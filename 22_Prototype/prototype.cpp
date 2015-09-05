/*
 * prototype.cpp
 *
 *  Created on: Aug 29, 2015
 *      Author: tatsu
 */
#include <iostream>
#include <string>
#include "prototype.h"
using namespace std ;

Piece::Piece() { pLocation = 0 ; }
Piece::~Piece() { if(pLocation != 0 ) delete pLocation ; }
string Piece::getName() const { return name ; }
void Piece::setName(string name) { this->name = name ;}
void Piece::setLocation(Location *pLocation) {
	this->pLocation = pLocation ;
}
Location* Piece::getLocation() {
	return pLocation ;
}
void Piece::move(int x , int y) { pLocation->move(x,y) ; }
Cloneable* Piece::clone() {
	Piece* pClone = new Piece() ;
	pClone->setLocation((Location*) pLocation->clone()) ;
	return pClone ;
}

Location::Location(int x , int y ) {
	this->x = x ;
	this->y = y ;
}
int Location::getX() const { return x; }
int Location::getY() const { return y; }
void Location::move(int x, int y ) {
	this->x += x ;
	this->y += y;
}
Cloneable* Location::clone() {
	Location* pClone = new Location(x,y) ;
	return pClone ;
}

int main(void) {
	Piece* pFuA = new Piece() ;
	pFuA->setName("FuA") ;
	pFuA->setLocation(new Location(1,7)) ;
	pFuA->move(0,-1) ;
	Piece* pFuB = (Piece*)pFuA->clone() ;
	pFuB->setName("FuB") ;
	pFuB->move(0,-1) ;

	cout << "FuA" << endl;
	cout << "Name:" << pFuA->getName() << endl;
	cout << "LocationX:" << pFuA->getLocation()->getX() << endl;
	cout << "LocationY:" << pFuA->getLocation()->getY() << endl;
	cout << "--------------" << endl;
	cout << "FuB" << endl;
	cout << "Name:" << pFuB->getName() << endl;
	cout << "LocationX:" << pFuB->getLocation()->getX() << endl;
	cout << "LocationY:" << pFuB->getLocation()->getY() << endl;

	delete pFuA ;
	delete pFuB ;
}


