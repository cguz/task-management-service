/*
 * main.cpp
 *
 *  Created on: 07 may. 2020
 *
 *  @Author: Cesar Augusto Guzman Alvarez
 *  @Email : cguzwork@cguz.org
 */

#pragma hdrstop

#include "CLIENT/Creational/CustomSequenceTasksCatalogConstructor.h"
#include "CLIENT/Execution/TaskIndexFile.h"
#include "Creational/SequenceTasksCatalogConstructor.h"
#include "ClientControl.h"
#include <thread>


//# global variables
SequenceTasksCatalogConstructor* sequenceTasks;

ClientControl* controlClient;



/**
 * Function to create the control and the sequenceTasksCatalogConstructor
 */
void createClientControl(){

	cout << "\n------------------" << endl;
	cout << "1. Create the Sequence Tasks Catalog Constructor" << endl;
	cout << "-------------------" << endl;

	sequenceTasks = new SequenceTasksCatalogConstructor();


	cout << "\n\n------------------" << endl;
	cout << "2. Create the client control with the Sequence Tasks Constructor" << endl;
	cout << "-------------------" << endl;


	controlClient = new ClientControl(sequenceTasks);

}

/**
 * Function to create the control and the CustomSequenceCatalogConstructor
 */
void createClientControlCustomCatalog(){

	cout << "\n------------------" << endl;
	cout << "1. Create the Custom Sequence Tasks Catalog Constructor" << endl;
	cout << "-------------------" << endl;

	sequenceTasks = new CustomSequenceTasksCatalogConstructor();


	cout << "\n\n------------------" << endl;
	cout << "2. Create the client control with the Sequence Tasks Constructor" << endl;
	cout << "-------------------" << endl;


	controlClient = new ClientControl(sequenceTasks);

}


/**
 * Function to show an example of how to execute one task
 */
void testExecutionOneTask() {

	createClientControl();

	cout << "\n\n------------------------------------------" << endl;
	cout << "3. Choose the sequence task SEQ_TASKS_GROUP1 for execution" << endl;
	cout << "--------------------------------------------" << endl;

	controlClient->select(SequenceTasksCatalogConstructor::SEQ_TASKS_GROUP1);

	try {

		cout << "\n\n--------------------------------------------";
		cout << "\n4. START The execution of SEQ_TASKS_GROUP1 ";
		cout << "\n--------------------------------------------" << endl;

		controlClient->execute();

		cout << "\n\n-----------------------------------------";
		cout << "\n4. END The execution of SEQ_TASKS_GROUP1";
		cout << "\n-----------------------------------------" << endl;

	} catch(char const* exception) {
		cout << endl << exception << endl;
	}
}

/**
 * Function to show an example of how to execute two tasks
 */
void testExecutionTwoTasks() {

	createClientControl();

	cout << "\n\n------------------------------------------" << endl;
	cout << "3. Choose the sequence task SEQ_TASKS_GROUP2 for execution" << endl;
	cout << "--------------------------------------------" << endl;

	controlClient->select(SequenceTasksCatalogConstructor::SEQ_TASKS_GROUP2);

	try {

		cout << "\n\n--------------------------------------------";
		cout << "\n4. START The execution of SEQ_TASKS_GROUP2 ";
		cout << "\n--------------------------------------------" << endl;

		controlClient->execute();

		cout << "\n\n-----------------------------------------";
		cout << "\n4. END The execution of SEQ_TASKS_GROUP2";
		cout << "\n-----------------------------------------" << endl;

	} catch(char const* exception) {
		cout << endl << exception << endl;
	}
}

/**
 * Function to show an example of how to execute some tasks of the client
 * SEQ_CUSTOM1 contains three tasks: 1.) Batch data load to a data warehouse;, 2) Index files; and 3) Send notifications.
 */
void testClientTasks() {

	createClientControlCustomCatalog();


	cout << "\n\n-----------------------------------" << endl;
	cout << "3. Choose the sequence task SEQ_CUSTOM1 for execution" << endl;
	cout << "---------------------------------------" << endl;

	// SEQ_CUSTOM1 contains three tasks: 1.) Batch data load to a data warehouse;, 2) Index files; and 3) Send notifications.
	controlClient->select(CustomSequenceTasksCatalogConstructor::SEQ_CUSTOM1);

	try {

		cout << "\n\n--------------------------------------------";
		cout << "\n4. START The execution of SEQ_CUSTOM1 ";
		cout << "\n--------------------------------------------" << endl;

		// execute the tasks waiting until it finish
		std::thread executeThread(&ClientControl::execute, std::ref(controlClient));
		executeThread.join();

		cout << "\n\n-----------------------------------------";
		cout << "\n4. END The execution of SEQ_CUSTOM1";
		cout << "\n-----------------------------------------" << endl;

	} catch(char const* exception) {
		cout << endl << exception << endl;
	}
}

/**
 * Function to show an example of how to execute some tasks of the client and add a new one during execution
 * - SEQ_CUSTOM1 contains three tasks: 1.) Batch data load to a data warehouse;, 2) Index files; and 3) Send notifications.
 * - NEW TASK ADDED: Index Files
 */
