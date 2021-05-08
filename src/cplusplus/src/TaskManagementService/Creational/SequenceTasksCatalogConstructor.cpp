/*
 * SequenceTasksConstructor.cpp
 *
 *  Created on: 07 may. 2021
 *
 *  Author: Cesar Augusto Guzman
 *  Email: cguzwork@cguz.org
 */
#include "SequenceTasksCatalogConstructor.h"

#include "Factories/TasksGroup1Factory.h"
#include "Factories/TasksGroup2Factory.h"


//################### CONSTRUCTOR ###################

SequenceTasksCatalogConstructor::SequenceTasksCatalogConstructor() {

	// Initialize the SequenceTasksConstructor
	init();

}

SequenceTasksCatalogConstructor::~SequenceTasksCatalogConstructor() {
	cout<< "\nDestructor of the class SequenceTasksCatalogConstructor";
}




//################### METHODS ###################

void SequenceTasksCatalogConstructor::init(){

	cout<< "\nInit of the class SequenceTasksCatalogConstructor";

	sequenceTasksFactoryCatalog[SEQ_TASKS_GROUP1] = new TasksGroup1Factory();
	sequenceTasksFactoryCatalog[SEQ_TASKS_GROUP2] = new TasksGroup2Factory();

}



ITask* SequenceTasksCatalogConstructor::build(short Id) {
	return getFactory_(Id)->build();
}

vector<int> SequenceTasksCatalogConstructor::getSequenceIds() {

	vector<int> ids;
	ids.reserve(sequenceTasksFactoryCatalog.size());

	for(auto kv : sequenceTasksFactoryCatalog) {
	    ids.push_back(kv.first);
	}

	return ids;

}


SequenceTasksFactory* SequenceTasksCatalogConstructor::getFactory_(short seqId) {

	return sequenceTasksFactoryCatalog[seqId];

}

