/*
 * StateFailed.cpp
 *
 *  Created on: 07 may. 2021
 *
 *  Author: Cesar Augusto Guzman
 *  Email: cguzwork@cguz.org
 */

#pragma hdrstop

#include "StateFailed.h"


//########################## CONSTRUCTOR & DESTRUCTOR #########################

StateFailed::StateFailed() {
	_name = "Failed";
	_id = FAILED;
}


//########################## METHODS TO TRANSICT #########################

void StateFailed::execute(ITask* context) {

	cout << "throw WrongState No possible transition!\n";

}

void StateFailed::cancel(ITask* context) {

	cout << "throw WrongState No possible transition!\n";

}

void StateFailed::pause(ITask* context) {

	cout << "throw WrongState No possible transition!\n";

}

void StateFailed::finish(ITask* context) {

	cout << "throw WrongState No possible transition!\n";

}

void StateFailed::fail(ITask* context) {

	cout << "\nThe component is already in the state "<<_name<<"!\n";

}


#pragma package(smart_init)