void testClientTasksAddNewOne() {

	createClientControlCustomCatalog();


	cout << "\n\n-----------------------------------" << endl;
	cout << "3. Choose the sequence task SEQ_CUSTOM1 for execution" << endl;
	cout << "---------------------------------------" << endl;

	// SEQ_CUSTOM1 contains three tasks: 1.) Batch data load to a data warehouse;, 2) Index files; and 3) Send notifications.s
	controlClient->select(CustomSequenceTasksCatalogConstructor::SEQ_CUSTOM1);

	try {

		cout << "\n\n--------------------------------------------";
		cout << "\n4. START The execution of SEQ_CUSTOM1 ";
		cout << "\n--------------------------------------------" << endl;

		// execute the tasks in parallel
		std::thread executeThread(&ClientControl::execute, std::ref(controlClient));
		executeThread.detach();

		// add the new task
		controlClient->add(new TaskIndexFile());

		// wait until the tasks finish their execution
	    std::this_thread::sleep_for(std::chrono::seconds(20));

		cout << "\n\n-----------------------------------------";
		cout << "\n4. END The execution of SEQ_CUSTOM1";
		cout << "\n-----------------------------------------" << endl;

	} catch(char const* exception) {
		cout << endl << exception << endl;
	}
}

/**
 * Function to show an example of how to execute some tasks of the client and add a new one during execution
 * - SEQ_CUSTOM1 contains three tasks: 1.) Batch data load to a data warehouse;, 2) Index files; and 3) Send notifications.
 * - NEW TASK ADDED: Index Files
 * - pause and then execute
 */
void testClientTasksAddNewOnePause() {

	createClientControlCustomCatalog();


	cout << "\n\n-----------------------------------" << endl;
	cout << "3. Choose the sequence task SEQ_CUSTOM1 for execution" << endl;
	cout << "---------------------------------------" << endl;

	// SEQ_CUSTOM1 contains three tasks: 1.) Batch data load to a data warehouse;, 2) Index files; and 3) Send notifications.s
	controlClient->select(CustomSequenceTasksCatalogConstructor::SEQ_CUSTOM1);

	try {

		cout << "\n\n--------------------------------------------";
		cout << "\n4. START The execution of SEQ_CUSTOM1 ";
		cout << "\n--------------------------------------------" << endl;

		// execute the tasks in parallel
		std::thread executeThread(&ClientControl::execute, std::ref(controlClient));
		executeThread.detach();

		// add the new task
		controlClient->add(new TaskIndexFile());

		// wait two seconds
	    cout << endl <<"wait for 2 seconds "<<endl;
	    std::this_thread::sleep_for(std::chrono::seconds(2));

	    // pause the execution of the tasks.
	    controlClient->pause();

		// wait five seconds
	    cout << "wait for 5 seconds "<<endl;
	    std::this_thread::sleep_for(std::chrono::seconds(5));

	    controlClient->execute();

		// wait until the tasks finish their execution
	    std::this_thread::sleep_for(std::chrono::seconds(30));

		cout << "\n\n-----------------------------------------";
		cout << "\n4. END The execution of SEQ_CUSTOM1";
		cout << "\n-----------------------------------------" << endl;

	} catch(char const* exception) {
		cout << endl << exception << endl;
	}
}


/**
 * Function to show an example of how to execute some tasks of the client and add a new one during execution
 * - SEQ_CUSTOM1 contains three tasks: 1.) Batch data load to a data warehouse;, 2) Index files; and 3) Send notifications.
 * - NEW TASK ADDED: Index Files
 * - cancel
 */
void testClientTasksAddNewOneCancel() {

	createClientControlCustomCatalog();


	cout << "\n\n-----------------------------------" << endl;
	cout << "3. Choose the sequence task SEQ_CUSTOM1 for execution" << endl;
	cout << "---------------------------------------" << endl;

	// SEQ_CUSTOM1 contains three tasks: 1.) Batch data load to a data warehouse;, 2) Index files; and 3) Send notifications.s
	controlClient->select(CustomSequenceTasksCatalogConstructor::SEQ_CUSTOM1);

	try {

		cout << "\n\n--------------------------------------------";
		cout << "\n4. START The execution of SEQ_CUSTOM1 ";
		cout << "\n--------------------------------------------" << endl;

		// execute the tasks in parallel
		std::thread executeThread(&ClientControl::execute, std::ref(controlClient));
		executeThread.detach();

		// add the new task
		controlClient->add(new TaskIndexFile());

		// wait two seconds
	    cout << endl <<"wait for 2 seconds "<<endl;
	    std::this_thread::sleep_for(std::chrono::seconds(2));

	    // cancel the execution of the tasks.
	    // Internally, it first pause the execution and then cancel the task
	    controlClient->cancel();

	    // the execution cannot continue
	    controlClient->execute();

		// wait until the tasks finish their execution
	    std::this_thread::sleep_for(std::chrono::seconds(10));

		cout << "\n\n-----------------------------------------";
		cout << "\n4. END The execution of SEQ_CUSTOM1";
		cout << "\n-----------------------------------------" << endl;

	} catch(char const* exception) {
		cout << endl << exception << endl;
	}
}


int main(int argc, char* argv[]) {

	/** TEST the General Task Management Service **/
	// testExecutionOneTask();

	// testExecutionTwoTasks();


	/** TEST the specific Tasks of the client **/
	// testClientTasks();

	// testClientTasksAddNewOne();

	// testClientTasksAddNewOnePause();

	testClientTasksAddNewOneCancel();

	return 0;

}


