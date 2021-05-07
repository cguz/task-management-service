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


	SequenceIterator* iterate = new SequenceIterator();

	SequenceTasks* sequence = new SequenceTasks("TasksGroup2", iterate);

	sequence->add(new Task());
	sequence->add(new Task());

	return sequence;

}
