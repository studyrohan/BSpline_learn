#include "pch.h"
#include "CCubicBezierCurve.h"

#define ROUND(x) (int(x+0.5))
CCubicBezierCurve::CCubicBezierCurve()
{

}

CCubicBezierCurve::~CCubicBezierCurve()
{

}

void CCubicBezierCurve::ReadPoint(CP2* p)
{
	for (int i = 0;i<4;i++)
	{
		this->p[i] = *p;
		p++;
	}
}

void CCubicBezierCurve::Draw(CDC* pDC)
{
	CPen pen(PS_SOLID, 1, RGB(0, 0, 255));
	CPen* pOldPen = pDC->SelectObject(&pen);
	CP2 p00 = p[0];
	CP2 p10 = p[1];
	CP2 p20 = p[2];
	CP2 p30 = p[3];
	pDC->MoveTo(CPoint{ROUND(p[0].x),ROUND(p[0].y)});
	for (double t = 0.0;t<1.0;t+=0.01)
	{
		//CP2 p01 = p00 * (1 - t) + p10 * t;
		//CP2 p11 = p10 * (1 - t) + p20 * t;
		//CP2 p21 = p20 * (1 - t) + p30 * t;

		//CP2 p02 = p01 * (1 - t) + p11 * t;
		//CP2 p12 = p11 * (1 - t) + p21 * t;

		//CP2 p03 = p02 * (1 - t) + p12 * t;

		//pDC->LineTo(CPoint{ ROUND(p03.x),ROUND(p03.y) });


		//直接使用博尔斯特基函数
		double Bern03 = (1 - t) * (1 - t) * (1 - t);
		double Bern12 = (1 - t) * (1 - t) * t;
		double Bern21 = (1 - t) * t * t;
		double Bern30 = t * t * t;
		CP2 pd = p[0]*Bern03+p[1]*Bern12+p[2]*Bern21+p[3]*Bern30;
		pDC->LineTo(CPoint{ ROUND(pd.x),ROUND(pd.y) });
	}
	pDC->SelectObject(pOldPen);
}

void CCubicBezierCurve::DrawControlPolygon(CDC* pDC)
{
	CPen pen(PS_SOLID, 1, RGB(0, 0, 255));
	CPen* pOldPen = pDC->SelectObject(&pen);
	CBrush brush(RGB(0, 0, 255));
	CBrush* oldBrush = pDC->SelectObject(&brush);
	for (int i = 0; i < 4; i++)
	{
		if (0 == i)
		{
			pDC->MoveTo(CPoint{ROUND( p[i].x),ROUND(p[i].y) });
			pDC->Ellipse(ROUND(p[i].x - 5), ROUND(p[i].y - 5), ROUND(p[i].x + 5), ROUND(p[i].y + 5));
		}
		else
		{
			pDC->LineTo(CPoint{ROUND( p[i].x),ROUND(p[i].y) });
			pDC->Ellipse(ROUND(p[i].x - 5), ROUND(p[i].y - 5), ROUND(p[i].x + 5), ROUND(p[i].y + 5));
		}
	}
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(oldBrush);

}
