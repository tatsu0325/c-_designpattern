/*
 * builder.cpp
 *
 *  Created on: Aug 26, 2015
 *      Author: tatsu
 */
#include <iostream>
using namespace std ;

#include "builder.h"

void BuildHome::setPillar(string pillar) { this->pillar = pillar ; }
void BuildHome::setWall(string wall) { this->wall = wall ; }
void BuildHome::setRoof(string roof) { this->roof = roof ; }
string BuildHome::getPillar() { return pillar ; }
string BuildHome::getWall() { return wall ; }
string BuildHome::getRoof() { return roof ; }

ModernHomeBuilder::ModernHomeBuilder() {
	pBuildHome = new BuildHome() ;
	setStructure() ;
}

void ModernHomeBuilder::setStructure() {
	pBuildHome->setPillar("軽量鉄骨造") ;
	pBuildHome->setWall("コンクリート") ;
	pBuildHome->setRoof("コンクリート") ;
}

BuildHome* ModernHomeBuilder::getResult() { return pBuildHome ; }

EuropeanHomeBuilder::EuropeanHomeBuilder() {
	pBuildHome = new BuildHome() ;
}
void EuropeanHomeBuilder::setStructure() {
	pBuildHome->setPillar("木造") ;
	pBuildHome->setWall("サイティング") ;
	pBuildHome->setRoof("スレート葺き") ;
}
BuildHome * EuropeanHomeBuilder::getResult() { return pBuildHome ; }

JapaneseHomeBuilder::JapaneseHomeBuilder() {
	pBuildHome = new BuildHome() ;
}
void JapaneseHomeBuilder::setStructure() {
	pBuildHome->setPillar("木造") ;
	pBuildHome->setWall("和風タイル貼り") ;
	pBuildHome->setRoof("瓦") ;
}
BuildHome * JapaneseHomeBuilder::getResult() { return pBuildHome ; }

void Director::construct(HomeBuilder* pBuilder) {
	pBuilder->setStructure() ;
}

int main() {
	HomeBuilder* pBuilder ;
	Director* pDirector = new Director() ;
	int build_type = 2 ;

//	if(       build_type == 0 )  pBuilder = new ModernHomeBuilder();
//	else if ( build_type == 1 )  pBuilder = new EuropeanHomeBuilder() ;
//	else if ( build_type == 2 )  pBuilder = new JapaneseHomeBuilder() ;

	pBuilder = new ModernHomeBuilder();
	pDirector->construct(pBuilder) ;
	BuildHome* pBuild = pBuilder->getResult() ;

	cout << "今回建築する住宅は" << endl ;
	cout << "構造が" << pBuild->getPillar() << "で、" << endl ;
	cout << "外壁が" << pBuild->getWall()   << "で、" << endl ;
	cout << "屋根が" << pBuild->getRoof() << "で、" << endl ;

	delete pBuilder ;
	delete pDirector ;
	delete pBuild ;
	return  0 ;
}
