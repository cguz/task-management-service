/*
 * ITask.cpp
 *
 *  Created on: 07 may. 2021
 *
 *  Author: Cesar Augusto Guzman
 *  Email: cguzwork@cguz.org
 */

#include "ITask.h"


//################### CONSTRUCTOR ###################

ITask::ITask(){
}

ITask::~ITask() {
	cout<< "\nDestructor of the class ITask";
}


//################### METHODS ###################

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

