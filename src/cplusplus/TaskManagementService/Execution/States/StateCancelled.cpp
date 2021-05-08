/*
 * StateCanceled.cpp
 *
 *  Created on: 07 may. 2021
 *
 *  Author: Cesar Augusto Guzman
 *  Email: cguzwork@cguz.org
 */

#pragma hdrstop

#include "StateCancelled.h"
#include "StateSuccess.h"


//########################## CONSTRUCTOR & DESTRUCTOR #########################

StateCancelled::StateCancelled() {
	_name = "Cancelled";
	_id = CANCELLED;
}


//########################## METHODS TO TRANSICT #########################

void StateCancelled::execute(ITask* context) {

	cout << "throw WrongState No possible transition!\n";

}

void StateCancelled::cancel(ITask* context) {

	cout << "\nThe component is already in the state "<<_name<<"!\n";

}

void StateCancelled::pause(ITask* context) {

	cout << "throw WrongState No possible transition!\n";

}

void StateCancelled::finish(ITask* context) {

	cout << "throw WrongState No possible transition!\n";

}

void StateCancelled::fail(ITask* context) {

	cout << "throw WrongState No possible transition!\n";

}


#pragma package(smart_init)
