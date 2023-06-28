#include "pch.h"
#include "Cbezier.h"#include "pch.h"
#include "Cbezier.h"
#include "pch.h"
#include "Cbezier.h"

Cbezier::Cbezier()
{
}

Cbezier::~Cbezier()
{
}


void Cbezier::ReadPoint(CPoint* pnt, int n)
{
	this->_n = n;
	for (int i = 0; i <= n; i++)
	{
		this->_p[i] = *pnt;
		pnt++;
	}
}

#define ROUND(x) (int(x+0.5))
void Cbezier::Draw(CDC* pDC)
{
	CPen pen(PS_SOLID, 1, RGB(255, 0, 0));
	CPen* pOldPen = pDC->SelectObject(&pen);
	pDC->MoveTo(ROUND(_p[0].x), ROUND(_p[0].y));
	double step = 0.01;
	for (double t = 0.0; t <= 1.0; t += step)
	{
		double x = 0, y = 0;
		DeCasteljau(t);
		pDC->LineTo(this->ctrl[0][_n]);
	}
	pDC->SelectObject(pOldPen);
}

void Cbezier::DrawControlPolygon(CDC* pDC)
{
	CPen pen(PS_SOLID, 1, RGB(0, 0, 255));
	CPen* pOldPen = pDC->SelectObject(&pen);
	CBrush brush(RGB(0, 0, 255));
	CBrush* oldBrush = pDC->SelectObject(&brush);
	for (int i = 0; i < _n + 1; i++)
	{
		if (0 == i)
		{
			pDC->MoveTo(_p[i]);
			pDC->Ellipse(ROUND(_p[i].x - 5), ROUND(_p[i].y - 5), ROUND(_p[i].x + 5), ROUND(_p[i].y + 5));
		}
		else
		{
			pDC->LineTo(_p[i]);
			pDC->Ellipse(ROUND(_p[i].x - 5), ROUND(_p[i].y - 5), ROUND(_p[i].x + 5), ROUND(_p[i].y + 5));
		}
	}
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(oldBrush);
}

void Cbezier::DeCasteljau(double t)
{
	for (int i = 0; i <= this->_n; i++)
	{
		this->ctrl[i][0] = this->_p[i];
	}
	for (int r = 1; r <= this->_n; r++)
	{
		for (int i = 0; i <= this->_n - r; i++)
		{
			this->ctrl[i][r].x = (1 - t) * (this->ctrl[i][r - 1].x) + t * (this->ctrl[i + 1][r - 1].x);
			this->ctrl[i][r].y = (1 - t) * (this->ctrl[i][r - 1].y) + t * (this->ctrl[i + 1][r - 1].y);
		}
	}
}

