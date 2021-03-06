/*
 * SeqState.h
 *
 *  Created on: 07 may. 2021
 *
 *  Author: Cesar Augusto Guzman
 *  Email: cguzwork@cguz.org
 */

#ifndef L_State_H_
#define L_State_H_

// Includes
#include <string>
#include <iostream>

// forward declaration
class ITask;

using namespace std;

class State {

	//--------------------------------------------------
	// public section
	//--------------------------------------------------
	public:

		//################### ENUMERATE ###################
		// to identify the state
		enum SeqStateType {
			QUEUED, RUNNING, SUCCESS, FAILED, PAUSED, CANCELLED
		};


		//########################## METHODS TO TRANSICT ############################
		virtual void execute(ITask* context);
		virtual void cancel(ITask* context);
		virtual void pause(ITask* context);
		virtual void finish(ITask* context);
		virtual void fail(ITask* context);



		//################### Methods to query the current sequence state ######################
		bool			isQueued	();
		bool			isRunning	();
		bool			isSuccess	();
		bool			isFailed	();
		bool			isPaused	();
		bool			isCanceled	();


		//########################## GETTERS ############################

		/**
		 * Return the state formatted as a string
		 */
		virtual string toString();

		/**
		 * Retrieve the state identifier
		 */
		virtual int getId();


	//--------------------------------------------------
	// protected section
	//--------------------------------------------------
	protected:

		string _name;

		short _id;


};

#endif // L_State_H_
