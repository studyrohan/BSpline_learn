#pragma once
class Cbezier
{
public:
	Cbezier();
	virtual ~Cbezier();
	void ReadPoint(CPoint* pnt, int n);
	void Draw(CDC* pDC);// draw bezier curve
	void DrawControlPolygon(CDC* pDC);
private:
	/*
	* function deCasteljau(i,j)
	begin
	if i = 0 then
	  return P0,j
	else
	  return (1-u)* deCasteljau(i-1,j) + u* deCasteljau(i-1,j+1)
	end q
	*/
	void DeCasteljau(double t);
private:
	CPoint _p[5];
	CPoint ctrl[5][5];
	int _n;
};

