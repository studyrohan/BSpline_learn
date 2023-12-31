#include "pch.h"
#include "CP2.h"

CP2::CP2()
{
	this->w = 1;
}

CP2::CP2(double x, double y)
{
	this->x =x;
	this->y =y;
	this->w = 1;
}

CP2& CP2::operator=(const CP2& P)
{
	this->x = P.x;
	this->y = P.y;
	return *this;
}

CP2& CP2::operator-=(const CP2& P)
{
	this->x -= P.x;
	this->y -= P.y;
	return *this;
}

CP2 CP2::operator-(const CP2& P)
{
	CP2 tem;
	tem.x = this->x -P.x;
	tem.y = this->y -P.y;
	return tem;
}

CP2 CP2::operator-(double num)
{
	CP2 tem;
	tem.x = this->x - num;
	tem.y = this->y - num;
	return tem;
}

CP2& CP2::operator+=(const CP2& P)
{
	this->x += P.x;
	this->y += P.y;
	return *this;
}

CP2 CP2::operator+(const CP2& P)
{
	CP2 tem;
	tem.x = this->x + P.x;
	tem.y = this->y + P.y;
	return tem;
}

CP2 CP2::operator+(double num)
{
	CP2 tem;
	tem.x = this->x + num;
	tem.y = this->y + num;
	return tem;
}

CP2 CP2::operator*(double num)
{
	CP2 tem;
	tem.x = this->x * num;
	tem.y = this->y * num;
	return tem;
}

CP2 CP2::operator/(double num)
{
	CP2 tem;
	tem.x = this->x / num;
	tem.y = this->y / num;
	return tem;
}

CP2& CP2::operator-=(double num)
{
	this->x -= num;
	this->y -= num;
	return *this;
}

CP2& CP2::operator+=(double num)
{
	this->x += num;
	this->y += num;
	return *this;
}
