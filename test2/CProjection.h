#pragma once
#include "CP2.h"
class CProjection
{
public:
	CProjection();
	virtual ~CProjection();
	void SetEye();//设置视点
	CP3 GetEye();
	CP2 ObliqueProjection(CP3 worldPoint);//斜投影
	CP2 OrthogonalProjection(CP3 worldPoint);//正交投影
	CP2 PerspectiveProjection(CP3 worldPoint);//透视投影

private:
	CP3 eyePoint;//视点
	double R, d;//试径和视距

};

