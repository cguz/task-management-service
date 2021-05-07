/*
 * StateSuccess.cpp
 *
 *  Created on: 07 may. 2021
 *
 *  Author: Cesar Augusto Guzman
 *  Email: cguzwork@cguz.org
 */

#pragma hdrstop

#include "StateSuccess.h"


//########################## CONSTRUCTOR & DESTRUCTOR #########################

StateSuccess::StateSuccess() {
	_name = "Success";
	_id = SUCCESS;
}


//########################## METHODS TO TRANSICT #########################

void StateSuccess::cancel(SequenceTasks* context) {

	cout << "throw WrongState No possible transition!\n";

}

void StateSuccess::execute(SequenceTasks* context) {

	cout << "throw WrongState No possible transition!\n";

}

void StateSuccess::pause(SequenceTasks* context) {

	cout << "throw WrongState No possible transition!\n";

}

void StateSuccess::fail(SequenceTasks* context) {

	cout << "throw WrongState No possible transition!\n";

}

void StateSuccess::finish(SequenceTasks* context) {

	cout << "throw WrongState No possible transition!\n";

}

#pragma package(smart_init)
