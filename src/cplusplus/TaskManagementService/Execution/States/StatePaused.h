/*
 * StatePaused.h
 *
 *  Created on: 07 may. 2021
 *
 *  Author: Cesar Augusto Guzman
 *  Email: cguzwork@cguz.org
 */

#ifndef L_StateQueue_H_
#define L_StateQueue_H_

#include <iostream>
#include <stdio.h>

#include "../ITask.h"
#include "State.h"


class StatePaused : public State {

	//--------------------------------------------------
	// public section
	//--------------------------------------------------
	public:

		//########################## CONSTRUCTOR & DESTRUCTOR #########################

		StatePaused();


		//########################## METHODS TO TRANSICT #########################

		void execute(ITask* context);

		void cancel(ITask* context);

		void pause(ITask* context);

		void fail(ITask* context);

		void finish(ITask* context);

};


#endif /* L_StateQueue_H_ */
