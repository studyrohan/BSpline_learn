#pragma once
#include "CP2.h"
class CTransform3
{
public:
	CTransform3();
	virtual ~CTransform3();
	void SetMatrix(CP3* p, int ptNumber);//3维顶点数组
	void Identify();
	void Translate(double tx, double ty,double tz);
	void Scale(double sx, double sy,double sz);
	void Scale(double sx, double sy,double sz, CP3 p);//基于任意一点的比例变换
	void Scale(double x);
	void Scale(double x, CP3 p);
	void RotateX(double beta);
	void RotateY(double beta);
	void RotateZ(double beta);
	void RotateX(double beta, CP3 p);
	void RotateY(double beta, CP3 p);
	void RotateZ(double beta, CP3 p);
	void ReflectOrg();//关于原点的反射变换
	void ReflectX();
	void ReflectY();
	void ReflectZ();
	void Shear(double b, double c);//错切变换
	void MultiplyMatrix();//矩阵相乘
private:
	double M[4][4];
	CP3* p;//三维顶点数组名
	int ptNumber;

};

