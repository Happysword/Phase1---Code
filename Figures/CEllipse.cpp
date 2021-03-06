#include "CEllipse.h"
#include"../ApplicationManager.h"
CEllipse::CEllipse(Point P1, GfxInfo FigGfxInfo):CFigure(FigGfxInfo)
{
	center = P1;
	figtype=2;

	if (FigGfxInfo.FillClr == RED)					//figcolor (0:red,1:blue,2:green,3:white,4:black)
	{
		figcolor = 0;
	}
	else if (FigGfxInfo.FillClr == BLUE)
	{
		figcolor = 1;
	}
	else if (FigGfxInfo.FillClr == GREEN)
	{
		figcolor = 2;
	}
	else if (FigGfxInfo.FillClr == WHITE)
	{
		figcolor = 3;
	}
	else if (FigGfxInfo.FillClr == BLACK)
	{
		figcolor = 4;
	}
}

void CEllipse::Draw(Output * pOut) 
{
	pOut->Drawelipse(center, FigGfxInfo, Selected);
}
bool CEllipse:: SelectArea(int x,int y)
{
	double f =(x-center.x)*(x-(double)center.x)/(100*100)+(y-center.y)*((double)y-center.y)/(50*50);
	if (f<=1) return true;
	return false;

}

void CEllipse:: PrintInfo(Output* pOut)
{
	string p="Ellipse ID: "+to_string(5000+ID);

	p+=" Center: "+to_string(center.x)+' '+to_string(center.y);
	pOut->PrintMessage(p);


}
void CEllipse :: save (ofstream &OutFile, int n) {
	ID = n;
	OutFile<<"Elipse"<<"       ";
	OutFile<<ID<<"        "<<center.x<<"      "<<center.y<<"     ";
	if (FigGfxInfo.isFilled){
		if (FigGfxInfo.FillClr == BLACK) {
		OutFile<<"BLACK"<<"   ";
		}
		else if (FigGfxInfo.FillClr == RED) {
		OutFile<<"RED"<<"   ";
	}
		else if (FigGfxInfo.FillClr == BLUE) {
		OutFile<<"BLUE"<<"   ";
	}
		else if (FigGfxInfo.FillClr == GREEN) {
		OutFile<<"GREEN"<<"   ";
	}
		else {
		OutFile<<"WHITE"<<"   ";
		}
}
	else {
	OutFile<<"NON_FILL"<<"      ";
	}
	if (FigGfxInfo.DrawClr == BLACK) {
		OutFile<<"BLACK"<<"   ";
		}
	else if (FigGfxInfo.DrawClr == RED) {
		OutFile<<"RED"<<"   ";
	}
	else if (FigGfxInfo.DrawClr == BLUE) {
		OutFile<<"BLUE"<<"   ";
	}
	else if (FigGfxInfo.DrawClr== GREEN) {
		OutFile<<"GREEN"<<"   ";
	}
		else {
		OutFile<<"WHITE"<<"   ";
		}
}
void CEllipse:: load (ifstream &Infile) {
Infile>>ID; 
Infile>>center.x;
Infile>>center.y;
string y;
string fil;
Infile>>y;
string  Clr;
Infile>>Clr;
if (Clr=="BLACK") {
	FigGfxInfo.DrawClr = BLACK;
}
else if (Clr=="RED") {
	FigGfxInfo.DrawClr = RED;
}
else if (Clr=="BLUE") {
	FigGfxInfo.DrawClr = BLUE;
}
else if (Clr=="GREEN") {
	FigGfxInfo.DrawClr = GREEN;
}
else   {
	FigGfxInfo.DrawClr = WHITE;
}
if (y== "NON_FILL") {
	FigGfxInfo.isFilled = false;
}
else {
	FigGfxInfo.isFilled = true;
	fil = y;
	if (fil=="BLACK") {
		FigGfxInfo.FillClr= BLACK;
}
else if (fil=="RED") {
	FigGfxInfo.FillClr = RED;
}
else if (fil=="BLUE") {
	FigGfxInfo.FillClr = BLUE;
}
else if (fil=="GREEN") {
	FigGfxInfo.FillClr = GREEN;
}
else   {
	FigGfxInfo.FillClr = WHITE;
}
}

}