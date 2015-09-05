//============================================================================
// Name        : 08_Composite.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "composite.h"

int UnitDistrict::getPopulation() {
	return population;
}

void UnitDistrict::setPopulation(int population) {
	this->population = population ;
}

GroupDistrict::~GroupDistrict(){
	for( int i = 0 ; i < (int)districts.size() ; i ++ ) {
		delete districts[i] ;
	}
}

void GroupDistrict::add(District * district) {
	districts.push_back(district) ;
}

int GroupDistrict::getPopulation() {
	int result = 0 ;
	for(int i = 0 ; i < districts.size() ; i ++ ) {
		result += districts[i]->getPopulation() ;
	}
	return result ;
}
int main() {
	GroupDistrict* japan = new GroupDistrict() ;
	GroupDistrict* tokyo = new GroupDistrict() ;
	UnitDistrict*  minatoku = new UnitDistrict() ;
	UnitDistrict*  shibuyaku = new UnitDistrict() ;
	GroupDistrict* aichi = new GroupDistrict() ;
	UnitDistrict*  nagoyashi = new UnitDistrict() ;
	UnitDistrict*  chiryuushi = new UnitDistrict() ;
	GroupDistrict* osaka = new GroupDistrict() ;
	UnitDistrict*  oosakashi = new UnitDistrict() ;
	UnitDistrict*  amagasakishi = new UnitDistrict() ;

	minatoku->setPopulation(1000);
	shibuyaku->setPopulation(2000) ;
	tokyo->add(minatoku) ;
	tokyo->add(shibuyaku) ;

	cout << tokyo->getPopulation() << endl ;


	japan->add(tokyo);
	japan->add(aichi);
	japan->add(osaka);

	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
