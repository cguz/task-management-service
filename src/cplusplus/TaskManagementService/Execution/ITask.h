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
#include "States/State.h"


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



		//########################## GETTERS AND SETTERS ############################

		/**
		* Update the current state
		*/
		void setState(State* state);

		/**
		* Retrieve the current state
		*/
		State* getState();

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


	protected:

		// current state of the Sequence
		State* state;


	private:

		// name of the sequence of tasks or task
		string name_ = "ITask";

};

#endif /* FACTORYPM_ITASK_H_ */
