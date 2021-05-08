/*
 * TasksGroup2Factory.cpp
 *
 *  Created on: 07 may. 2021
 *
 *  Author: Cesar Augusto Guzman
 *  Email: cguzwork@cguz.org
 */
#ifndef FACTORYPM_TASKSGROUP2FACTORY_H_
#define FACTORYPM_TASKSGROUP2FACTORY_H_

#include <iostream>

#include "../SequenceTasksFactory.h"
#include "../../Execution/SequenceTasks.h"
#include "../../Execution/Task.h"

using namespace std;

/**
 * Dummy example 2 of a Sequence of Tasks
 *
 * This class test the functionality of the SequenceTasks class
 */
class TasksGroup2Factory : public SequenceTasksFactory {

	public:

		//################### CONSTRUCTOR ###################
		TasksGroup2Factory();
		virtual ~TasksGroup2Factory();


		//################### METHODS ###################
		/**
		 * Create the sequence
		 * @return abstract class ITask that represents the Sequence of Tasks
		 */
		ITask* build();

};

#endif /* FACTORYPM_TASKSGROUP2FACTORY_H_ */
