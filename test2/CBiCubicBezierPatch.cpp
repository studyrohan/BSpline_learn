#include "pch.h"
#include "CBiCubicBezierPatch.h"


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
	for (double u = 0;u<1.0;u+=dstep)
	{
		for (double v = 0;v<1.0;v+=dstep)
		{

		}
	}
}

void CBiCubicBezierPatch::DrawControlGrid(CDC* pDC)
{

}

void CBiCubicBezierPatch::LeftMulitiplyMatrix(double M[4][4], CP3 P[4][4])
{

}

void CBiCubicBezierPatch::RightMulitiplyMatrix(double M[4][4], CP3 P[4][4])
{

}

void CBiCubicBezierPatch::RightMulitiplyMatrix(CP3 P[4][4], double M[4][4])
{

}

void CBiCubicBezierPatch::TransposeMatrix(double M[4][4])
{

}
