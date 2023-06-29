#pragma once
#include "CP2.h"
#include "CProjection.h"
//三次贝塞尔曲面
//三次曲线4个控制点，曲面就是16控制点
class CBiCubicBezierPatch
{
public:
	CBiCubicBezierPatch();
	virtual ~CBiCubicBezierPatch();
	void ReadControlPoint(CP3 P[4][4]);
	void DrawCurvedPatch(CDC* pDC);//绘制三次贝塞尔曲面片
	void DrawControlGrid(CDC* pDC);//绘制控制网格
private:
	void LeftMulitiplyMatrix(double M[4][4], CP3 P[4][4]);
	void RightMulitiplyMatrix(double M[4][4], CP3 P[4][4]);
	void RightMulitiplyMatrix(CP3 P[4][4],double M[4][4]);
	void TransposeMatrix(double M[4][4]);
private:
	CP3 p[4][4];
	CProjection projection;

};

