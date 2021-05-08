/*
 * CustomSeqNAME1Factory.cpp
 *
 *  Created on: 07 may. 2021
 *
 *  Author: Cesar Augusto Guzman
 *  Email: cguzwork@cguz.org
 */


#include "CustomSeqExampleTasksToExecuteFactory.h"

class Task;

//################### CONSTRUCTOR ###################

CustomSeqExampleTasksToExecuteFactory::CustomSeqExampleTasksToExecuteFactory() : CustomSequenceFactory(){
	cout << endl << "Constructor CustomSeqNAME1Factory";
}

CustomSeqExampleTasksToExecuteFactory::~CustomSeqExampleTasksToExecuteFactory() {
	cout << endl << "Destructor of the class CustomSeqNAME1Factory";
}


//################### METHODS ###################

ITask* CustomSeqExampleTasksToExecuteFactory::build() {

	cout << "\nExecute CustomSeqNAME1Factory::build()";
	cout << endl << "Iterative Sequence.";


	ControlIterator* iterate = new ControlIterator(1);

	// input parameters are : name of the sequence, total number of commands to execute and total number of repetitions of the execution
	SequenceTasks* sequence = new SequenceIterative("CustomSeqNAME1Factory", iterate);

	sequence->add(new TaskBatchDataLoad());
	sequence->add(new TaskIndexFile());
	sequence->add(new TaskSendNotifications());

	return sequence;

}
