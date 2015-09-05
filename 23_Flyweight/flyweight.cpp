/*
 * flyweight.cpp
 *
 *  Created on: Aug 29, 2015
 *      Author: tatsu
 */
#include <iostream>
#include <list>

//using namespace std ;
#include "flyweight.h"

Wallet::~Wallet() {
	list<WalletItem*>::iterator it = items.begin() ;
	while(it != items.end()) {
		delete(*it) ;
		it ++ ;
	}
	delete &items ;
}

void Wallet::add(WalletItem* pItem) { items.push_back(pItem) ; }
int Wallet::getAmount() {
	int result = 0 ;
	list<WalletItem*>::iterator it = items.begin() ;
	while(it != items.end() ) {
		result += (*it)->getAmount() ;
		it ++ ;
	}
	return result ;
}

WalletItem::WalletItem(BillCoin* pCoin,int quantitiy) {
	this->pCoin = pCoin ;
	this->quantity = quantity ;
}
int WalletItem::getAmount() {
	return pCoin->getAmount() * quantity ;
}

BillCoin::BillCoin(int amount) { this->amount = amount ; }
int BillCoin::getAmount() { return amount ; }

map<int,BillCoin*> BillCoinFactory::coins ;
BillCoinFactory::BillCoinFactory() {
	for ( int i = 0 ; i < 10 ; i ++ ) {
		coins.insert(make_pair(kind[i],new BillCoin(kind[i]))) ;
	}
}
BillCoin* BillCoinFactory::getBillCoin(int amount) {
	BillCoin* pResult ;
	pResult = (BillCoin*) coins[amount] ;
	if (pResult == NULL ) throw EXCEPTION_AMOUNT ;
	return pResult ;
}

int  main() {
	BillCoinFactory* pBillCoinFactory = new BillCoinFactory ;
	Wallet* pWallet = new Wallet ;
//	try
//	{
		pWallet->add(new WalletItem(pBillCoinFactory->getBillCoin(10000),1)) ;
		pWallet->add(new WalletItem(pBillCoinFactory->getBillCoin(5000),1)) ;
		pWallet->add(new WalletItem(pBillCoinFactory->getBillCoin(2000),1)) ;
		pWallet->add(new WalletItem(pBillCoinFactory->getBillCoin(1000),1)) ;
		pWallet->add(new WalletItem(pBillCoinFactory->getBillCoin(500),1)) ;
		pWallet->add(new WalletItem(pBillCoinFactory->getBillCoin(100),1)) ;
		pWallet->add(new WalletItem(pBillCoinFactory->getBillCoin(50),1)) ;
		pWallet->add(new WalletItem(pBillCoinFactory->getBillCoin(10),1)) ;
		pWallet->add(new WalletItem(pBillCoinFactory->getBillCoin(5),1)) ;
		pWallet->add(new WalletItem(pBillCoinFactory->getBillCoin(1),1)) ;
//	}
//	catch (EXCEPTION_AMOUNT)
//	{
//		cout << "Irregular" << endl ;
//	}
	cout << " Total:" << pWallet->getAmount() << "yen" << endl ;

	delete pWallet ;
	delete pBillCoinFactory ;
	return 0 ;
}
