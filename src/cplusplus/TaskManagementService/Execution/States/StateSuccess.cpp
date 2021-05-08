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

void StateSuccess::cancel(ITask* context) {

	cout << "throw WrongState No possible transition from Success to Cancelled!\n";

}

void StateSuccess::execute(ITask* context) {

	cout << "throw WrongState No possible transition from Success to Running!\n";

}

void StateSuccess::pause(ITask* context) {

	cout << "throw WrongState No possible transition from Success to Paused!\n";

}

void StateSuccess::fail(ITask* context) {

	cout << "throw WrongState No possible transition from Success to Failed!\n";

}

void StateSuccess::finish(ITask* context) {

	cout << "throw WrongState No possible transition from Success to Success!\n";

}

#pragma package(smart_init)
