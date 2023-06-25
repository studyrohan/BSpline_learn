#pragma once
#include "CP2.h"
class CBrick
{
public:
	CBrick();
	virtual ~CBrick();
	void ReadPoint();
	void Draw(CDC* pDC);
public:
	CP2 P[4];
};

