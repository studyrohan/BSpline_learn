#pragma once
#include "CP2.h"
#include "CProjection.h"
#include "CFacet.h"
class CCube
{
public:
	CCube();
	virtual ~CCube();
	void ReadVertex();
	void ReadFacet();
	CP3* GetPtArrayName();
	void Draw(CDC* pDC);
private:
	CP3 p[8];//点表
	//面表
	CFacet F[6];
	CProjection projection;
};

