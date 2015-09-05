/*
 * templetemethod.cpp
 *
 *  Created on: Aug 29, 2015
 *      Author: tatsu
 */
#include <iostream>
#include <string>
#include "templetemethod.h"
using namespace std ;

void FileFormatter::formatter(string infile,string outfile) {
	string data = readFile(infile) ;
	string formattedData = formatting(data) ;
	writeToFile(outfile,formattedData) ;
}

string TabToCSVFormatter::readFile(string filename) {
	return filename ;
}
string TabToCSVFormatter::formatting(string data) {return data ; }
void TabToCSVFormatter::writeToFile(string outfilename, string modData) {

}

string CSVToHTMLFormatter::readFile(string filename) {return filename ;}
string CSVToHTMLFormatter::formatting(string data) {return data ; }
void CSVToHTMLFormatter::writeToFile(string outfilename, string modData) {}

string TextLengthFormatter::readFile(string filename) {return filename ;}
string TextLengthFormatter::formatting(string data) {return data ;}
void TextLengthFormatter::writeToFile(string outfilename, string modData) {}

int main(void) {
	cout << "Hello World" << endl ;
}

