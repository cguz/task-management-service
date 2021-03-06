/*
 * SequenceTasksFactory.h
 *
 *  Created on: 07 may. 2021
 *
 *  Author: Cesar Augusto Guzman
 *  Email: cguzwork@cguz.org
 */

#ifndef SEQUENCETASKSFACTORY_H_
#define SEQUENCETASKSFACTORY_H_

#include "../Execution/ITask.h"

/**
 * Class pure virtual of a factory to create Sequence tasks
 */
class SequenceTasksFactory {

	public:

		//################### CONSTRUCTOR ###################
		SequenceTasksFactory();
		virtual ~SequenceTasksFactory();


		//################### METHODS ###################
		/**
		 * Create the Sequence of Tasks as an abstract class ITask
		 */
		virtual ITask* build() = 0;


};

#endif /* SEQUENCETASKSFACTORY_H_ */
