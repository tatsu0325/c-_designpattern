/*
 * interpreter.h
 *
 *  Created on: Aug 30, 2015
 *      Author: tatsu
 */

#ifndef INTERPRETER_H_
#define INTERPRETER_H_
#include <string>
using namespace std ;
class Context {
public:
	Context(bool reservedSeatAvailable) ;
	bool isReservedSeatAvailable() ;
	static Context* createReservedSeatAvailable() ;
	static Context* createReservedSeatUnavailable() ;
private:
	bool reservedSeatAvailable ;
};

class AbstractPolicy {
public:
	virtual string buy(Context* pContext) = 0 ;
	static AbstractPolicy* preferReservedSeat() ;
	static AbstractPolicy* necessaryReservedSeat() ;
	static AbstractPolicy* preferUnreservedSeat() ;
};

class PreferReservedSeatPolicy : public AbstractPolicy {
public:
	virtual string buy(Context* pContext) ;
};

class NecessaryReservedSeatPolicy : public AbstractPolicy {
public:
	virtual string buy(Context* pContext) ;
};

class PreferUnreservedSeatPolicy: public AbstractPolicy {
public:
	virtual string buy(Context* pContext) ;
};
#endif /* INTERPRETER_H_ */
