/*
 * cakefactory.h
 *
 *  Created on: Aug 29, 2015
 *      Author: tatsu
 */

#ifndef CAKEFACTORY_H_
#define CAKEFACTORY_H_

class CakeBase {
public:
	virtual void makeBase() const = 0 ;
};
class Fruit {
public:
	virtual void makeFruit() const = 0 ;
};
class Decoration {
public:
	virtual void makeDecoration() const = 0 ;
//	virtual void makeDecoration(string name) = const = 0 ;
};

class BirthdayBase : public CakeBase {
public:
	virtual void makeBase() const {
		cout << "Birthday Base" << endl ;
	}
};

class XmasBase : public CakeBase {
public:
	virtual void makeBase() const {
		cout << "Xmas Base" << endl ;
	}
};

class BirthdayFruit : public Fruit {
public:
	virtual void makeFruit() const {
		cout << "Birthday Fruit " << endl ;
	}
};

class XmasFruit : public Fruit {
public:
	virtual void makeFruit() const {
		cout << "Xmas Fruit" << endl ;
	}
};

class BirthdayDecoration : public Decoration {
public:
	virtual void makeDecoration() const {
		cout << "Birthday Decoration " << endl ;
	}
};

class XmasDecoration : public Decoration {
public:
	virtual void makeDecoration() const {
		cout << "Xmas Decoration" << endl ;
	}
};

class DecoCakeFactory {
public:
	virtual CakeBase* CreateBase() = 0 ;
	virtual Fruit* CreateFruit() = 0 ;
	virtual Decoration* CreateDecoration() = 0 ;
};

class BirthdayCakeFactory : public DecoCakeFactory {
public:
	CakeBase* CreateBase() {
		return new BirthdayBase() ;
	}
	Fruit* CreateFruit() {
		return new BirthdayFruit() ;
	}
	Decoration* CreateDecoration() {
		return new BirthdayDecoration() ;
	}
};
class XmasCakeFactory : public DecoCakeFactory {
public:
	CakeBase* CreateBase() {
		return new XmasBase() ;
	}
	Fruit* CreateFruit() {
		return new XmasFruit() ;
	}
	Decoration* CreateDecoration() {
		return new XmasDecoration() ;
	}
};

#endif /* CAKEFACTORY_H_ */
