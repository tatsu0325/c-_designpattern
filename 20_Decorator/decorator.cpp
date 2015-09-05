/*
 * decorator.cpp
 *
 *  Created on: Aug 29, 2015
 *      Author: tatsu
 */
#include <iostream>
#include <string>
using namespace std ;
#include <fstream>
#include "decorator.h"

void ConsoleWriter::writeData(string str) {
	cout << str << endl ;
}

LocalFileWriter::LocalFileWriter(string fileName) {
	this->fileName = fileName ;
}

void LocalFileWriter::writeData(string str) {
	ofstream* ofs = new ofstream() ;

	ofs->open(fileName.c_str()) ;
//	ofs->write(str) ;
	ofs->close() ;

	delete ofs ;
}
BRWriter::BRWriter(Writer* pOut) {
	this->pOut = pOut ;
}

void BRWriter::writeData(string str) {
	string before = "\n";
	string after = "<br> ";
	string::size_type pos, size = 0;

	while ((pos = str.find(before, size)) != string::npos) {
		str.replace(pos, before.size(), after);
		size = pos + after.size();
	}
	pOut->writeData(str);
}

int main(void) {
	cout << "Hello WOrld" << endl;
}

