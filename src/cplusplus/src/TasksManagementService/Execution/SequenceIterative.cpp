/*
 * IterativeSequence.cpp
 *
 *  Created on: 07 may. 2021
 *
 *  Author: Cesar Augusto Guzman
 *  Email: cguzwork@cguz.org
 */
#include "SequenceIterative.h"



//################### CONSTRUCTOR ###################

SequenceIterative::SequenceIterative(const string& name, ControlIterator* iterate)
	: SequenceTasks(name, iterate) {

}

SequenceIterative::~SequenceIterative() {
	cout<< "\nDestructor of the class IterativeSequence";
}




//################### METHODS ###################

void SequenceIterative::execute() {

	cout << "\nExecuting sequence.";

	ITask* e;

	try {

		do {

			// execute the sequence
			SequenceTasks::execute();

			if(getState()->isRunning()) {

				// default values of the sequence
				iterate->begin();

				// increase the current index of the repetition
				iterate->nextIteration();

			}

		// consider if the sequence needs to be repeated
		} while(!iterate->isEndIterations() && getState()->isRunning());


	} catch (...) {
		cout<< endl <<"[Error]" << endl;
	}

}
