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

void StateQueued::execute(SequenceTasks* context) {

	State* nextState = new StateRunning();
	printf("\n\n->Go to state %s\n", nextState->toString().c_str());
	context->setState(nextState);
	delete this;
}

void StateQueued::cancel(SequenceTasks* context) {

	State* nextState = new StateCancelled();
	printf("\n\n->Go to state %s\n", nextState->toString().c_str());
	context->setState(nextState);
	delete this;

}

void StateQueued::pause(SequenceTasks* context) {

	cout << "throw WrongState No possible transition!\n";

}

void StateQueued::fail(SequenceTasks* context) {

	cout << "throw WrongState No possible transition!\n";

}

void StateQueued::finish(SequenceTasks* context) {

	cout << "throw WrongState No possible transition!\n";

}

#pragma package(smart_init)
