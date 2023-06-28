#include "pch.h"
#include "CTransform3.h"


constexpr double Pi = 3.1415926;
CTransform3::CTransform3()
{
	//this->M = { 0 };
	this->p = nullptr;
	this->ptNumber = 0;

}

CTransform3::~CTransform3()
{

}

void CTransform3::SetMatrix(CP3* p, int ptNumber)
{
	this->p = p;
	this->ptNumber = ptNumber;
}

void CTransform3::Identify()
{
	memset(this->M, 0,sizeof(M));
	this->M[0][0] = this->M[1][1] = this->M[2][2] = this->M[3][3] = 1;
}

void CTransform3::Translate(double tx, double ty, double tz)
{
	Identify();
	M[0][3] = tx;
	M[1][3] = ty;
	M[2][3] = tz;
	MultiplyMatrix();
}

void CTransform3::Scale(double sx, double sy, double sz)
{
	Identify();
	M[0][0] = sx;
	M[1][1] = sy;
	M[2][2] = sz;
	MultiplyMatrix();
}

void CTransform3::Scale(double sx, double sy, double sz, CP3 p)
{
	Translate(-p.x, -p.y,-p.z);
	Scale(sx, sy,sz);
	Translate(p.x, p.y,p.z);
	MultiplyMatrix();
}

void CTransform3::Scale(double x)
{
	Identify();
	M[0][0] = x;
	M[1][1] = x;
	M[2][2] = x;
	MultiplyMatrix();
}

void CTransform3::Scale(double x, CP3 p)
{
	Translate(-p.x, -p.y, -p.z);
	Scale(x, x, x);
	Translate(p.x, p.y, p.z);
	MultiplyMatrix();

}

void CTransform3::RotateX(double beta)
{
	Identify();
	M[1][1] = cos(beta * Pi / 180);
	M[1][2] = -sin(beta * Pi / 180);
	M[2][1] = sin(beta * Pi / 180);
	M[2][2] = cos(beta * Pi / 180);
	MultiplyMatrix();

}

void CTransform3::RotateX(double beta, CP3 p)
{
	Translate(-p.x, -p.y,-p.z);
	RotateX(beta);
	Translate(p.x, p.y,p.z);
	MultiplyMatrix();
}

void CTransform3::RotateY(double beta)
{
	Identify();
	M[0][0] = cos(beta * Pi / 180);
	M[0][2] = -sin(beta * Pi / 180);
	M[2][0] = sin(beta * Pi / 180);
	M[2][2] = cos(beta * Pi / 180);
	MultiplyMatrix();
}

void CTransform3::RotateY(double beta, CP3 p)
{
	Translate(-p.x, -p.y, -p.z);
	RotateY(beta);
	Translate(p.x, p.y, p.z);
	MultiplyMatrix();
}

void CTransform3::RotateZ(double beta)
{
	Identify();
	M[0][0] = cos(beta * Pi / 180);
	M[0][1] = -sin(beta * Pi / 180);
	M[1][0] = sin(beta * Pi / 180);
	M[1][1] = cos(beta * Pi / 180);
	MultiplyMatrix();
}

void CTransform3::RotateZ(double beta, CP3 p)
{
	Translate(-p.x, -p.y, -p.z);
	RotateZ(beta);
	Translate(p.x, p.y, p.z);
	MultiplyMatrix();
}

void CTransform3::ReflectOrg()
{

}

void CTransform3::ReflectX()
{

}

void CTransform3::ReflectY()
{

}

void CTransform3::ReflectZ()
{

}

void CTransform3::Shear(double b, double c)
{

}

void CTransform3::MultiplyMatrix()
{
	CP3* ptem = new CP3[this->ptNumber];
	for (int i = 0; i < this->ptNumber; i++)
	{
		ptem[i] = this->p[i];
	}
	for (int i = 0; i < this->ptNumber; i++)
	{
		p[i].x = M[0][0] * ptem[i].x + M[0][1] * ptem[i].y + M[0][2] * ptem[i].z + M[0][3] * ptem[i].w;
		p[i].y = M[1][0] * ptem[i].x + M[1][1] * ptem[i].y + M[1][2] * ptem[i].z + M[1][3] * ptem[i].w;
		p[i].z = M[2][0] * ptem[i].x + M[2][1] * ptem[i].y + M[2][2] * ptem[i].z + M[2][3] * ptem[i].w;
		p[i].w = M[3][0] * ptem[i].x + M[3][1] * ptem[i].y + M[3][2] * ptem[i].z + M[3][3] * ptem[i].w;
	}
	delete[]ptem;
}
