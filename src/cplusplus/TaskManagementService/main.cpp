/*
 * main.cpp
 *
 *  Created on: 07 may. 2020
 *
 *  @Author: Cesar Augusto Guzman Alvarez
 *  @Email : cguzwork@cguz.org
 */

#pragma hdrstop

#include "CLIENT/Creational/CustomSequenceCatalogConstructor.h"
#include "Creational/SequenceTasksCatalogConstructor.h"
#include "Control.h"
// #include <thread>


//# global variables
SequenceTasksCatalogConstructor* sequenceTasks;

Control* controlClient;


/**
 * Function to show an example of how to call the general Task Management Service
 */
void testGeneral() {

	cout << "\n------------------" << endl;
	cout << "1. Create the Sequence Tasks Constructor and add it to the client control" << endl;
	cout << "-------------------" << endl;

	sequenceTasks = new CustomSequenceCatalogConstructor();
	controlClient = new Control(sequenceTasks);


	cout << "\n\n------------------------------------------" << endl;
	cout << "2. Choose the sequence task SEQ_TASKS_GROUP1 for execution" << endl;
	cout << "--------------------------------------------" << endl;

	controlClient->select(SequenceTasksCatalogConstructor::SEQ_TASKS_GROUP1);

	try {

		cout << "\n\n--------------------------------------------";
		cout << "\n3. START The execution of SEQ_TASKS_GROUP1 ";
		cout << "\n--------------------------------------------" << endl;

		controlClient->execute();

		controlClient->pause();

		controlClient->execute();


		cout << "\n\n-----------------------------------------";
		cout << "\n3. END The execution of SEQ_TASKS_GROUP1";
		cout << "\n-----------------------------------------" << endl;

	} catch(char const* exception) {
		cout << endl << exception << endl;
	}
}

/**
 * Function to show an example of how to call a sequence of the instrument FRIDA
 */
void testClientTasks() {

	cout << "\n------------------" << endl;
	cout << "1. Create the Sequence Tasks Constructor and add it to the client control" << endl;
	cout << "-------------------" << endl;

	sequenceTasks = new CustomSequenceCatalogConstructor();
	controlClient = new Control(sequenceTasks);


	cout << "\n\n-----------------------------------" << endl;
	cout << "2. Choose the sequence task SEQ_CUSTOM1 (it only contains one task) for execution" << endl;
	cout << "---------------------------------------" << endl;

	controlClient->select(CustomSequenceCatalogConstructor::SEQ_CUSTOM1);

	try {

		cout << "\n\n--------------------------------------------";
		cout << "\n3. START The execution of SEQ_CUSTOM1 ";
		cout << "\n--------------------------------------------" << endl;

		controlClient->execute();

		cout << "\n\n-----------------------------------------";
		cout << "\n3. END The execution of SEQ_CUSTOM1";
		cout << "\n-----------------------------------------" << endl;

	} catch(char const* exception) {
		cout << endl << exception << endl;
	}
}


int main(int argc, char* argv[]) {

	/** TEST the General Task Management Service **/
	testGeneral();


	/** TEST the specific Tasks of the client **/
	testClientTasks();

	return 0;

}


