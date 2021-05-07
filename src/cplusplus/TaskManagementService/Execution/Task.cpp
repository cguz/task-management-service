/*
 * Task.cpp
 *
 *  Created on: 07 may. 2021
 *
 *  Author: Cesar Augusto Guzman
 *  Email: cguzwork@cguz.org
 */

#include "Task.h"


Task::Task() : ITask() {

}


//################### METHODS ###################

void Task::execute() {
	cout << endl << "Executing task." << endl;
	cout << endl << " ->  call some method " << endl;

}

void Task::cancel() {
	cout << endl << "The method finish() is not implemented." << endl;
}

void Task::pause() {
	cout << endl << "The method pause() is not implemented." << endl;
}
