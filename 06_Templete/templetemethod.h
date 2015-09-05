/*
 * templetemethod.h
 *
 *  Created on: Aug 29, 2015
 *      Author: tatsu
 */

#ifndef TEMPLETEMETHOD_H_
#define TEMPLETEMETHOD_H_
#include <string>
using namespace std ;

class FileFormatter {
public:
	void formatter(string infile,string outfile) ;
	virtual string readFile(string filename) = 0 ;
	virtual string formatting(string data) = 0 ;
	virtual void writeToFile(string outfilename,string modData) = 0 ;
};

class TabToCSVFormatter : public FileFormatter {
public:
	string readFile(string filename) = 0 ;
	string formatting(string data) = 0 ;
	void writeToFile(string outfilename,string modData) = 0 ;
};

class CSVToHTMLFormatter : public FileFormatter {
public:
	string readFile(string filename) = 0 ;
	string formatting(string data) = 0 ;
	void writeToFile(string outfilename,string modData) = 0 ;
};

class TextLengthFormatter : public FileFormatter {
public:
	string readFile(string filename) = 0 ;
	string formatting(string data) = 0 ;
	void writeToFile(string outfilename,string modData) = 0 ;
};

#endif /* TEMPLETEMETHOD_H_ */
