#pragma once
#include "CP2.h"
class CTransform3
{
public:
	CTransform3();
	virtual ~CTransform3();
	void SetMatrix(CP3* p, int ptNumber);//3ά��������
	void Identify();
	void Translate(double tx, double ty,double tz);
	void Scale(double sx, double sy,double sz);
	void Scale(double sx, double sy,double sz, CP3 p);//��������һ��ı����任
	void Scale(double x);
	void Scale(double x, CP3 p);
	void RotateX(double beta);
	void RotateY(double beta);
	void RotateZ(double beta);
	void RotateX(double beta, CP3 p);
	void RotateY(double beta, CP3 p);
	void RotateZ(double beta, CP3 p);
	void ReflectOrg();//����ԭ��ķ���任
	void ReflectX();
	void ReflectY();
	void ReflectZ();
	void Shear(double b, double c);//���б任
	void MultiplyMatrix();//�������
private:
	double M[4][4];
	CP3* p;//��ά����������
	int ptNumber;

};

