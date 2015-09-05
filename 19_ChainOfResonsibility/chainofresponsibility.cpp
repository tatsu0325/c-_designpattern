/*
 * chainofresponsibility.cpp
 *
 *  Created on: Aug 29, 2015
 *      Author: tatsu
 */
#include <cstdio>
#include <iostream>
using namespace std ;
#include "chainofresponsibility.h"
Luggage::Luggage(int weight) {
	this->weight = weight ;
}

int Luggage::getWeight() { return weight ; }

//Delivery::Delivery() {}
Delivery::Delivery(Delivery* pChain) {
	pSuccessor = pChain ;
}
void Delivery::getAcceptance(Luggage* pLuggage) {
	if (pSuccessor != NULL ) {
		pSuccessor->handle(pLuggage) ;
	} else {
		cout << "Weight Over" << endl ;
	}
}

LightLuggageDelivery::LightLuggageDelivery(Delivery* pChain)
         : Delivery(pChain) {
}

void LightLuggageDelivery::handle(Luggage* pLuggage) {
	if ( checkLuggage(pLuggage)) deliver(pLuggage) ;
	else getAcceptance(pLuggage) ;
}
MediumLuggageDelivery::MediumLuggageDelivery(Delivery* pChain)
          : Delivery(pChain) {
}

void MediumLuggageDelivery::handle(Luggage* pLuggage) {
	if ( checkLuggage(pLuggage)) deliver(pLuggage) ;
	else getAcceptance(pLuggage) ;
}
HeavyLuggageDelivery::HeavyLuggageDelivery(Delivery* pChain)
          : Delivery(pChain) {
}

void HeavyLuggageDelivery::handle(Luggage* pLuggage) {
	if ( checkLuggage(pLuggage)) deliver(pLuggage) ;
	else getAcceptance(pLuggage) ;
}

int main() {
	Delivery* pChain ;
	pChain = new LightLuggageDelivery(
			   new MediumLuggageDelivery(
			   new HeavyLuggageDelivery(NULL))) ;

	Luggage* pLuggage = new Luggage(LIGHT_LUGGAGE) ;
	pChain->handle(pLuggage) ;
}



