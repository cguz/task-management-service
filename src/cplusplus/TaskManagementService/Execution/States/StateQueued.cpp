/*
 * StateQueued.cpp
 *
 *  Created on: 07 may. 2021
 *
 *  Author: Cesar Augusto Guzman
 *  Email: cguzwork@cguz.org
 */

#pragma hdrstop

#include "StateQueued.h"
#include "StateRunning.h"
#include "StateCancelled.h"
#include "StatePaused.h"
#include "StateSuccess.h"
#include "StateFailed.h"


//########################## CONSTRUCTOR & DESTRUCTOR #########################

StateQueued::StateQueued() {
	_name = "Queue";
	_id = QUEUED;
}


//########################## METHODS TO TRANSICT #########################

void StateQueued::execute(ITask* context) {

	State* nextState = new StateRunning();
	printf("\n\n->Go to state %s\n", nextState->toString().c_str());
	context->setState(nextState);
	delete this;
}

void StateQueued::cancel(ITask* context) {

	State* nextState = new StateCancelled();
	printf("\n\n->Go to state %s\n", nextState->toString().c_str());
	context->setState(nextState);
	delete this;

}

void StateQueued::pause(ITask* context) {

	cout << "throw WrongState No possible transition from state StateQueued to Paused!\n";

}

void StateQueued::fail(ITask* context) {

	cout << "throw WrongState No possible transition from state StateQueued to Failed!\n";

}

void StateQueued::finish(ITask* context) {

	cout << "throw WrongState No possible transition from state StateQueued to Success!\n";

}

#pragma package(smart_init)
