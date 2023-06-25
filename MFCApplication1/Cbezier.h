#pragma once
class Cbezier
{
public:
	Cbezier();
	virtual ~Cbezier();
	void ReadPoint(CPoint* pnt, int n,int order);
	void Draw(CDC* pDC);// draw bezier curve
	void DrawControlPolygon(CDC* pDC);
private:
	double Cn1(const int& n, const int& l);
	int Factorial(int n);
public:
	CPoint* _pntList;
	int _n;
	int _order;
};

