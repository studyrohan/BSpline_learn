#pragma once
#include "CP2.h"
class CProjection
{
public:
	CProjection();
	virtual ~CProjection();
	void SetEye();//�����ӵ�
	CP3 GetEye();
	CP2 ObliqueProjection(CP3 worldPoint);//бͶӰ
	CP2 OrthogonalProjection(CP3 worldPoint);//����ͶӰ
	CP2 PerspectiveProjection(CP3 worldPoint);//͸��ͶӰ

private:
	CP3 eyePoint;//�ӵ�
	double R, d;//�Ծ����Ӿ�

};

