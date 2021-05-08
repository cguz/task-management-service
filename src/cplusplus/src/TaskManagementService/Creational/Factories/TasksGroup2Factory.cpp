/*
 * TasksGroup2Factory.cpp
 *
 *  Created on: 07 may. 2021
 *
 *  Author: Cesar Augusto Guzman
 *  Email: cguzwork@cguz.org
 */
#include "TasksGroup2Factory.h"


//################### CONSTRUCTOR ###################

TasksGroup2Factory::TasksGroup2Factory() {
	cout << "\nConstructor TasksGroup2Factory";
}


TasksGroup2Factory::~TasksGroup2Factory() {
	cout << "\nDestructor of the class TasksGroup2Factorys";
}


//################### METHODS ###################

ITask* TasksGroup2Factory::build() {

	cout << "\nTasksGroup2Factory::build()";
	cout << "\t - contains two Tasks"<<endl;


	// the aim is twofold: 1) allow us to control the execution of the tasks and 2) allows to iterate one or more times the sequence tasks
	ControlIterator* iterate = new ControlIterator();

	SequenceTasks* sequence = new SequenceTasks("TasksGroup2", iterate);

	sequence->add(new Task());
	sequence->add(new Task());

	return sequence;

}
