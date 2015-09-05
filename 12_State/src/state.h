/*
 * state.h
 *
 *  Created on: Aug 26, 2015
 *      Author: tatsu
 */

#ifndef STATE_H_
#define STATE_H_
/*
**State.h
*/
// EngineBox ////////////////////////////////////////////////////////

class EngineState;

class EngineBox
{
public:
	EngineBox();
	~EngineBox();

	void up();
	void down();
	void changeState( EngineState* newState );
	void nowState();
private:
	EngineState* state;
};

// EngineState //////////////////////////////////////////////////////
class EngineState
{
public:
	virtual void up( EngineBox* pEBox )		= 0;
	virtual void down( EngineBox* pEBox )	= 0;
	virtual void showCurrentState()			= 0;
};

// EngineIdle ///////////////////////////////////////////////////////
class EngineIdle : public EngineState
{
public:
	void up( EngineBox* pEBox );
	void down( EngineBox* pEBox );
	void showCurrentState();
};

// EngineRunningLow /////////////////////////////////////////////////
class EngineRunningLow : public EngineState
{
public:
	void up( EngineBox* pEBox );
	void down( EngineBox* pEBox );
	void showCurrentState();
};

// EngineRunningHigh ////////////////////////////////////////////////
class EngineRunningHigh : public EngineState
{
public:
	void up( EngineBox* pEBox );
	void down( EngineBox* pEBox );
	void showCurrentState();
};
#endif /* STATE_H_ */
