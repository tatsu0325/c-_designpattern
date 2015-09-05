/*
 * decorator.h
 *
 *  Created on: Aug 29, 2015
 *      Author: tatsu
 */

#ifndef DECORATOR_H_
#define DECORATOR_H_
#include <string>
#include <fstream>
using namespace std ;

class Writer {
public:
	virtual void writeData(string str) = 0 ;
};

class ConsoleWriter : public Writer {
public:
	virtual void writeData(string str) ;
};

class LocalFileWriter : public Writer {
public:
	LocalFileWriter(string fileName) ;
	virtual void writeData(string str) ;
private:
	string fileName ;
};
class BRWriter: public Writer {
public:
	BRWriter(Writer* pOut);
	void writeData(string str);
private:
	Writer* pOut;
};

#endif /* DECORATOR_H_ */
