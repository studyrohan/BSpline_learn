#pragma once
#include "CP2.h"
class CTransform2
{
public:
	CTransform2();
	virtual ~CTransform2();
	void SetMatrix(CP2* p, int ptNumber);//二维顶点数组
	void Identify();
	void Translate(double tx,double ty);
	void Scale(double sx, double sy);
	void Scale(double sx, double sy, CP2 p);//基于任意一点的比例变换
	void Rotate(double beta);
	void Rotate(double beta, CP2 p);
	void ReflectOrg();//关于原点的反射变换
	void ReflectX();
	void ReflectY();
	void Shear(double b,double c);//错切变换
	void MultiplyMatrix();//矩阵相乘
private:
	double M[3][3];//变换矩阵
	CP2* p;//顶点数组
	int ptNumber;//顶点个数

};

