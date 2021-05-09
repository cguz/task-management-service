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
	cout << "\nExecuting SequenceTasks. State : "<<getState()->toString()<<" ("<<getState()->getId()<<")";

	ITask* e;

	try {

		// we change the state of the sequence
		getState()->execute(this);

		// make iterate point to beginning and increment it one by one until
		// i)  it reaches the end of list or
		// ii) it changes its state
		while(!iterate->isEnd() && getState()->isRunning()) {

			// get the task to execute
			e = *(tasks_.begin()+iterate->getCurrentStepExecution());

			// executed the task if it is queued
			if (e->getState()->isQueued()){

				{
					// if the task is paused, we wait
					while(e->getState()->isPaused()){
						ITask::wait();
					}

					// change the state of the task to execute
					e->getState()->execute(e);

					// execute the task
					e->execute();

				}while(e->getState()->isPaused());

				// if the user did not cancel the task
				if (!e->getState()->isCanceled()){

					// change the state of the task to finish
					e->getState()->finish(e);

				}
			}


			// increase the current index execution
			iterate->next();

		}

		getState()->finish(this);

	} catch (...) {
		cout<< endl <<"[Error]" << endl;
	}
}

void SequenceTasks::cancel() {
	cout << "\nCancel the current task in execution.";

	ITask* e;

	try {

		// get the task in execution
		e = *(tasks_.begin()+iterate->getCurrentStepExecution());

		// change the state of the task
		e->getState()->cancel(this);

		// getState()->cancel(this);

	} catch (...) {
		cout<< endl <<"[Error]" << endl;
	}
}

void SequenceTasks::pause() {
	cout << "\nPausing the current task in execution.";

	ITask* e;

	try {

		// get the task in execution
		e = *(tasks_.begin()+iterate->getCurrentStepExecution());

		// change the state of the task
		e->getState()->pause(this);

		// pause the complete sequence
		getState()->pause(this);

	} catch (...) {
		cout<< endl <<"[Error]" << endl;
	}
}

void SequenceTasks::add(ITask* exe) {
	tasks_.push_back(exe);

	// we change the total number of steps according to the list of commands
	iterate->setTotalNumberOfSteps(tasks_.size());

	cout << "\nAdding new task to execute.";

	if (getState()->isSuccess()){

		setState(new StateQueued());
	}
}

