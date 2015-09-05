/*
 * factorymethod.h
 *
 *  Created on: Aug 29, 2015
 *      Author: tatsu
 */
#ifndef FACTORYMETHOD_H_
#define FACTORYMETHOD_H_

#include <map>
#include <string>
using namespace std ;

class DataObject {
public:
	static DataObject* create() ;
	virtual string getName(int id) = 0 ;
};

class FileDataObject : public DataObject {
public:
	FileDataObject() ;
	string getName(int id) ;
private:
	map<int,string> m_data ;
};



#endif /* FACTORYMETHOD_H_ */
