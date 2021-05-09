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
SequenceTasks::SequenceTasks(const string& name, ControlIterator* ite) : ITask(), iterate(ite) {

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

	if (getState()->isPaused()){

		cout << "\nResume SequenceTasks. State : "<<getState()->toString()<<" ("<<getState()->getId()<<")";

		getState()->execute(this);

	}else{

		cout << "\nExecuting SequenceTasks. State : "<<getState()->toString()<<" ("<<getState()->getId()<<")";

		try {

			// we change the state of the sequence
			getState()->execute(this);

			// make iterate point to beginning and increment it one by one until
			// i)  it reaches the end of list or
			// ii) it changes its state
			while(!iterate->isEnd() && getState()->isRunning()) {

				// get the task to execute
				ITask* task = *(tasks_.begin()+iterate->getCurrentStepExecution());

				// execute the task
				task->execute();

				// increase the current index execution
				iterate->next();

				// while the state is pause, we wait
				while(getState()->isPaused()){}
			}

			if (getState()->isRunning())
				getState()->finish(this);

		} catch (...) {
			cout<< endl <<"[Error]" << endl;
		}
	}
}

void SequenceTasks::cancel() {
	cout << "\nCancel the current execution.";

	try {

		// cancel the complete sequence tasks
		getState()->pause(this);

		getState()->cancel(this);

	} catch (...) {
		cout<< endl <<"[Error]" << endl;
	}
}

void SequenceTasks::pause() {
	cout << "\nPausing the current task in execution.";

	try {

		// pause the complete sequence tasks
		getState()->pause(this);

	} catch (...) {
		cout<< endl <<"[Error]" << endl;
	}
}

void SequenceTasks::add(ITask* task) {
	tasks_.push_back(task);

	// we change the total number of steps according to the list of commands
	iterate->setTotalNumberOfSteps(tasks_.size());

	cout << "\nAdding new task to execute.";

	if (getState()->isSuccess()){

		setState(new StateQueued());
	}
}

