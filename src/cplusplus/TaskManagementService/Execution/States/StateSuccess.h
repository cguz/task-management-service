/*
 * StateSuccess.h
 *
 *  Created on: 07 may. 2021
 *
 *  Author: Cesar Augusto Guzman
 *  Email: cguzwork@cguz.org
 */

#ifndef L_StateSuccess_H_
#define L_StateSuccess_H_

#include <iostream>
#include <stdio.h>

#include "../SequenceTasks.h"
#include "State.h"


class StateSuccess : public State {

	//--------------------------------------------------
	// public section
	//--------------------------------------------------
	public:

		//########################## CONSTRUCTOR & DESTRUCTOR #########################

		StateSuccess();


		//########################## METHODS TO TRANSICT #########################

		void execute(SequenceTasks* context);

		void cancel(SequenceTasks* context);

		void pause(SequenceTasks* context);

		void finish(SequenceTasks* context);

		void fail(SequenceTasks* context);

};


#endif /* L_StateSuccess_H_ */
