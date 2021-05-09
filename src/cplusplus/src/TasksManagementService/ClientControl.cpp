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
	catalogConstructor_ = catalogConstructor;
	tasksManagement_ = new TasksManagementService();

}

ClientControl::~ClientControl() {

	cout << "\nDestructor of the class Control";
	delete catalogConstructor_;
	delete tasksManagement_;

}


//################### METHODS ###################s

void ClientControl::build() {

	for(int seqId : getSequenceIds()) {
		catalogConstructor_->build(seqId);
	}

}

void ClientControl::select(short Id) {

	if(!tasksManagement_->isInitialized(Id)) {
		tasksManagement_->setSequenceTasks(Id, catalogConstructor_->build(Id));
	}

}

void ClientControl::add(ITask* task){
	tasksManagement_->add(task);
}

void ClientControl::execute() {
	tasksManagement_->execute();
}

void ClientControl::cancel() {
	tasksManagement_->cancel();
}

void ClientControl::pause() {
	tasksManagement_->pause();
}


vector<int> ClientControl::getSequenceIds(){
	return catalogConstructor_->getSequenceIds();
}
