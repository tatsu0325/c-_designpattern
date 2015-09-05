/*
 * proxy.h
 *
 *  Created on: Aug 26, 2015
 *      Author: tatsu
 */

#ifndef PROXY_H_
#define PROXY_H_

class SaleData {
public:
	string getDate() ;
	int getId() ;
	void setDate(string date) ;
	void setId(int id) ;
private:
	int id ;
	string date;
};

class ItemData {
public:
	int getId() ;
	void setId(int id) ;
	string getName() ;
	void setName(string name) ;
	int getUnitPrice() ;
	void setUnitPrice(int unitPrice) ;
	int getQuantity() ;
	void setQuantity(int quantity) ;
private:
	int id ;
	string name ;
	int unitPrice ;
	int quantity ;
};

class DataBase {
public:
	virtual void initDB() = 0 ;
	virtual void closeDB() = 0 ;
	virtual void insert_SaleData(SaleData* storedSale) = 0 ;
	virtual SaleData * getSaleData(int id) = 0 ;
	virtual void delete_SaleData(SaleData* storedSale) = 0 ;
	virtual void insert_ItemData(ItemData* storedSale) = 0 ;
	virtual list<ItemData*>* getItemsForSale(int id)=0 ;
	virtual void delete_ItemData(ItemData* storedSale) =0 ;
	virtual list<SaleData*>* getSalesByDate(string date)=0 ;
};

class ProxyDB : public DataBase {
public:
	ProxyDB() ;
	~ProxyDB() ;
	void setReal(bool b) ;
	virtual void initDB() = 0 ;
	virtual void closeDB() = 0 ;
	virtual void insert_SaleData(SaleData* storedSale) = 0 ;
	virtual SaleData * getSaleData(int id) = 0 ;
	virtual void delete_SaleData(SaleData* storedSale) = 0 ;
	virtual void insert_ItemData(ItemData* storedSale) = 0 ;
	virtual list<ItemData*>* getItemsForSale(int id)=0 ;
	virtual void delete_ItemData(ItemData* storedSale) =0 ;
	virtual list<SaleData*>* getSalesByDate(string date)=0 ;
private:
	bool isReal() ;
	DataBase* db ;
	bool real ;
};

class MockDB : public DataBase {
public:
	virtual void initDB() = 0 ;
	virtual void closeDB() = 0 ;
	virtual void insert_SaleData(SaleData* storedSale) = 0 ;
	virtual SaleData * getSaleData(int id) = 0 ;
	virtual void delete_SaleData(SaleData* storedSale) = 0 ;
	virtual void insert_ItemData(ItemData* storedSale) = 0 ;
	virtual list<ItemData*>* getItemsForSale(int id)=0 ;
	virtual void delete_ItemData(ItemData* storedSale) =0 ;
	virtual list<SaleData*>* getSalesByDate(string date)=0 ;
private:
	bool isReal() ;
	list<SaleData *> * sales ;
	list<ItemData *> * items ;

};


#endif /* PROXY_H_ */
