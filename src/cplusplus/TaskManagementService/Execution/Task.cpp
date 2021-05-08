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
	srand (31173);
}


//################### METHODS ###################

void Task::execute() {

	cout << endl << "Executing a general task." << endl;

	simulateDuration();
}

void Task::simulateDuration(){

	unsigned int microsecond = 1000000;
	int duration = rand() % 5;

	cout << endl << " ->  duration : " << duration << " seconds" << endl;

	usleep(duration * microsecond);

}

bool Task::simulateFailure(){

	unsigned int microsecond = 1000000;
	int failure = rand() % 100;

	return (failure <= 5)? true: false;

}

void Task::cancel() {
	cout << endl << "The method finish() is not implemented." << endl;
}

void Task::pause() {
	cout << endl << "The method pause() is not implemented." << endl;
}

