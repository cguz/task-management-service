/*
 * StateCanceled.h
 *
 *  Created on: 07 may. 2021
 *
 *  Author: Cesar Augusto Guzman
 *  Email: cguzwork@cguz.org
 */

#ifndef L_StateCancelled_H_
#define L_StateCancelled_H_

#include <iostream>
#include <stdio.h>

#include "../SequenceTasks.h"
#include "State.h"


class StateCancelled : public State {

	//--------------------------------------------------
	// public section
	//--------------------------------------------------
	public:

		//########################## CONSTRUCTOR & DESTRUCTOR #########################

		StateCancelled();


		//########################## METHODS TO TRANSICT #########################

		void execute(SequenceTasks* context);

		void cancel(SequenceTasks* context);

		void pause(SequenceTasks* context);

		void fail(SequenceTasks* context);

		void finish(SequenceTasks* context);

};


#endif /* L_StateCancelled_H_ */
