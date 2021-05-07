/*
 * ClientControl.cpp
 *
 *  Created on: 07 may. 2021
 *
 *  Author: Cesar Augusto Guzman
 *  Email: cguzwork@cguz.org
 */

#include "ClientControl.h"


//################### CONSTRUCTOR ###################

ClientControl::ClientControl(SequenceTasksCatalogConstructor* catalogConstructor) {

	cout << "\n\nConstructor Control";
	_catalogConstructor = catalogConstructor;
	_tasksManagement = new TasksManagementService();

}

ClientControl::~ClientControl() {
	cout << "Destructor of the class Control";
}


//################### METHODS ###################s

void ClientControl::build() {

	for(int seqId : getSequenceIds()) {
		_catalogConstructor->build(seqId);
	}

}

void ClientControl::select(short Id) {

	if(!_tasksManagement->isInitialized(Id)) {
		_tasksManagement->setSequence(Id, _catalogConstructor->build(Id));
	}

}

void ClientControl::execute() {
	_tasksManagement->execute();
}

void ClientControl::cancel() {
	_tasksManagement->cancel();
}

void ClientControl::pause() {
	_tasksManagement->pause();
}


vector<int> ClientControl::getSequenceIds(){
	return _catalogConstructor->getSequenceIds();
}
