/*
 * proxy.cpp
 *
 *  Created on: Aug 26, 2015
 *      Author: tatsu
 */
#include <list>
#include <string>
using namespace std ;

#include "proxy.h"

string SaleData::getDate() { return date; }
int SaleData::getId() { return id ; }
void SaleData::setDate(string date) { this->date = date ; }
void SaleData::setId(int id) { this->id = id ; }

int ItemData::getId() { return id ; }
void ItemData::setId(int id) { this->id = id ; }
string ItemData::getName() { return name ; }
void ItemData::setName(string name) { this->name = name ; }
int ItemData::getUnitPrice() { return unitPrice ; }
void ItemData::setUnitPrice(int unitPrice) { this->unitPrice = unitPrice ; }
int ItemData::getQuantity() { return quantity ; }
void ItemData::setQuantity(int quantity) { this->quantity = quantity ; }

long getSalesAmountByDate(DataBase* db , string date) {
	long result = 0 ;

	list<SaleData*>* sales = db->getSalesByDate(date) ;
	list<SaleData*>::iterator itSale = sales->begin() ;
	while(itSale != sales->end()) {
		SaleData * sale = (*itSale++) ;
		list<ItemData*>* items = db->getItemsForSale(sale->getId()) ;
		list<ItemData*>::iterator itItem = items->begin() ;
		while(itItem != items->end()) {
			ItemData* item = (*itItem++) ;
			result += item->getUnitPrice() * item->getQuantity() ;
		}
	}
	return result ;
}

void MockDB::initDB() {
	sales = new list<SaleData*>  ;
	items = new list<ItemData*> ;
}
void MockDB::closeDB() {

	delete sales ;
	delete items ;
}
ProxyDB::ProxyDB() {
	real = false ;
	if(isReal()) db = new RealDB() ;
	else         db = new MockDB() ;
}
ProxyDB::~ProxyDB(){ delete db; }
void ProxyDB::setReal(bool b) { real = b ;}
bool ProxyDB::isReal() { return real ;}
void ProxyDB::initDB() { db->initDB() ; }
void ProxyDB::closeDB() { db->closeDB() ; }
void ProxyDB::insert_SaleData(SaleData* storedSale) { db->insert_SaleData(storedData) ; }
SaleData * ProxyDB::getSaleData(int id) { return db->getSaleData(id) ; }
void ProxyDB::delete_SaleData(SaleData* storedSale) { db->delete_SaleData(storedData) ; }
void ProxyDB::insert_ItemData(ItemData* storedSale)  { db->insert_SaleData(storedData) ; }
list<ItemData*>* ProxyDB::getItemsForSale(int id)   { return db->getItemForSale(id) ; }
void ProxyDB::delete_ItemData(ItemData* storedSale)   { db->delete_ItemData(storedData) ; }
list<SaleData*>* ProxyDB::getSalesByDate(string date)   { return db->getSaleByDate(date) ; }


