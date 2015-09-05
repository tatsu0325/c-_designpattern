/*
 * flyweight.h
 *
 *  Created on: Aug 29, 2015
 *      Author: tatsu
 */

#ifndef FLYWEIGHT_H_
#define FLYWEIGHT_H_
#include <list>
#include <map>

using namespace std;
class WalletItem ;
class BillCoin ;
class BillCoinFactory ;

class Wallet {
public:
	~Wallet() ;
	void add(WalletItem* pItem) ;
	int getAmount() ;
private:
	list<WalletItem*> items ;
};

class WalletItem {
public:
	WalletItem(BillCoin* pCoin, int quantity) ;
	int getAmount() ;
private:
	BillCoin* pCoin ;
	int quantity ;
};

class BillCoin {
	friend BillCoinFactory ;
public:
	int getAmount() ;
private:
	BillCoin(int amount) ;
	int amount;
};

static int kind[] = { 10000,5000,2000,1000,500,100,50,10,5,1} ;
const int EXCEPTION_AMOUNT = -1 ;

class BillCoinFactory {
public:
	BillCoinFactory() ;
	BillCoin* getBillCoin(int amount) ;
private:
	static map<int,BillCoin*> coins ;
};

#endif /* FLYWEIGHT_H_ */
