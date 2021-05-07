/*
 * StateRunning.cpp
 *
 *  Created on: 07 may. 2021
 *
 *  Author: Cesar Augusto Guzman
 *  Email: cguzwork@cguz.org
 */

#pragma hdrstop

#include "StateRunning.h"
#include "StateCancelled.h"
#include "StatePaused.h"
#include "StateSuccess.h"
#include "StateFailed.h"


//########################## CONSTRUCTOR & DESTRUCTOR #########################

StateRunning::StateRunning() {
	_name = "Running";
	_id = RUNNING;
}


//########################## METHODS TO TRANSICT #########################



void StateRunning::execute(SequenceTasks* context) {

	cout << "\nThe component is already in the state "<<_name<<"!\n";

}

void StateRunning::cancel(SequenceTasks* context) {

	cout << "throw WrongState No possible transition!\n";

}

void StateRunning::finish(SequenceTasks* context) {

	State* nextState = new StateSuccess();
	printf("\n\n->Go to state %s\n", nextState->toString().c_str());
	context->setState(nextState);
	delete this;

}

void StateRunning::pause(SequenceTasks* context) {

	State* nextState = new StatePaused();
	printf("\n\n-> go to state %s\n", nextState->toString().c_str());
	context->setState(nextState);
	delete this;

}

void StateRunning::fail(SequenceTasks* context) {

	State* nextState = new StateFailed();
	printf("\n->Go to state %s\n", nextState->toString().c_str());
	context->setState(nextState);
	delete this;

}

#pragma package(smart_init)
