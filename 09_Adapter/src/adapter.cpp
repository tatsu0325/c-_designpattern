/*
 * adapter.cpp
 *
 *  Created on: Aug 25, 2015
 *      Author: tatsu
 */
#include <iostream>
#include <string>
#include <fstream>
#include "adapter.h"
using namespace std;

FileWriter::FileWriter(string filename) {
	this->filename = filename ;
}

void FileWriter::openFile() {
	ofs.open(filename.c_str(),ios::trunc);
}

void FileWriter::closeFile() {
	ofs.close() ;
}

void FileWriter::writeData(string stringDat) {
	ofs << stringDat.c_str() << endl ;
}

HTMLWriter::HTMLWriter(string filename) {
}

void HTMLWriter::fileOpen() {
}

void HTMLWriter::fileClose() {
}

void HTMLWriter::fileWrite(string stringDat) {
	cout << stringDat.c_str() << endl ;
}
string HTMLWriter::conversionString(string stringDat) {
	string oStr = "[" ;
	oStr = "[" + stringDat + "]" ;
	return oStr ;
}


HTMLWriterClassAdapter::HTMLWriterClassAdapter(string filename) : HTMLWriter(filename) {

}

void HTMLWriterClassAdapter::openFile() { fileOpen() ; }
void HTMLWriterClassAdapter::closeFile() { fileClose() ; }
void HTMLWriterClassAdapter::writeData(string stringDat ) {
	fileWrite(conversionString(stringDat)) ;
}

int main() {
	HTMLWriterClassAdapter* writer = new HTMLWriterClassAdapter("/tmp/test.html") ;
	writer->writeData("TestHTML.String") ;

	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}


