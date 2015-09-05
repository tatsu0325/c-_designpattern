/*
 * command.h
 *
 *  Created on: Aug 25, 2015
 *      Author: tatsu
 */

#ifndef COMMAND_H_
#define COMMAND_H_

#include <string>
#include <vector>
using namespace std;

class Point {
public:
	Point() ;
	Point(int x, int y) ;
	int getX() ;
	int getY();
	string toString() ;
private:
	int x ;
	int y ;
};

class Command : public Point {
public:
	Command(Point* point, Point* old);
	~Command();
	virtual void execute() = 0;
	virtual void undo() = 0;
	virtual string getLine() = 0;
	Point* getPoint();
protected:
	Point* point;
	Point* old;
};

class MoveCommand: public Command {
public:
	MoveCommand(Point* point, Point* old);
	void execute();
	void undo();
	string getLine();
};

class LineCommand: public Command {
public:
	LineCommand(Point* point, Point* old);
	void execute();
	void undo();
	string getLine();
};
class Graphic {
public:
	Graphic();
	~Graphic();
	string status();
	void moveTo(int x, int y);
	bool isRedoable();
	void undo();
	void redo();
	Command* getCurrentCommand();
	void lineTo(int x, int y);
private:
	void addHistory(Command* command);
	vector<Command*> history;
	int current;
};

#endif /* COMMAND_H_ */
