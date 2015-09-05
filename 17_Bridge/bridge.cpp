/*
 * bridge.cpp
 *
 *  Created on: Aug 27, 2015
 *      Author: tatsu
 */
#include <string>
#include <fstream>
#include <iostream>
#include "bridge.h"
using namespace std ;

WriterImpl* Writer::getImpl() {
	return pImpl ;
}
void Writer::setImpl(WriterImpl* pImpl) {
	this->pImpl = pImpl ;
}

void PlainWriter::openFile() {
	getImpl()->openFile() ;
}

void PlainWriter::closeFile() {
	getImpl()->closeFile() ;
}

void PlainWriter::writeString(string& str) {
	getImpl()->writeString(str) ;
}

void HtmlWriter::writeString(string& str) {
	string htmlstr = "<h1>" + str + "</h1>" ;
	getImpl()->writeString(htmlstr) ;
}

void ConsoleWriter::openFile() {}
void ConsoleWriter::closeFile() {}
void ConsoleWriter::writeString(string& str) {
	cout << str << endl ;
}

LocalFileWriter::LocalFileWriter(string fileName) {
	ofs = new ofstream() ;
	this->fileName = fileName ;
}

LocalFileWriter::~LocalFileWriter() {
	delete ofs ;
}
void LocalFileWriter::openFile() {
	ofs->open(fileName.c_str()) ;
}
void LocalFileWriter::writeString(string& str) {
	ofs->write(str.c_str(),(std::streamsize) str.length()) ;
}
void LocalFileWriter::closeFile() {
	ofs->close() ;
}
