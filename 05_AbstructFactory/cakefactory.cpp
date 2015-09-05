/*
 * cakefactory.cpp
 *
 *  Created on: Aug 29, 2015
 *      Author: tatsu
 */
#include <iostream>
using namespace std ;
#include "cakefactory.h" ;

int main(void) {
	DecoCakeFactory* pFactory ;
	CakeBase* pBase ;
	Fruit* pFruit ;
	Decoration* pDecoration ;

	pFactory = new BirthdayCakeFactory() ;

	pBase = pFactory->CreateBase() ;
	pFruit = pFactory->CreateFruit() ;
	pDecoration = pFactory->CreateDecoration() ;

	pBase->makeBase() ;
	pFruit->makeFruit() ;
//	pDecoration->makeDecoration("Eri chan") ;
	pDecoration->makeDecoration() ;
}



