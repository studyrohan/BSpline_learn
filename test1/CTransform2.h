#pragma once
#include "CP2.h"
class CTransform2
{
public:
	CTransform2();
	virtual ~CTransform2();
	void SetMatrix(CP2* p, int ptNumber);//��ά��������
	void Identify();
	void Translate(double tx,double ty);
	void Scale(double sx, double sy);
	void Scale(double sx, double sy, CP2 p);//��������һ��ı����任
	void Rotate(double beta);
	void Rotate(double beta, CP2 p);
	void ReflectOrg();//����ԭ��ķ���任
	void ReflectX();
	void ReflectY();
	void Shear(double b,double c);//���б任
	void MultiplyMatrix();//�������
private:
	double M[3][3];//�任����
	CP2* p;//��������
	int ptNumber;//�������

};

