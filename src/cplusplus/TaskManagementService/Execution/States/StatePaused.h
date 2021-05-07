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

#include "../SequenceTasks.h"
#include "State.h"


class StatePaused : public State {

	//--------------------------------------------------
	// public section
	//--------------------------------------------------
	public:

		//########################## CONSTRUCTOR & DESTRUCTOR #########################

		StatePaused();


		//########################## METHODS TO TRANSICT #########################

		void execute(SequenceTasks* context);

		void cancel(SequenceTasks* context);

		void pause(SequenceTasks* context);

		void fail(SequenceTasks* context);

		void finish(SequenceTasks* context);

};


#endif /* L_StateQueue_H_ */
