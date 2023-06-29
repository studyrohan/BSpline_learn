#include "pch.h"
#include "CP2.h"
#include "pch.h"
#include "CP2.h"

CP2::CP2()
{
	this->w = 1;
}

CP2::CP2(double x, double y)
{
	this->x = x;
	this->y = y;
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
	tem.x = this->x - P.x;
	tem.y = this->y - P.y;
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

CP3::CP3(double x, double y, double z)
	:CP2(x,y)
{
	this->z = z;
}

CP3::CP3()
	:CP2()
{

}

CP3 CP3::operator-(const CP3& P)
{
	CP3 tem;
	tem.x = this->x - P.x;
	tem.y = this->y - P.y;
	tem.z = this->z - P.z;
	return tem;
}

CP3 CP3::operator-(double num)
{
	CP3 tem;
	tem.x = this->x - num;
	tem.y = this->y - num;
	tem.z = this->z - num;
	return tem;
}

CP3 CP3::operator+(const CP3& P)
{
	CP3 tem;
	tem.x = this->x + P.x;
	tem.y = this->y + P.y;
	tem.z = this->z + P.z;
	return tem;
}

CP3 CP3::operator+(double num)
{
	CP3 tem;
	tem.x = this->x + num;
	tem.y = this->y + num;
	tem.z = this->z + num;
	return tem;

}

CP3 CP3::operator*(double num)
{
	CP3 tem;
	tem.x = this->x *num;
	tem.y = this->y *num;
	tem.z = this->z *num;
	return tem;
}

CP3 CP3::operator/(double num)
{
	CP3 tem;
	tem.x = this->x / num;
	tem.y = this->y / num;
	tem.z = this->z / num;
	return tem;
}

CP3& CP3::operator-=(double num)
{
	this->x -= num;
	this->y -= num;
	this->z -= num;
	return *this;
}

CP3& CP3::operator+=(double num)
{
	this->x += num;
	this->y += num;
	this->z += num;
	return *this;
}

CP3& CP3::operator-=(const CP3& P)
{
	this->x -= P.x;
	this->y -= P.y;
	this->z -= P.z;
	return *this;

}

CP3& CP3::operator+=(const CP3& P)
{
	this->x += P.x;
	this->y += P.y;
	this->z += P.z;
	return *this;
}

CP3& CP3::operator=(const CP3& P)
{
	this->x = P.x;
	this->y = P.y;
	this->z = P.z;
	return *this;
}
