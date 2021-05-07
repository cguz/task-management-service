/*
 * TaskSendNotifications.h
 *
 *  Created on: 07 may. 2021
 *
 *  Author: Cesar Augusto Guzman
 *  Email: cguzwork@cguz.org
 */

#ifndef TASKSENDNOTIFICATIONS_H_
#define TASKSENDNOTIFICATIONS_H_

#include <iostream>
#include "../../Execution/Task.h"

using namespace std;

/**
 * Dummy example of task send notifications
 */
class TaskSendNotifications : public Task {

	//--------------------------------------------------
	// public section
	//--------------------------------------------------

	public:

		// **************** CONSTRUCTOR & DESTRUCTOR **************** //
		TaskSendNotifications();

		//################### METHODS ###################

		void execute();

};

#endif /* S */
