/*
 * TaskBatchDataLoad.h
 *
 *  Created on: 07 may. 2021
 *
 *  Author: Cesar Augusto Guzman
 *  Email: cguzwork@cguz.org
 */

#ifndef TASKBATCHDATALOAD_H_
#define TASKBATCHDATALOAD_H_

#include <iostream>
#include "../../Execution/Task.h"

using namespace std;

/**
 * Dummy example of task batch data load
 */
class TaskBatchDataLoad : public Task {

	//--------------------------------------------------
	// public section
	//--------------------------------------------------

	public:

		// **************** CONSTRUCTOR & DESTRUCTOR **************** //
		TaskBatchDataLoad();

		//################### METHODS ###################

		void execute();

};

#endif /* TASKBATCHDATALOAD_H_ */
