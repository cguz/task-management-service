/*
 * SeqStateRunning.h
 *
 *  Created on: 07 may. 2021
 *
 *  Author: Cesar Augusto Guzman
 *  Email: cguzwork@cguz.org
 */

#ifndef L_StateRunning_H_
#define L_StateRunning_H_

#include <iostream>
#include <stdio.h>

#include "../ITask.h"
#include "State.h"


class StateRunning : public State {

	//--------------------------------------------------
	// public section
	//--------------------------------------------------
	public:

		//########################## CONSTRUCTOR & DESTRUCTOR #########################

		StateRunning();


		//########################## METHODS TO TRANSICT #########################

		void execute(ITask* context);

		void cancel(ITask* context);

		void pause(ITask* context);

		void finish(ITask* context);

		void fail(ITask* context);


};


#endif /* L_StateRunning_H_ */
