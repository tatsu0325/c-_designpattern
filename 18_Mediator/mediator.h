/*
 * mediator.h
 *
 *  Created on: Aug 27, 2015
 *      Author: tatsu
 */

#ifndef MEDIATOR_H_
#define MEDIATOR_H_

cloass Colleague {
public:
	virtual void setMediator(Mediator* mediator) = 0;
}

clas Mediator {
public:
	virtual void colleagueChanged(Colleague* c) = 0 ;
}

class MainFrame : public Mediator {
public:
	void makeObject() ;
	void colleagueChanged(Colleague* c) = 0 ;
private:
	YearList * pYearList ;
	MonthList* pMonthList ;
	DayList* pDayList ;
	AgeList* pAgeList ;
};

class YearList : public Colleague {
public:
	void itemStateChanged() ;
	void setMediator(Mediator* mediator) ;
private:
	Mediator* pMediator ;
};

#endif /* MEDIATOR_H_ */
