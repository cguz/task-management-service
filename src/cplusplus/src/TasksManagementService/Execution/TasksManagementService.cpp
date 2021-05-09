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
	if (currentSequenceTask_ == -1)
		throw "The current executable id is not initialized in the TasksManagementService. Please, call the method select(Id)";
	tasksCatalog_[currentSequenceTask_]->execute();
}

void TasksManagementService::cancel() {
	if (currentSequenceTask_ == -1)
		throw "The current executable id is not initialized in the TasksManagementService. Please, call the method select(Id)";
	tasksCatalog_[currentSequenceTask_]->cancel();
}

void TasksManagementService::pause() {
	if (currentSequenceTask_ == -1)
		throw "The current executable id is not initialized in the TasksManagementService. Please, call the method select(Id)";
	tasksCatalog_[currentSequenceTask_]->pause();
}

void TasksManagementService::setSequenceTasks(short Id, ITask* executable) {

	currentSequenceTask_ = Id;

	tasksCatalog_[currentSequenceTask_] = executable;

}

bool TasksManagementService::isInitialized(short Id) {
	return tasksCatalog_[Id] != NULL;
}

void TasksManagementService::add(ITask* task){

	if (currentSequenceTask_ == -1)
		throw "The current executable id is not initialized in the TasksManagementService. Please, call the method select(Id)";
	SequenceTasks* tasks = static_cast<SequenceTasks*>(tasksCatalog_[currentSequenceTask_]);
	tasks->add(task);
}
