/*
 * SequenceTasks.cpp
 *
 *  Created on: 07 may. 2021
 *
 *  Author: Cesar Augusto Guzman
 *  Email: cguzwork@cguz.org
 */

#include "SequenceTasks.h"

#include "StateDesign/StateQueued.h"
#include "StateDesign/StateRunning.h"



//################### CONSTRUCTOR ###################

// the constructor also creates the variable to iterate through the tasks in the sequence of tasks
SequenceTasks::SequenceTasks(string name, SequenceIterator* ite) : ITask(), iterate(ite) {

	// Sequence iterator
	// NOTE This should be always a difference instance for a Sequence of tasks
	iterate->begin();

	// update the name of the sequence
	setName(name);

	// initialize the state variable
	setState(new StateRunning());
}

SequenceTasks::~SequenceTasks() {
	cout<< "\nDestructor of the class SequenceTasks";
}


//########################## GETTERS AND SETTERS #######################################
//----------------------------------------------------------------------
// Change the current state
//----------------------------------------------------------------------
void SequenceTasks::setState ( State* state) {

	this->state = state;

}

//----------------------------------------------------------------------
// Retrieve the current state
//----------------------------------------------------------------------
State* SequenceTasks::getState( ) {

	return state;

}



//################### METHODS ###################

void SequenceTasks::execute() {
	cout << "\nExecuting SequenceTasks. State : "<<getState()->getId();

	ITask* e;

	try {

		// we change the state of the sequence
		getState()->execute(this);

		// make iterate point to beginning and increment it one by one untill
		// i)  it reaches the end of list or
		// ii) it changes its state
		while(!iterate->isEnd() && getState()->isRunning()) {

			// get the command to execute
			e = *(tasksList_.begin()+iterate->getCurrentStepExecution());

			// execute the command
			e->execute();

			// increase the current index execution
			iterate->next();

		}

		// finish();

	} catch (...) {
		cout<< endl <<"[Error]" << endl;
	}
}

void SequenceTasks::cancel() {
	cout << "\nAborting SequenceTasks.";

	try {

		getState()->fail(this);

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

string SequenceTasks::getParameters() {
	return "get parameters of a normal SequenceTasks";
}

void SequenceTasks::add(ITask* exe) {
	tasksList_.push_back(exe);

	// we change the total number of steps according to the list of commands
	iterate->setTotalNumberOfSteps(tasksList_.size());
}

