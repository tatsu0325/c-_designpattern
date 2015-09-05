/*
 * prototype.h
 *
 *  Created on: Aug 29, 2015
 *      Author: tatsu
 */

#ifndef PROTOTYPE_H_
#define PROTOTYPE_H_
#include <string>
using namespace std ;

class Cloneable {
public:
	virtual Cloneable* clone() = 0 ;
};

class Location : public Cloneable {
public:
	Location(int x , int y ) ;
	int getX() const ;
	int getY() const ;
	void move(int x, int y) ;
	Cloneable* clone() ;
private:
	int x ;
	int y ;
};

class Piece : public Cloneable {
public:
	Piece() ;
	~Piece() ;
	string getName() const ;
	void setName(string name) ;
	Location* getLocation() ;
	void setLocation(Location* pLocation) ;
	void move(int x , int y) ;
	Cloneable* clone() ;
private:
	string name ;
	Location* pLocation ;
};

#endif /* PROTOTYPE_H_ */
