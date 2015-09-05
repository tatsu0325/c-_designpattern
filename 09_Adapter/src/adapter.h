/*
 * adapter.h
 *
 *  Created on: Aug 25, 2015
 *      Author: tatsu
 */

#ifndef ADAPTER_H_
#define ADAPTER_H_

#include <iostream>
#include <fstream>
#include <string>
using namespace std ;

class Writer {
public:
	virtual void openFile() = 0 ;
	virtual void writeData(string stringDat) = 0 ;
	virtual void closeFile() = 0 ;
};

class HTMLWriter : public Writer {
public:
	HTMLWriter(string filename) ;
	void fileOpen() ;
	void fileClose() ;
	string conversionString(string beforeStr) ;
	void fileWrite(string afterStr) ;
};

class FileWriter : public Writer {
public:
	FileWriter(string filename) ;
	void openFile() ;
	void closeFile() ;
	void writeData(string stringDat) ;
private:
	std::ofstream ofs ;
	std::string filename ;
};

class HTMLWriterClassAdapter : public HTMLWriter
            , public Writer {
public:
	HTMLWriterClassAdapter(string filename) ;
	void openFile() ;
	void writeData(string stringDat) ;
	void closeFile() ;
};

#endif /* ADAPTER_H_ */
