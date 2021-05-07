/*
 * SequenceTasks.cpp
 *
 *  Created on: 07 may. 2021
 *
 *  Author: Cesar Augusto Guzman
 *  Email: cguzwork@cguz.org
 */

#include "SequenceTasks.h"



//################### CONSTRUCTOR ###################

// the constructor also creates the variable to iterate through the tasks in the sequence of tasks
SequenceTasks::SequenceTasks(string name, ControlIterator* ite) : ITask(), iterate(ite) {

	// Sequence iterator
	// NOTE This should be always a difference instance for a Sequence of tasks
	iterate->begin();

	// update the name of the sequence
	setName(name);
}

SequenceTasks::~SequenceTasks() {
	cout<< "\nDestructor of the class SequenceTasks";
}




//################### METHODS ###################

void SequenceTasks::execute() {
	cout << "\nExecuting SequenceTasks. State : "<<getState()->toString()<<" ("<<getState()->getId()<<")";

	ITask* e;

	try {

		// we change the state of the sequence
		getState()->execute(this);

		// make iterate point to beginning and increment it one by one until
		// i)  it reaches the end of list or
		// ii) it changes its state
		while(!iterate->isEnd() && getState()->isRunning()) {

			// get the command to execute
			e = *(_tasks.begin()+iterate->getCurrentStepExecution());

			// execute the command
			e->execute();

			// increase the current index execution
			iterate->next();

		}

		getState()->finish(this);

	} catch (...) {
		cout<< endl <<"[Error]" << endl;
	}
}

void SequenceTasks::cancel() {
	cout << "\nCancel the SequenceTasks.";

	try {

		getState()->cancel(this);

	} catch (...) {
		cout<< endl <<"[Error]" << endl;
	}
}

void SequenceTasks::pause() {
	cout << "\nPausing SequenceTasks.";
	try {

		getState()->pause(this);

	} catch (...) {
		cout<< endl <<"[Error]" << endl;
	}
}

void SequenceTasks::add(ITask* exe) {
	_tasks.push_back(exe);

	// we change the total number of steps according to the list of commands
	iterate->setTotalNumberOfSteps(_tasks.size());
}

