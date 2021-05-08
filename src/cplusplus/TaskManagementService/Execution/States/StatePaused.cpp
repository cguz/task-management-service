/*
 * StatePaused.cpp
 *
 *  Created on: 07 may. 2021
 *
 *  Author: Cesar Augusto Guzman
 *  Email: cguzwork@cguz.org
 */

#pragma hdrstop

#include "StatePaused.h"
#include "StateCancelled.h"
#include "StateRunning.h"


//########################## CONSTRUCTOR & DESTRUCTOR #########################

StatePaused::StatePaused() {
	_name = "Paused";
	_id = PAUSED;
}


//########################## METHODS TO TRANSICT #########################

void StatePaused::pause(ITask* context) {

	cout << "\nThe component is already in the state "<<_name<<"!\n";

}

void StatePaused::cancel(ITask* context) {

	State* nextState = new StateCancelled();
	printf("\n->Go to state %s\n", nextState->toString().c_str());
	context->setState(nextState);
	delete this;

}

void StatePaused::execute(ITask* context) {

	State* nextState = new StateRunning();
	printf("\n->Go to state %s\n", nextState->toString().c_str());
	context->setState(nextState);
	delete this;

}

void StatePaused::fail(ITask* context) {

	cout << "throw WrongState No possible transition from StatePaused to Failed!\n";

}

void StatePaused::finish(ITask* context) {

	cout << "throw WrongState No possible transition from StatePaused to Success!\n";

}

#pragma package(smart_init)
