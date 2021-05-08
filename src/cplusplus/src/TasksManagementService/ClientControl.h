/*
 * ClientControl.h
 *
 *  Created on: 07 may. 2021
 *
 *  Author: Cesar Augusto Guzman
 *  Email: cguzwork@cguz.org
 */

#ifndef CONTROL_H_
#define CONTROL_H_

#pragma hdrstop

#include <iostream>
#include <vector>

#include "Creational/SequenceTasksCatalogConstructor.h"
#include "Execution/TasksManagementService.h"
#include "Execution/ITask.h"

using namespace std;


/**
 * Control class of the proposed solution
 */
class ClientControl {

	//################### CONSTRUCTOR ###################

	public:
		ClientControl(SequenceTasksCatalogConstructor* sequenceConstructor);
		virtual ~ClientControl();


	//################### METHODS ###################
		void execute();
		void cancel();
		void pause();


		/**
		 * Prepare all the sequence tasks
		 */
		void build();

		/**
		 * Select a given sequence tasks
		 * @param sequence id
		 */
		void select(short seqId);

		/**
		 * Add the ITask to execution
		 */
		void add(ITask* task);

		/**
		 * Retrieves a list of sequence ids
		 * @return a vector of integer sequence
		 */
		vector<int> getSequenceIds();

	private:

		// Constructor of a catalog of a task sequence
		SequenceTasksCatalogConstructor* _catalogConstructor;

		// Constructor the sequence executor
		TasksManagementService* _tasksManagement;

};

#endif /* CONTROL_H_ */
