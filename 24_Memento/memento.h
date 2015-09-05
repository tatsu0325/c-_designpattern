/*
 * memento.h
 *
 *  Created on: Aug 29, 2015
 *      Author: tatsu
 */

#ifndef MEMENTO_H_
#define MEMENTO_H_
#include <string>
#include <list>
using namespace std ;

class Cell {
public:
	Cell(int x , int y , string text) ;
	int getX() ;
	int getY() ;
	string getText() ;
	void setText(string text) ;
	Cell* clone() ;
private:
	int x ;
	int y ;
	string text ;
};

class Sheet {
public:
	Sheet() ;
	string getCellText(int x , int y ) ;
	Cell* getCell(int x,int y ) ;
	list<Cell*> * getList() ;
	void setSellText(int x, int y , string text) ;
	void undo() ;
	void redo() ;
	void disp() ;
private:
	list<list<Cell*>*> stack ;
	int current ;
	void addStack() ;
	bool isRedoable() ;
};

class SheetWithMemento {
public:
	SheetWithMemnto() ;
	~SheetWithMemento() ;
	string getCellText(int x, int y ) ;
	Cell* getCell(intx ,int y) ;
	void setCellText(int x , int y m string text) ;
	void undo() ;
	void redo() ;
	void disp() ;
private:
	list<Cell*>* getList() ;
	void addStack(Cell* pOldCell,Cell* pNewCell) ;
	bool isRedoable() ;
	lisgt<CellMemento*> stack ;
	list<Cell*> cellList ;
	int current ;
};




#endif /* MEMENTO_H_ */
