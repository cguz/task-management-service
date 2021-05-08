/*
 * TaskManagementService.cpp
 *
 *  Created on: 07 may. 2021
 *
 *  Author: Cesar Augusto Guzman
 *  Email: cguzwork@cguz.org
 */
#include "TasksManagementService.h"


//################### CONSTRUCTOR ###################

TasksManagementService::TasksManagementService() {
}

TasksManagementService::~TasksManagementService() {
	cout << "Destructor of the class TasksManagementService";
}


//################### METHODS ###################

void TasksManagementService::execute() {
	if (_currentSequenceTask == -1)
		throw "The current executable id is not initialized in the TasksManagementService. Please, call the method select(Id)";
	_tasksCatalog[_currentSequenceTask]->execute();
}

void TasksManagementService::cancel() {
	if (_currentSequenceTask == -1)
		throw "The current executable id is not initialized in the TasksManagementService. Please, call the method select(Id)";
	_tasksCatalog[_currentSequenceTask]->cancel();
}

void TasksManagementService::pause() {
	if (_currentSequenceTask == -1)
		throw "The current executable id is not initialized in the TasksManagementService. Please, call the method select(Id)";
	_tasksCatalog[_currentSequenceTask]->pause();
}

void TasksManagementService::setSequenceTasks(short Id, ITask* executable) {

	_currentSequenceTask = Id;

	_tasksCatalog[_currentSequenceTask] = executable;

}

bool TasksManagementService::isInitialized(short Id) {
	return _tasksCatalog[Id] != NULL;
}

void TasksManagementService::add(ITask* task){

	if (_currentSequenceTask == -1)
		throw "The current executable id is not initialized in the TasksManagementService. Please, call the method select(Id)";
	SequenceTasks* tasks = (SequenceTasks*) _tasksCatalog[_currentSequenceTask];
	tasks->add(task);
}
