/*
 * TaskIndexFile.h
 *
 *  Created on: 07 may. 2021
 *
 *  Author: Cesar Augusto Guzman
 *  Email: cguzwork@cguz.org
 */

#ifndef TASKINDEXFILE_H_
#define TASKINDEXFILE_H_

#include <iostream>
#include "../../Execution/Task.h"

using namespace std;

/**
 * Dummy example of task index file
 */
class TaskIndexFile : public Task {

	//--------------------------------------------------
	// public section
	//--------------------------------------------------

	public:

		// **************** CONSTRUCTOR & DESTRUCTOR **************** //
		TaskIndexFile();

		//################### METHODS ###################

		void execute();

};

#endif /* TASKINDEXFILE_H_ */
