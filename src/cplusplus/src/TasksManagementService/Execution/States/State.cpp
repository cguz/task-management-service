/*
 * State.cpp
 *
 *  Created on: 07 may. 2021
 *
 *  Author: Cesar Augusto Guzman
 *  Email: cguzwork@cguz.org
 */

#pragma hdrstop

// Includes
// system
#include <iostream>


#include "State.h"

using namespace std;


//########################## METHODS TO TRANSICT ############################

void State::execute(ITask* context) {

	cout << "throw WrongState No possible transition from state State!\n";

}

void State::cancel(ITask* context) {

	cout << "throw WrongState No possible transition from state State!\n";

}

void State::pause(ITask* context) {

	cout << "throw WrongState No possible transition from state State!\n";

}

void State::finish(ITask* context) {

	cout << "throw WrongState No possible transition from state State!\n";

}

void State::fail(ITask* context) {

	cout << "throw WrongState No possible transition from state State!\n";

}




//################### Methods to query the current state ######################
//----------------------------------------------------------------------
// isDefined
//----------------------------------------------------------------------
bool State::isQueued()
{
	return (_id == QUEUED);
}

//----------------------------------------------------------------------
// isExecuting
//----------------------------------------------------------------------
bool State::isRunning()
{
	return (_id == RUNNING);
}

//----------------------------------------------------------------------
// isDefined
//----------------------------------------------------------------------
bool State::isPaused()
{
	return (_id == PAUSED);
}

//----------------------------------------------------------------------
// isFinished
//----------------------------------------------------------------------
bool State::isSuccess()
{
	return (_id == SUCCESS);
}

//----------------------------------------------------------------------
// isFault
//----------------------------------------------------------------------
bool State::isFailed()
{
	return (_id == FAILED);
}

//----------------------------------------------------------------------
// isCanceled
//----------------------------------------------------------------------
bool State::isCanceled(){
	return (_id == CANCELLED);
}


//########################## GETTERS ############################

string State::toString() {
	return _name;
}

int State::getId() {
	return _id;
}


#pragma package(smart_init)
