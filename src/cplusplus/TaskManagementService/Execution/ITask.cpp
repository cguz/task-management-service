/*
 * ITask.cpp
 *
 *  Created on: 07 may. 2021
 *
 *  Author: Cesar Augusto Guzman
 *  Email: cguzwork@cguz.org
 */

#include "ITask.h"

#include "States/StateQueued.h"
#include "States/StateRunning.h"


//################### CONSTRUCTOR ###################

ITask::ITask(){

	// initialize the state variable
	setState(new StateRunning());
}

ITask::~ITask() {
	cout<< "\nDestructor of the class ITask";
}


//########################## GETTERS AND SETTERS #######################################
void ITask::setState ( State* state) {

	this->state = state;

}

State* ITask::getState( ) {

	return state;

}

void ITask::setName(string name) {
	name_ = name;
}

string ITask::getName() {
	return name_;
}


string ITask::toString() {
	cout << "Please override the method toString() in " << name_;
	return name_;
}

