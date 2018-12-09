#ifndef CLINE_H
#define CLINE_H

#include "CFigure.h"

class CLine : public CFigure
{
private:
	Point fPoint;
	Point sPoint;
public:
	CLine(Point, Point, GfxInfo FigureGfxInfo);

	virtual void Draw(Output* pOut) ;
	 virtual bool SelectArea(int x,int y);
	 Point getPoint1(){
		 return fPoint;
	 }
	 Point getPoint2(){
		 return sPoint;
	 }


};
#endif