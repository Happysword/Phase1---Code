#pragma once
#include "action.h"
#include "../ApplicationManager.h"
extern CFigure *copyFigPtr; //copied fig
//CFigure* getCopied();
class CopyAction : public Action
{
 	private:
	Point P1; //Point of selection
	
	
public:
	
	CopyAction(ApplicationManager *pApp);
	~CopyAction();
	virtual void ReadActionParameters();
	virtual void Execute() ;
	//friend  CFigure* getCopied();
 };
