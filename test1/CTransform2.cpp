#include "pch.h"
#include "CTransform2.h"
#include <cstring>

const double Pi = 3.1415926;
CTransform2::CTransform2()
{
	//this->M = { 0 };
	this->p = nullptr;
	this->ptNumber = 0;
}

CTransform2::~CTransform2()
{

}

void CTransform2::SetMatrix(CP2* p, int ptNumber)
{
	this->p = p;
	this->ptNumber = ptNumber;
}

void CTransform2::Identify()
{
	std::memset(this->M, 0, sizeof(M));
	this->M[0][0] = this->M[1][1] = this->M[2][2] = 1;
}

void CTransform2::Translate(double tx, double ty)
{
	Identify();
	M[0][2] = tx;
	M[1][2] = ty;
	MultiplyMatrix();
}

void CTransform2::Scale(double sx, double sy)
{
	Identify();
	M[0][0] = sx;
	M[1][1] = sy;
	MultiplyMatrix();
}

void CTransform2::Scale(double sx, double sy, CP2 p)
{
	Translate(-p.x, -p.y);
	Scale(sx, sy);
	Translate(p.x, p.y);
	MultiplyMatrix();
}

void CTransform2::Rotate(double beta)
{
	Identify();
	M[0][0] = cos(beta * Pi / 180);
	M[0][1] = -sin(beta * Pi / 180);
	M[1][0] = sin(beta * Pi / 180);
	M[1][1] = cos(beta * Pi / 180);
	MultiplyMatrix();
}

void CTransform2::Rotate(double beta, CP2 p)
{
	Translate(-p.x, -p.y);
	Rotate(beta);
	Translate(p.x, p.y);
	MultiplyMatrix();
}

void CTransform2::ReflectOrg()
{
	Identify();
	M[0][0] = -1;
	M[1][1] = -1;
	MultiplyMatrix();

}

void CTransform2::ReflectX()
{
	Identify();
	M[1][1] = -1;
	MultiplyMatrix();
}

void CTransform2::ReflectY()
{
	Identify();
	M[0][0] = -1;
	MultiplyMatrix();
}

void CTransform2::Shear(double b, double c)
{

}

void CTransform2::MultiplyMatrix()
{
	CP2* ptem = new CP2[this->ptNumber];
	for (int i = 0;i<this->ptNumber;i++)
	{
		ptem[i] = this->p[i];
	}
	for (int i = 0; i < this->ptNumber; i++)
	{
		p[i].x = M[0][0] * ptem[i].x + M[0][1] * ptem[i].y + M[0][2] * ptem[i].w;
		p[i].y = M[1][0] * ptem[i].x + M[1][1] * ptem[i].y + M[1][2] * ptem[i].w;
		p[i].w = M[2][0] * ptem[i].x + M[2][1] * ptem[i].y + M[2][2] * ptem[i].w;
	}
	delete[]ptem;
	
}
