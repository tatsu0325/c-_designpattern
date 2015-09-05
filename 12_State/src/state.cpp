/*
 * state.cpp
 *
 *  Created on: Aug 26, 2015
 *      Author: tatsu
 */
/*
**State.cpp
*/
#include "state.h"
#include <iostream>
using namespace std;

/////////////////////////////////////////////////////////////////////
// EngineBox ////////////////////////////////////////////////////////
EngineBox::EngineBox()
{
	state = new EngineIdle();
}

EngineBox::~EngineBox()
{
	delete state;
}

void EngineBox::up()
{
	state->up( this );
}

void EngineBox::down()
{
	state->down( this );
}

void EngineBox::changeState( EngineState* newState )
{
	delete state;
	state = newState;
}

void EngineBox::nowState()
{
	state->showCurrentState();
}

/////////////////////////////////////////////////////////////////////
// EngineIdle ///////////////////////////////////////////////////////
void EngineIdle::up( EngineBox *pEBox )
{
	cout << "Idle -> Low" << endl;
	pEBox->changeState( new EngineRunningLow() );
}

void EngineIdle::down( EngineBox *pEBox )
{
	cout << "No Change" << endl;
	pEBox->changeState( new EngineIdle() );
}

void EngineIdle::showCurrentState()
{
	cout << "State:Idle" << endl;
}

/////////////////////////////////////////////////////////////////////
// EngineRunningLow /////////////////////////////////////////////////
void EngineRunningLow::up( EngineBox *pEBox )
{
	cout << "Low -> High" << endl;
	pEBox->changeState( new EngineRunningHigh() );
}

void EngineRunningLow::down( EngineBox *pEBox )
{
	cout << "Low -> Idle" << endl;
	pEBox->changeState( new EngineIdle() );
}

void EngineRunningLow::showCurrentState()
{
	cout << "State:Low" << endl;
}

/////////////////////////////////////////////////////////////////////
// EngineRunningHigh ////////////////////////////////////////////////
void EngineRunningHigh::up( EngineBox *pEBox )
{
	cout << "No Change" << endl;
	pEBox->changeState( new EngineRunningHigh() );
}

void EngineRunningHigh::down( EngineBox *pEBox )
{
	cout << "High -> Low" << endl;
	pEBox->changeState( new EngineRunningLow() );
}

void EngineRunningHigh::showCurrentState()
{
	cout << "State:High" << endl;
}

/////////////////////////////////////////////////////////////////////
// main /////////////////////////////////////////////////////////////
int main()
{
	EngineBox *pEBox = new EngineBox();

	pEBox->up();
	pEBox->nowState();

	pEBox->up();
	pEBox->nowState();

	pEBox->down();
	pEBox->nowState();
}


