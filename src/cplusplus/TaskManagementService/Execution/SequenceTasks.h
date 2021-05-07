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

#include "ControlIterator.h"
#include "ITask.h"

using namespace std;

/**
 * Composite of leaf tasks to execute
 */
class SequenceTasks : public ITask {

	public:

		//################### CONSTRUCTOR ###################
		SequenceTasks(string name, ControlIterator* iterate);
		virtual ~SequenceTasks();



		//################### METHODS ###################
		void 	execute();
		void 	cancel();
		void 	pause();


		/**
		 * Add a Task to the sequence
		 *
		 * @param ITask to execute
		 */
		void 	add(ITask* task);


	protected:

		// class to iterate through the tasks of a sequence
		ControlIterator* iterate;

	private:

		// list of tasks or sequence of tasks to execute
		vector <ITask*> _tasks;

};

#endif /* SEQUENCETASKS_H_ */
