/*
 * singleton.cpp
 *
 *  Created on: Aug 29, 2015
 *      Author: tatsu
 */
#include "singleton.h"

int main(void) {
	Process* pProcA = new Process() ;
	Process* pProcB = new Process() ;
	Process* pProcC = new Process() ;

	pProcA->printOut("Singlegton Pattern");
	pProcB->printOut("シングルトンパターン");
	pProcC->printOut("しんぐるとーんぱたーん");

	delete pProcA ;
	delete pProcB ;
	delete pProcC ;

	return 0 ;
}



