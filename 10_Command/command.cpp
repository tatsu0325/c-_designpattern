/*
 * command.cpp
 *
 *  Created on: Aug 25, 2015
 *      Author: tatsu
 */
#include <vector>
using namespace std ;
#include "command.h"

Point::Point() {
	x = 0;
	y = 0 ;
}
Point::Point(int x , int y ) {
	this->x = x ;
	this->y = y ;
}
int Point::getX() { return x ; }
int Point::getY() { return y ;}
string Point::toString() {
	string str ;
	string ssX,ssY ;
	ssX = getX() ;
	ssY = getY() ;
	str += "(" + ssX + "," + ssY + ")" ;
	return str ;
}
Command::Command(Point* point,Point* old){
	this->point = point ;
	this->old = old ;
}
Command::~Command(){
	delete point ;
}

MoveCommand::MoveCommand(Point* point,Point* old) : Command(point,old)  {
}
void MoveCommand::execute() {
}
void MoveCommand::undo() {
}
string MoveCommand::getLine() { return "" ; }

LineCommand::LineCommand(Point* point,Point* old) : Command(point,old)  {
}
void LineCommand::execute() {
}
void LineCommand::undo() {
}
string LineCommand::getLine() {
	string str ;
	str += "Line[" ;
	str += old->toString() ;
	str += "<->" ;
	str += point->toString() ;
	str += "]" ;
	return str ;
}


Graphic::Graphic() {
	this->current = 0;
	this->history.push_back(new MoveCommand(new Point(0,0),new Point(0,0)));
}

Graphic::~Graphic() {
	vector<Command*>::iterator it = history.begin() ;
	while( it != history.end() ) {
		delete(*it) ;
		it ++ ;
	}
	history.clear() ;
}

string Graphic::status() {
	string str = "current[" ;
	str += getCurrentCommand()->getPoint()->toString() ;
	str += "]\n" ;

	Command * command ;
	for(int i = 0 ; i <= current ; i ++ ){
		command = (Command*)history[i] ;
		str += command->getLine() ;
	}
	return str ;
}

void Graphic::moveTo(int x, int y ) {
	addHistory(new MoveCommand(new Point(x,y),
			  getCurrentCommand()->getPoint())) ;
}

bool Graphic::isRedoable() {
	if(current < (int) history.size() -1 ) return true ;
	return false ;
}

void Grahic::undo() {
	if ( current > 0 ) {
		getCurrnetCommand()->undo() ;
		current -- ;
	}
}

void Grahic::redo() {
	if ( isRedoable()) {
		current ++ ;
		getCurrnetCommand()->execute() ;
	}
}

Command* Graphic::getCurrentCommand() {
	vector<Command*>::iterator it = history.begin() ;
	it += current ;
	return (*it) ;
}

void Graphic::addHistory(Command* command) {
	if(isRedoable()) {
		vector<Command*>::iterator it = hisgtory.begin() ;
		it += current + 1  ;
		history.erase(it,history.end()) ;
	}
	history.push_back(command) ;
	current++ ;
	command->execute() ;
}

void Graphic::lineTo(init x , int y) {
	addHistory(new LineCommand(new Point(x,y),getCurrentCommand()->getPoint()) ;)
}

