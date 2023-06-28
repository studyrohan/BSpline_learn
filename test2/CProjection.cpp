#include "pch.h"
#include "CProjection.h"

CProjection::CProjection()
{
	R = 1200;
	d = 800;
}

CProjection::~CProjection()
{

}

void CProjection::SetEye()
{
	eyePoint = { 0,0,R };
}

CP3 CProjection::GetEye()
{
	return eyePoint;
}

CP2 CProjection::ObliqueProjection(CP3 worldPoint)
{
	CP2 p;
	p.x = worldPoint.x - 0.3536 * worldPoint.z;
	p.y = worldPoint.y - 0.3536 * worldPoint.z;
	return p;
}

CP2 CProjection::OrthogonalProjection(CP3 worldPoint)
{
	CP2 p;
	p.x = worldPoint.x ;
	p.y = worldPoint.y ;
	return p;
}

CP2 CProjection::PerspectiveProjection(CP3 worldPoint)
{
	CP3 viewPoint(0,0,0);//观察坐标系三维点
	viewPoint.x = worldPoint.x;
	viewPoint.y = worldPoint.y;
	viewPoint.z = R - worldPoint.z;
	CP2 screenPoint;
	screenPoint.x = d * viewPoint.x / viewPoint.z;
	screenPoint.y = d * viewPoint.y / viewPoint.z;
	return screenPoint;

}
