/*
 * ITask.h
 *
 *  Created on: 07 may. 2021
 *
 *  Author: Cesar Augusto Guzman
 *  Email: cguzwork@cguz.org
 */

#ifndef FACTORYPM_ITASK_H_
#define FACTORYPM_ITASK_H_

#include <iostream>


using namespace std;

/**
 * Single class for the composite pattern
 */
class ITask {

	public:

		//################### CONSTRUCTOR ###################
		ITask();
		virtual ~ITask();


		//################### METHODS ###################
		virtual void 	execute()=0;
		virtual void 	cancel()=0;
		virtual void 	pause()=0;



		/**
		 * Update the name of the Task or the Sequence Task
		 */
		void 	setName(string name);

		/**
		 * Retrieve the name
		 */
		string 	getName();


		/**
		 * Retrieve the ITask as a string
		 */
		string 	toString();

	private:

		// name of the sequence of tasks or task
		string name_ = "ITask";

};

#endif /* FACTORYPM_ITASK_H_ */
