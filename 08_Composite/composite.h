/*
 * Composite.h
 *
 *  Created on: Aug 25, 2015
 *      Author: tatsu
 */

#ifndef COMPOSITE_H_
#define COMPOSITE_H_

#include <vector>
//using namespace std ;

class District {
public:
	virtual int getPopulation() = 0 ;
};

class UnitDistrict : public District {
public:
	virtual int getPopulation() ;
	void setPopulation(int population) ;
private:
	int population ;
};


class GroupDistrict : public District {
public:
	~GroupDistrict() ;
	void add(District * district) ;
	virtual int getPopulation() ;
private:
	std::vector<District*> districts ;
};

#endif /* COMPOSITE_H_ */
