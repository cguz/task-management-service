/*
 * SequenceTasksConstructor.cpp
 *
 *  Created on: 07 may. 2021
 *
 *  Author: Cesar Augusto Guzman
 *  Email: cguzwork@cguz.org
 */
#ifndef FACTORYPM_TASK_H_
#define FACTORYPM_TASK_H_

#include <iostream>
#include "ITask.h"

using namespace std;

/**
 * Leaf class to execute task of the sequence tasks
 */
class Task : public ITask {

	public:

		//################### CONSTRUCTOR ###################
		Task();
		// virtual ~Command();

		//################### METHODS ###################

		void 	execute();
		void 	cancel();
		void 	pause();
		void 	resume();


};

#endif /* FACTORYPM_TASK_H_ */
