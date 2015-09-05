/*
 * strategy.h
 *
 *  Created on: Aug 26, 2015
 *      Author: tatsu
 */

#ifndef STRATEGY2_H_
#define STRATEGY2_H_

class Dialect {
public:
	virtual void sayWelcome() = 0 ;
	virtual void sayThanks() = 0 ;
};

class KyotoDialect : public Dialect {
public:
	void sayWelcome();
	void sayThanks() ;
};

class NagoyaDialect : public Dialect {
public:
	void sayWelcome();
	void sayThanks() ;
};

class DialectSpeaker {
public:
	const static int KYOTO = 1 ;
	const static int NAGOYA = 2 ;

	DialectSpeaker(int dialect) ;
	~DialectSpeaker() ;
	void sayWelcome() ;
	void sayThanks() ;
private:
	Dialect* pDialect ;
};

#endif /* STRATEGY_H_ */
