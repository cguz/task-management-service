/*
 * TasksGroup1Factory.cpp
 *
 *  Created on: 07 may. 2021
 *
 *  Author: Cesar Augusto Guzman
 *  Email: cguzwork@cguz.org
 */

#ifndef FACTORYPM_SEQGROUP1FACTORY_H_
#define FACTORYPM_SEQGROUP1FACTORY_H_

#include <iostream>

#include "../../Execution/Task.h"
#include "../SequenceTasksFactory.h"

using namespace std;

/**
 * Dummy example 1 of a Sequence of Tasks
 *
 * This class test the functionality with only one Task class
 */
class TasksGroup1Factory : public SequenceTasksFactory {

	public:

		//################### CONSTRUCTOR ###################
		TasksGroup1Factory();
		virtual ~TasksGroup1Factory();


		//################### METHODS ###################
		/**
		 * Create the sequence task
		 *
		 * @return abstract class ITask that represents the Sequence tasks
		 */
		ITask* build();

};

#endif /* FACTORYPM_SEQGROUP1FACTORY_H_ */
