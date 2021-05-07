/*
 * SequenceTasks.h
 *
 *  Created on: 07 may. 2021
 *
 *  Author: Cesar Augusto Guzman
 *  Email: cguzwork@cguz.org
 */

#ifndef SEQUENCETASKS_H_
#define SEQUENCETASKS_H_

#include <iostream>
#include <vector>
#include "SequenceIterator.h"
#include "ITask.h"
#include "StateDesign/State.h"

using namespace std;

/**
 * Composite of leaf tasks to execute
 */
class SequenceTasks : public ITask {

	public:

		//################### CONSTRUCTOR ###################

		SequenceTasks(string name, SequenceIterator* iterate);

		virtual ~SequenceTasks();


		//########################## GETTERS AND SETTERS ############################

		/**
		* Update the current state
		*/
		void setState(State* state);

		/**
		* Retrieve the current state
		*/
		State* getState();


		//################### METHODS ###################


		void 	execute();
		void 	cancel();
		void 	pause();


		/**
		 * Retrieve the sequence as a string
		 */
		string 	getParameters();

		/**
		 * Add an Task to the sequence
		 *
		 * @param ITask to execute
		 */
		void 	add(ITask* exe);


	protected:

		// current state of the Sequence
		State* state;

		// class to iterate through the tasks of a sequence
		SequenceIterator* iterate;

	private:

		// list of tasks or sequence of tasks to execute
		vector <ITask*> tasksList_;

};

#endif /* SEQUENCETASKS_H_ */
