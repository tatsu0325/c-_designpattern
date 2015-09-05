/*
 * bridg.h
 *
 *  Created on: Aug 27, 2015
 *      Author: tatsu
 */

#ifndef BRIDG_H_
#define BRIDG_H_
#include <fstream>
#include <string>
using namespace std ;

class WriterImpl {
public:
	virtual void openFile() = 0 ;
	virtual void writeString(string& str) = 0 ;
	virtual void closeFile() = 0 ;
};


class Writer {
public:
	virtual void openFile() = 0 ;
	virtual void writeString(string& str) = 0 ;
	virtual void closeFile() = 0 ;
	WriterImpl* getImpl() ;
	void setImpl(WriterImpl* impl) ;
private:
	WriterImpl* pImpl ;
};

class PlainWriter : public Writer {
public:
	virtual void openFile() = 0 ;
	virtual void writeString(string& str) = 0 ;
	virtual void closeFile() = 0 ;
};

class HtmlWriter : public Writer {
public:
	virtual void writeString(string& str) = 0 ;
} ;

class ConsoleWriter : public WriterImpl {
public:
	virtual void openFile()  ;
	virtual void writeString(string& str)  ;
	virtual void closeFile() ;
};

class LocalFileWriter : public WriterImpl {
public:
	LocalFileWriter(string fileName) ;
	virtual ~LocalFileWriter() ;
	virtual void openFile()  ;
	virtual void writeString(string& str)  ;
	virtual void closeFile() ;
protected:
	ofstream * ofs ;
private:
	string fileName ;
};

#endif /* BRIDG_H_ */
