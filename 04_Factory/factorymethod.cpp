/*
 * factorymethod.cpp
 *
 *  Created on: Aug 29, 2015
 *      Author: tatsu
 */
#include <string>
#include "factorymethod.h"
using namespace std ;

FileDataObject::FileDataObject() {
}

string FileDataObject::getName(int id) {
}

DataObject* DataObject::create() {
	return new FileDataObject () ;
}

int main () {
	DataObject* pDataObject = DataObject::create() ;
	string strName = pDataObject->getName(1) ;
}


