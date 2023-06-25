#include "pch.h"
#include "Cbezier.h"

Cbezier::Cbezier()
{
	_pntList = nullptr;
}

Cbezier::~Cbezier()
{
	if (_pntList != nullptr)
	{
		delete[] _pntList;
	}
}

void Cbezier::ReadPoint(CPoint* pnt, int n,int order)
{
	if (n<1)
	{
		return;
	}
	if (_pntList != nullptr)
	{
		delete[] _pntList;
	}
	_pntList = new CPoint[n];
	for (int i = 0;i<n;i++)
	{
		_pntList[i] = *pnt;
		pnt++;
	}
	_n = n;
	_order = order;

}
#define ROUND(x) (int(x+0.5))
void Cbezier::Draw(CDC* pDC)
{
	CPen pen(PS_SOLID, 1, RGB(255, 0, 0));
	CPen* pOldPen = pDC->SelectObject(&pen);
	pDC->MoveTo(ROUND(_pntList[0].x), ROUND(_pntList[0].y));
	double step = 0.01;
	for (double t = 0.0;t<=1.0;t+=step)
	{
		double x = 0, y = 0;
		for (int i = 0;i<_order+1;i++)
		{
			x += Cn1(_order, i) * pow(t, i) * pow(1 - t, _order - i)*_pntList[i].x;
			y += Cn1(_order, i) * pow(t, i) * pow(1 - t, _order - i)*_pntList[i].y;
		}
		pDC->LineTo(ROUND(x), ROUND(y));
	}
	pDC->SelectObject(pOldPen);
}

void Cbezier::DrawControlPolygon(CDC* pDC)
{
	CPen pen(PS_SOLID, 1, RGB(0, 0, 255));
	CPen* pOldPen = pDC->SelectObject(&pen);
	CBrush brush(RGB(0, 0, 255));
	CBrush* oldBrush = pDC->SelectObject(&brush);
	for (int i = 0;i<_order+1;i++)
	{
		if (0 == i)
		{
			pDC->MoveTo(_pntList[i]);
			pDC->Ellipse(ROUND(_pntList[i].x - 5), ROUND(_pntList[i].y - 5), ROUND(_pntList[i].x + 5), ROUND(_pntList[i].y + 5));
		}
		else
		{
			pDC->LineTo(_pntList[i]);
			pDC->Ellipse(ROUND(_pntList[i].x - 5), ROUND(_pntList[i].y - 5), ROUND(_pntList[i].x + 5), ROUND(_pntList[i].y + 5));
		}
	}
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(oldBrush);
}

double Cbezier::Cn1(const int& n, const int& l)
{
	return double(Factorial(n) / (Factorial(l) * Factorial(n - l)));
}

int Cbezier::Factorial(int n)
{
	if (n<0)
	{
		return -1;
	}
	if (n ==0||n==1 )
	{
		return 1;
	}
	else
	{
		return n * Factorial(n - 1);
	}
}
