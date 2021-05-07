/*
 * Task.h
 *
 *  Created on: 07 may. 2021
 *
 *  Author: Cesar Augusto Guzman
 *  Email: cguzwork@cguz.org
 */
#ifndef FACTORYPM_TASK_H_
#define FACTORYPM_TASK_H_

#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include<unistd.h>

#include "ITask.h"

using namespace std;

/**
 * Leaf class to execute task of the sequence tasks
 */
class Task : public ITask {

	public:

		//################### CONSTRUCTOR ###################
		Task();

		//################### METHODS ###################

		void 	execute();
		void 	cancel();
		void 	pause();


	protected:
		void 	simulateDuration();

};

#endif /* FACTORYPM_TASK_H_ */
