/*
 * chainofresponsibility.h
 *
 *  Created on: Aug 29, 2015
 *      Author: tatsu
 */

#ifndef CHAINOFRESPONSIBILITY_H_
#define CHAINOFRESPONSIBILITY_H_
const int LIGHT_LUGGAGE = 15 ;
const int MEDIUM_LUGGAGE = 45 ;
const int HEAVY_LUGGAGE = 120 ;
//const int NULL = 0 ;

class Luggage {
public:
	Luggage(int weight) ;
	int getWeight() ;
private:
	int weight ;
};

class Delivery {
public:
	Delivery() ;
	Delivery(Delivery* pChain) ;
	virtual bool checkLuggage(Luggage* pLuggage) = 0 ;
	virtual void deliver(Luggage* pLuggage) = 0 ;
	virtual void handle(Luggage* pLuggage) = 0 ;
protected:
	void getAcceptance(Luggage* pLuggage) ;
private:
	Delivery* pSuccessor ;
};

class LightLuggageDelivery : public Delivery {
public:
	LightLuggageDelivery(Delivery* pChain) ;
	bool checkLuggage(Luggage* pLuggage) ;
	void deliver(Luggage* pLuggage) ;
	void handle(Luggage* pLuggage) ;
};

class MediumLuggageDelivery : public Delivery {
public:
	MediumLuggageDelivery(Delivery* pChain) ;
	bool checkLuggage(Luggage* pLuggage) ;
	void deliver(Luggage* pLuggage) ;
	void handle(Luggage* pLuggage) ;
};

class HeavyLuggageDelivery : public Delivery {
public:
	HeavyLuggageDelivery(Delivery* pChain) ;
	bool checkLuggage(Luggage* pLuggage) ;
	void deliver(Luggage* pLuggage) ;
	void handle(Luggage* pLuggage) ;
};

#endif /* CHAINOFRESPONSIBILITY_H_ */
