#pragma once
#include "CP2.h"
class CCubicBezierCurve
{
public:
	CCubicBezierCurve();
	virtual ~CCubicBezierCurve();
	void ReadPoint(CP2* p);
	void Draw(CDC* pDc);
	void DrawControlPolygon(CDC* pDC);
public:
	CP2 p[4];
};

