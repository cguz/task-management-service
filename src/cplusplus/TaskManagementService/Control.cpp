/*
 * Control.cpp
 *
 *  Created on: 07 may. 2021
 *
 *  Author: Cesar Augusto Guzman
 *  Email: cguzwork@cguz.org
 */

#include "Control.h"


//################### CONSTRUCTOR ###################

Control::Control(SequenceTasksCatalogConstructor* catalogConstructor) {

	cout << "\n\nConstructor Control";
	_catalogConstructor = catalogConstructor;
	_tasksManagement = new TasksManagementService();

}

Control::~Control() {
	cout << "Destructor of the class Control";
}


//################### METHODS ###################s

void Control::build() {

	for(int seqId : getSequenceIds()) {
		_catalogConstructor->build(seqId);
	}

}

void Control::select(short seqId) {

	if(!_tasksManagement->isInitialized(seqId)) {
		_tasksManagement->setSequence(seqId, _catalogConstructor->build(seqId));
	}

}

void Control::execute() {
	_tasksManagement->execute();
}

void Control::cancel() {
	_tasksManagement->cancel();
}

void Control::pause() {
	_tasksManagement->pause();
}


vector<int> Control::getSequenceIds(){
	return _catalogConstructor->getSequenceIds();
}
