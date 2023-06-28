#pragma once
#include "CCubicBezierCurve.h"

class CEllipse
{
public:
	CEllipse();
	virtual ~CEllipse();
	void ReadPoint();
	void Draw(CDC* pDC);
public:
	CP2 p[12];
private:
	CCubicBezierCurve bezier[4];
};

