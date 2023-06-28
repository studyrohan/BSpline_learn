#include "pch.h"
#include "CCube.h"
#define ROUND(x) (int(x+0.5))
CCube::CCube()
{

}

CCube::~CCube()
{

}

void CCube::ReadVertex()
{
	p[0].x = 0, p[0].y = 0; p[0].z = 0;
	p[1].x = 1, p[1].y = 0; p[1].z = 0;
	p[2].x = 1, p[2].y = 1; p[2].z = 0;
	p[3].x = 0, p[3].y = 1; p[3].z = 0;
	p[4].x = 0, p[4].y = 0; p[4].z = 1;
	p[5].x = 1, p[5].y = 0; p[5].z = 1;
	p[6].x = 1, p[6].y = 1; p[6].z = 1;
	p[7].x = 0, p[7].y = 1; p[7].z = 1;


}

void CCube::ReadFacet()
{
	F[0].index[0] = 4; F[0].index[1] = 5; F[0].index[2] = 6; F[0].index[3] = 7;
	F[1].index[0] = 0; F[1].index[1] = 3; F[1].index[2] = 2; F[1].index[3] = 1;
	F[2].index[0] = 0; F[2].index[1] = 4; F[2].index[2] = 7; F[2].index[3] = 3;
	F[3].index[0] = 1; F[3].index[1] = 2; F[3].index[2] = 6; F[3].index[3] = 5;
	F[4].index[0] = 2; F[4].index[1] = 3; F[4].index[2] = 7; F[4].index[3] = 6;
	F[5].index[0] = 0; F[5].index[1] = 1; F[5].index[2] = 5; F[5].index[3] = 4;
}

CP3* CCube::GetPtArrayName()
{
	return p;
}

void CCube::Draw(CDC* pDC)
{
	CP2 screenPoint, temp;
	for (int nFacet = 0;nFacet<6;nFacet++)
	{
		for (int nPoint = 0;nPoint<4;nPoint++)
		{
			screenPoint = projection.OrthogonalProjection(p[F[nFacet].index[nPoint]]);
			if (0 == nPoint)
			{
				pDC->MoveTo(ROUND(screenPoint.x), ROUND(screenPoint.y));
				temp = screenPoint;
			}
			else
			{
				pDC->LineTo(ROUND(screenPoint.x), ROUND(screenPoint.y));
			}
		}
	}
}
