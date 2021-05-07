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
	cout << "Destructor of the class SequenceExecutor";
}


//################### METHODS ###################

void TasksManagementService::execute() {
	if (currentExecutable == -1)
		throw "The current executable id is not initialized in the SequenceExecutor. Please, call the method select(seqId)";
	executableCatalog[currentExecutable]->execute();
}

void TasksManagementService::cancel() {
	if (currentExecutable == -1)
		throw "The current executable is not initialized, please, call the method select(seqId)";
	executableCatalog[currentExecutable]->cancel();
}

void TasksManagementService::resume() {
	if (currentExecutable == -1)
		throw "The current executable is not initialized, please, call the method select(seqId)";
	executableCatalog[currentExecutable]->resume();
}

void TasksManagementService::pause() {
	if (currentExecutable == -1)
		throw "The current executable is not initialized, please, call the method select(seqId)";
	executableCatalog[currentExecutable]->pause();
}

void TasksManagementService::setSequence(short seqId, ITask* executable) {

	currentExecutable = seqId;

	executableCatalog[currentExecutable] = executable;

}

bool TasksManagementService::isInitialized(short seqId) {
	return executableCatalog[seqId] != NULL;
}
