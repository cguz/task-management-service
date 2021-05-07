/*
 * TasksGroup1Factory.cpp
 *
 *  Created on: 07 may. 2021
 *
 *  Author: Cesar Augusto Guzman
 *  Email: cguzwork@cguz.org
 */

#include "TasksGroup1Factory.h"


//################### CONSTRUCTOR ###################

TasksGroup1Factory::TasksGroup1Factory() {
	cout << "\nConstructor TasksGroup1Factory";
}

TasksGroup1Factory::~TasksGroup1Factory() {
	cout << "\nDestructor of the class TasksGroup1Factory";
}


//################### METHODS ###################

ITask* TasksGroup1Factory::build() {

	cout << "\n class TasksGroup1Factory::build()"<<endl;
	cout << "\t  - it contains only one Task"<<endl;

	ITask* task = new Task();

	return task;

}
