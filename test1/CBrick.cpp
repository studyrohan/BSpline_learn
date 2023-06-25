#include "pch.h"
#include "CBrick.h"
#define ROUND(x) (int(x+0.5))
CBrick::CBrick()
{

}

CBrick::~CBrick()
{

}

void CBrick::ReadPoint()
{
	this->P[0] = CP2 (0,0)*100;
	this->P[1] = CP2 (1,0) * 100;
	this->P[2] = CP2 (1,0.5) * 100;
	this->P[3] = CP2 (0,0.5) * 100;
}

void CBrick::Draw(CDC* pDC)
{
	CPen pen(PS_SOLID, 2, RGB(255, 0, 0));
	CPen* pOldPen = pDC->SelectObject(&pen);
	pDC->MoveTo(ROUND(P[0].x), ROUND(P[0].y));
	pDC->LineTo(ROUND(P[1].x), ROUND(P[1].y));
	pDC->LineTo(ROUND(P[2].x), ROUND(P[2].y));
	pDC->LineTo(ROUND(P[3].x), ROUND(P[3].y));
	pDC->LineTo(ROUND(P[0].x), ROUND(P[0].y));
	pDC->SelectObject(pOldPen);
}
