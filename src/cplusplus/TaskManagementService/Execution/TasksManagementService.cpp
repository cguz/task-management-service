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
	if (_currentTask == -1)
		throw "The current executable id is not initialized in the TasksManagementService. Please, call the method select(Id)";
	_tasksCatalog[_currentTask]->execute();
}

void TasksManagementService::cancel() {
	if (_currentTask == -1)
		throw "The current executable id is not initialized in the TasksManagementService. Please, call the method select(Id)";
	_tasksCatalog[_currentTask]->cancel();
}

void TasksManagementService::pause() {
	if (_currentTask == -1)
		throw "The current executable id is not initialized in the TasksManagementService. Please, call the method select(Id)";
	_tasksCatalog[_currentTask]->pause();
}

void TasksManagementService::setSequence(short seqId, ITask* executable) {

	_currentTask = seqId;

	_tasksCatalog[_currentTask] = executable;

}

bool TasksManagementService::isInitialized(short seqId) {
	return _tasksCatalog[seqId] != NULL;
}
