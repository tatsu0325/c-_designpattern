/*
 * strategy.cpp
 *
 *  Created on: Aug 26, 2015
 *      Author: tatsu
 */
#include <iostream>
using namespace std ;
#include "strategy.h"

void KyotoDialect::sayWelcome() {cout << "おいでやす" << endl ;}
void KyotoDialect::sayThanks() { cout << "おおきに" << endl ; }
void NagoyaDialect::sayWelcome() {cout << "いりゃせ" << endl ; }
void NagoyaDialect::sayThanks() {cout << "ありがとう" << endl; }

DialectSpeaker::DialectSpeaker(int dialect) {
	switch(dialect) {
	case KYOTO:
		this->pDialect = new KyotoDialect() ;
		break;
	case NAGOYA:
		this->pDialect = new NagoyaDialect() ;
		break;
	}
}
DialectSpeaker::~DialectSpeaker() { delete pDialect ;}
void DialectSpeaker::sayWelcome() { pDialect->sayWelcome() ;}
void DialectSpeaker::sayThanks() { pDialect->sayThanks() ;}

int main() {
	DialectSpeaker* pKyotoPerson = new DialectSpeaker(DialectSpeaker::KYOTO) ;
	pKyotoPerson->sayWelcome() ;
	pKyotoPerson->sayThanks() ;

	DialectSpeaker* pNagoyaPerson = new DialectSpeaker(DialectSpeaker::NAGOYA) ;
	pNagoyaPerson->sayWelcome() ;
	pNagoyaPerson->sayThanks() ;

	delete pKyotoPerson ;
	delete pNagoyaPerson;
	return 0;
}



