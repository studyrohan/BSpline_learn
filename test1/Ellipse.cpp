#include "pch.h"
#include "Ellipse.h"

CEllipse::CEllipse()
{

}

CEllipse::~CEllipse()
{

}

void CEllipse::ReadPoint()
{
	double m = 0.5523;
	p[0].x = 1, p[0].y = 0;
	p[1].x = 1, p[1].y = m;
	p[2].x = m, p[2].y = 1;
	p[3].x = 0, p[3].y = 1;
	p[4].x = -m, p[4].y = 1;
	p[5].x = -1, p[5].y = m;
	p[6].x = -1, p[6].y =0;
	p[7].x = -1, p[7].y = -m;
	p[8].x = -m, p[8].y = -1;
	p[9].x = 0, p[9].y = -1;
	p[10].x = m, p[10].y = -1;
	p[11].x = 1, p[11].y = -m;
	
}

void CEllipse::Draw(CDC* pDC)
{
	CP2 ctrolPnt[4];
	//first
	for (int i = 0;i<4;i++)
	{
		ctrolPnt[i] = p[i];
	}
	bezier[0].ReadPoint(ctrolPnt);
	for (int i = 3; i < 7; i++)
	{
		ctrolPnt[i-3] = p[i];
	}
	bezier[1].ReadPoint(ctrolPnt);
	for (int i = 6; i < 10; i++)
	{
		ctrolPnt[i - 6] = p[i];
	}
	bezier[2].ReadPoint(ctrolPnt);
	for (int i = 9; i < 13; i++)
	{
		ctrolPnt[i - 9] = p[i%12];
	}
	bezier[3].ReadPoint(ctrolPnt);
	for (int i = 0;i<4;i++)
	{
		bezier[i].Draw(pDC);
		bezier[i].DrawControlPolygon(pDC);
	}
}
