#pragma once
class CP2
{
public:
	CP2();
	CP2(double x, double y);
	~CP2() = default;
	CP2& operator=(const CP2& P);
	CP2 operator+(const CP2& P);
	CP2 operator-(const CP2& P);
	CP2 operator-(double num);
	CP2 operator+(double num);
	CP2 operator*(double num);
	CP2 operator/(double num);
	CP2& operator+=(const CP2& P);
	CP2& operator-=(const CP2& P);
	CP2& operator+=(double num);
	CP2& operator-=(double num);
public:
	double x, y, w;
};

class CP3 :public CP2
{
public:
	CP3(double x, double y, double z);
	CP3();
	double z;
};



