#include "pch.h"
#include "CBiCubicBezierPatch.h"

#define ROUND(x) (int(x+0.5))
CBiCubicBezierPatch::CBiCubicBezierPatch()
{

}

CBiCubicBezierPatch::~CBiCubicBezierPatch()
{

}

void CBiCubicBezierPatch::ReadControlPoint(CP3 P[4][4])
{
	for (int i = 0;i<4;i++)
	{
		for (int j = 0;i<4;j++)
		{
			this->p[i][j] = p[i][j];
		}
	}
}

void CBiCubicBezierPatch::DrawCurvedPatch(CDC* pDC)
{
	//三次贝塞尔曲线的表达式
	//b03 = (1-u)^3 = -u^3+3u^2-3u+1
	//b12 = (1-u）^2 *u = 3u^3-6u^2+3u
	//b21 = (1-u） *u^2 = -3u^3+3u^2
	//b30 = u^3 
	// -1 3 -3 1
	// 3 -6 3 0
	// -3 3 0 0
	// 3  0 0 0
	//1.设置系数矩阵
	double M[4][4];
	M[0][0] = -1, M[0][1] = 3, M[0][2] = -3, M[0][3] = 1;
	M[1][0] = 3, M[1][1] = -6, M[1][2] = 3, M[1][3] = 0;
	M[2][0] = -3, M[2][1] = 3, M[2][2] = 0, M[2][3] = 0;
	M[3][0] = 3, M[3][1] = 0, M[3][2] = 0, M[3][3] = 0;

	//2,读入控制点
	CP3 p3[4][4];
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; i < 4; j++)
		{
			p3[i][j] = this->p[i][j];
		}
	}
	LeftMulitiplyMatrix(M, p3);
	TransposeMatrix(M);
	RightMulitiplyMatrix(p3, M);
	double dstep = 0.1;
	double u0, u1, u2, u3, v0, v1, v2, v3;//u v参数的幂
	for (double u = 0; u < 1.0; u += dstep)
	{
		for (double v = 0; v < 1.0; v += dstep)
		{
			u3 = u * u * u, u2 = u * u, u1 = u, u0 = 1;
			v3 = v * v * v; v2 = v * v; v1 = v; v0 = 1;
			CP3 pt = (p3[0][0] * u3 + p3[1][0] * u2 + p3[2][0] * u1 + p3[3][0] * u1) * v3
				+ (p3[0][1] * u3 + p3[1][1] * u2 + p3[2][1] * u1 + p3[3][1] * u1) * v2
				+ (p3[0][2] * u3 + p3[1][2] * u2 + p3[2][2] * u1 + p3[3][2] * u1) * v1
				+ (p3[0][3] * u3 + p3[1][3] * u2 + p3[2][3] * u1 + p3[3][3] * u1) * v0;
			CP2 point2 = projection.ObliqueProjection(pt);
			if (v == 0)
			{
				pDC->MoveTo(ROUND(point2.x), ROUND(point2.y));
			}
			else
			{
				pDC->LineTo(ROUND(point2.x), ROUND(point2.y));
			}
		}
	}
	for (double v = 0; v < 1.0; v += dstep)
	{
		for (double u = 0; u < 1.0; u += dstep)
		{
			u3 = u * u * u, u2 = u * u, u1 = u, u0 = 1;
			v3 = v * v * v; v2 = v * v; v2 = v; v0 = 1;
			CP3 pt = (p3[0][0] * u3 + p3[1][0] * u2 + p3[2][0] * u1 + p3[3][0] * u1) * v3
				+ (p3[0][1] * u3 + p3[1][1] * u2 + p3[2][1] * u1 + p3[3][1] * u1) * v2
				+ (p3[0][2] * u3 + p3[1][2] * u2 + p3[2][2] * u1 + p3[3][2] * u1) * v1
				+ (p3[0][3] * u3 + p3[1][3] * u2 + p3[2][3] * u1 + p3[3][3] * u1) * v0;
			CP2 point2 = projection.ObliqueProjection(pt);
			if (v == 0)
			{
				pDC->MoveTo(ROUND(point2.x), ROUND(point2.y));
			}
			else
			{
				pDC->LineTo(ROUND(point2.x), ROUND(point2.y));
			}
		}
	}
}

void CBiCubicBezierPatch::DrawControlGrid(CDC* pDC)
{

}

void CBiCubicBezierPatch::LeftMulitiplyMatrix(double M[4][4], CP3 P[4][4])
{
	CP3 pTemp[4][4];
	for (int i =0;i<4;i++)
	{
		for (int j =0;j<4;j++)
		{
			pTemp[i][j] = p[0][j] * M[i][0] + p[1][j] * M[i][1] + p[2][j] * M[i][2] + p[3][j] * M[i][3];
		}
	}
	for (int i=0;i<4;i++)
	{
		for (int j =0;j<4;j++)
		{
			P[j][j] = pTemp[i][j];
		}
	}
}

void CBiCubicBezierPatch::RightMulitiplyMatrix(double M[4][4], CP3 P[4][4])
{
	CP3 pTemp[4][4];
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			pTemp[i][j] = p[i][0] * M[0][j] + p[i][1] * M[1][j] + p[i][2] * M[2][j] + p[i][3] * M[3][j];
		}
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			P[j][j] = pTemp[i][j];
		}
	}
}

void CBiCubicBezierPatch::RightMulitiplyMatrix(CP3 P[4][4], double M[4][4])
{
	CP3 pTemp[4][4];
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			pTemp[i][j] = p[i][0] * M[0][j] + p[i][1] * M[1][j] + p[i][2] * M[2][j] + p[i][3] * M[3][j];
		}
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			P[j][j] = pTemp[i][j];
		}
	}
}

void CBiCubicBezierPatch::TransposeMatrix(double M[4][4])
{
	double pTemp[4][4];
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			pTemp[j][i] = M[i][j];
		}
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			M[i][j] =pTemp[i][j];
		}
	}
	
}
