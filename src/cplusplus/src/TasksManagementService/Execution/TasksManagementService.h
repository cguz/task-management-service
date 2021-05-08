/*
 * TaskManagementService.h
 *
 *  Created on: 07 may. 2021
 *
 *  Author: Cesar Augusto Guzman
 *  Email: cguzwork@cguz.org
 */

#ifndef TASKMANAGEMENT_SERVICE_H_
#define TASKMANAGEMENT_SERVICE_H_

#pragma hdrstop

#include <iostream>
#include <unordered_map>
#include <vector>
#include "ITask.h"
#include "SequenceTasks.h"

using namespace std;


/**
 * Main class of the execution framework
 */
class TasksManagementService {

	public:

		//################### CONSTRUCTOR ###################

		TasksManagementService();
		virtual ~TasksManagementService();



		//################### METHODS ###################
		void execute();
		void cancel();
		void pause();


		/**
		 * Select the sequence to execute
		 *
		 * @param sequence id
		 * @param executable
		 */
		void setSequenceTasks(short seqId, ITask* executable);

		/**
		 * Check is the sequence is initialized
		 *
		 * @param sequence id
		 * @return true when the sequence is initialized
		 */
		bool isInitialized(short seqId);

		/**
		 * Add the task for its execution
		 *
		 * @param task to execute
		 */
		void add(ITask* task);

	private:

		short _currentSequenceTask = -1;

		// Catalog of executable task or sequence tasks
		unordered_map <short, ITask*> _tasksCatalog;

};

#endif /* TASKMANAGEMENT_SERVICE_H_ */
