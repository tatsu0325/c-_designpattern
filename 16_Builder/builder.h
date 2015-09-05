/*
 * builder.h
 *
 *  Created on: Aug 26, 2015
 *      Author: tatsu
 */

#ifndef BUILDER_H_
#define BUILDER_H_
#include <string>
using namespace std;

class BuildHome {
public:
	void setPillar(string pillar) ;
	string getPillar() ;
	void setWall(string wall) ;
	string getWall() ;
	void setRoof(string roof) ;
	string getRoof() ;
private:
	string pillar ;
	string wall ;
	string roof ;
};

class HomeBuilder {
public:
	virtual void setStructure() = 0 ;
	virtual BuildHome* getResult() = 0 ;
};

class ModernHomeBuilder : public HomeBuilder {
public:
	ModernHomeBuilder() ;
	virtual void setStructure() = 0 ;
	virtual BuildHome* getResult() = 0 ;
private:
	BuildHome* pBuildHome ;
} ;

class EuropeanHomeBuilder : public HomeBuilder {
public:
	EuropeanHomeBuilder() ;
	virtual void setStructure() = 0 ;
	virtual BuildHome* getResult() = 0 ;
private:
	BuildHome* pBuildHome ;
} ;

class JapaneseHomeBuilder : public HomeBuilder {
public:
	JapaneseHomeBuilder() ;
	virtual void setStructure() = 0 ;
	virtual BuildHome* getResult() = 0 ;
private:
	BuildHome* pBuildHome ;
};

class Director {
public:
	void construct(HomeBuilder* pBuilder) ;
};

#endif /* BUILDER_H_ */
