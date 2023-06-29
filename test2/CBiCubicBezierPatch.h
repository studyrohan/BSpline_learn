#pragma once
#include "CP2.h"
#include "CProjection.h"
//���α���������
//��������4�����Ƶ㣬�������16���Ƶ�
class CBiCubicBezierPatch
{
public:
	CBiCubicBezierPatch();
	virtual ~CBiCubicBezierPatch();
	void ReadControlPoint(CP3 P[4][4]);
	void DrawCurvedPatch(CDC* pDC);//�������α���������Ƭ
	void DrawControlGrid(CDC* pDC);//���ƿ�������
private:
	void LeftMulitiplyMatrix(double M[4][4], CP3 P[4][4]);
	void RightMulitiplyMatrix(double M[4][4], CP3 P[4][4]);
	void RightMulitiplyMatrix(CP3 P[4][4],double M[4][4]);
	void TransposeMatrix(double M[4][4]);
private:
	CP3 p[4][4];
	CProjection projection;

};

