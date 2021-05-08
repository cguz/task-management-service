#include "gtest/gtest.h"


#include "TaskManagementService/CLIENT/Creational/CustomSequenceTasksCatalogConstructor.h"
#include "TaskManagementService/Creational/SequenceTasksCatalogConstructor.h"
#include "TaskManagementService/ClientControl.h"

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
bool testExecutionOneTask() {

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
		return false;
	}

	return true;
}



/**
 * Function to show an example of how to execute two tasks
 */
bool testExecutionTwoTasks() {

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
		return false;
	}

	return true;
}


/**
 * Function to show an example of how to execute two tasks
 */
bool testClientTasks() {

	createClientControlCustomCatalog();


	cout << "\n\n-----------------------------------" << endl;
	cout << "3. Choose the sequence task SEQ_CUSTOM1 for execution" << endl;
	cout << "---------------------------------------" << endl;

	controlClient->select(CustomSequenceTasksCatalogConstructor::SEQ_CUSTOM1);

	try {

		cout << "\n\n--------------------------------------------";
		cout << "\n4. START The execution of SEQ_CUSTOM1 ";
		cout << "\n--------------------------------------------" << endl;

		controlClient->execute();

		cout << "\n\n-----------------------------------------";
		cout << "\n4. END The execution of SEQ_CUSTOM1";
		cout << "\n-----------------------------------------" << endl;

	} catch(char const* exception) {
		cout << endl << exception << endl;
		return false;
	}

	return true;
}




TEST(IntegrationTest, ExecutionOneTask) {
    //arrange
    //act
    //assert
    EXPECT_EQ (testExecutionOneTask(),  true);
}

TEST(IntegrationTest, ExecutionTwoTasks) {
    //arrange
    //act
    //assert
    EXPECT_EQ (testExecutionTwoTasks(),  true);
}


TEST(IntegrationTest, ExecutionClientTasks) {
    //arrange
    //act
    //assert
    EXPECT_EQ (testClientTasks(),  true);
}
