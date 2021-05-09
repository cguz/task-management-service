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

	try {

		// we change the state of the sequence
		getState()->execute(this);

		// make iterate point to beginning and increment it one by one until
		// i)  it reaches the end of list or
		// ii) it changes its state
		while(!iterate->isEnd() && getState()->isRunning()) {

			// get the task to execute
			ITask* task = *(tasks_.begin()+iterate->getCurrentStepExecution());

			// executed the task if it is queued
			if (task->getState()->isQueued()){

				{
					// if the task is paused, we wait
					while(task->getState()->isPaused()){
						ITask::wait();
					}

					// change the state of the task to execute
					task->getState()->execute(task);

					// execute the task
					task->execute();

				}while(task->getState()->isPaused());

				// if the user did not cancel the task
				if (!task->getState()->isCanceled()){

					// change the state of the task to finish
					task->getState()->finish(task);

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

	try {

		// get the task in execution
		ITask* task = *(tasks_.begin()+iterate->getCurrentStepExecution());

		// change the state of the task
		task->getState()->cancel(this);

		// getState()->cancel(this);

	} catch (...) {
		cout<< endl <<"[Error]" << endl;
	}
}

void SequenceTasks::pause() {
	cout << "\nPausing the current task in execution.";

	try {

		// get the task in execution
		ITask* e = *(tasks_.begin()+iterate->getCurrentStepExecution());

		// change the state of the task
		e->getState()->pause(this);

		// pause the complete sequence
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

