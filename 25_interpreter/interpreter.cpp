/*
 * interpreter.cpp
 *
 *  Created on: Aug 30, 2015
 *      Author: tatsu
 */
#include "interpreter.h"

Context::Context(bool reservedSeatAvailable) {
	this->reservedSeatAvailable = reservedSeatAvailable ;
}
bool Context::isReservedSeatAvailable() {
	return reservedSeatAvailable ;
}
Context* Context::createReservedSeatAvailable() {
	return new Context(true) ;
}
Context* Context::createReservedSeatUnavailable() {
	return new Context(false) ;
}

AbstractPolicy* AbstractPolicy::preferReservedSeat() {
	return new PreferReservedSeatPolicy() ;
}

AbstractPolicy* AbstractPolicy::necessaryReservedSeat() {
	return new NecessaryReservedSeatPolicy() ;
}
AbstractPolicy* AbstractPolicy::preferUnreservedSeat() {
	return new PreferUnreservedSeatPolicy() ;
}

string PreferReservedSeatPolicy::buy(Context* pContext) {
	if (pContext->isReservedSeatAvailable()) return "Reserved Seat" ;
	else return "Unreserved Seat" ;
}
string NecessaryReservedSeatPolicy::buy(Context* pContext) {
	if (pContext->isReservedSeatAvailable()) return "Reserved Seat" ;
	else return "Nothing" ;
}
string PreferUnreservedSeatPolicy::buy(Context* pContext) {
	return "Unreserved Seat" ;
}

