/*
 * TaskSendNotifications.cpp
 *
 *  Created on: 07 may. 2021
 *
 *  Author: Cesar Augusto Guzman
 *  Email: cguzwork@cguz.org
 */

#include "TaskSendNotifications.h"


TaskSendNotifications::TaskSendNotifications() : Task() {

}


//################### METHODS ###################

void TaskSendNotifications::execute() {
	cout << endl << "Executing task send notifications." << endl;
	cout << endl << " ->  call methods() " << endl;

	Task::simulateDuration();
}
