/*
 * observer.h
 *
 *  Created on: Aug 30, 2015
 *      Author: tatsu
 */

#ifndef OBSERVER_H_
#define OBSERVER_H_

class ColorInfo {
public:
	void attach(Observer* observer) ;
private:
	list<Observer*> observers ;
};

class ColrPresentation : public



#endif /* OBSERVER_H_ */
