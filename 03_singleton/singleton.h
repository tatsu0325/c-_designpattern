/*
 * singleton.h
 *
 *  Created on: Aug 29, 2015
 *      Author: tatsu
 */
#ifndef SINGLETON_H_
#define SINGLETON_H_

#include <iostream>
#include <string>

using namespace std ;

class PrintSpool {
private:
	PrintSpool() {}
	PrintSpool ( const PrintSpool & obj )  {}
	PrintSpool& operator=(const PrintSpool& obj) {}
public:
	static PrintSpool* getInstance() {
		static PrintSpool instance ;
		return &instance ;
	}
	void setSpool(string printData) {
		cout <<"Store buffer :" << printData << endl ;
	}
};

class Process {
public:
	Process() {}
	void printOut(string printData) {
		PrintSpool::getInstance()->setSpool(printData) ;
	}
};

#endif /* SINGLETON_H_ */
