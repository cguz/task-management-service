/*
 * CustomSeqNAME1Factory.cpp
 *
 *  Created on: 07 may. 2021
 *
 *  Author: Cesar Augusto Guzman
 *  Email: cguzwork@cguz.org
 */


#include "CustomSeqNAME1Factory.h"

class Task;

//################### CONSTRUCTOR ###################

CustomSeqNAME1Factory::CustomSeqNAME1Factory() : CustomSequenceFactory(){
	cout << endl << "Constructor CustomSeqNAME1Factory";
}

CustomSeqNAME1Factory::~CustomSeqNAME1Factory() {
	cout << endl << "Destructor of the class CustomSeqNAME1Factory";
}


//################### METHODS ###################

ITask* CustomSeqNAME1Factory::build() {

	cout << "\nExecute CustomSeqNAME1Factory::build()";
	cout << endl << "Iterative Sequence.";


	SequenceIterator* iterate = new SequenceIterator(1);

	// input parameters are : name of the sequence, total number of commands to execute and total number of repetitions of the execution
	SequenceTasks* sequence = new IterativeSequence("CustomSeqNAME1Factory", iterate);

	sequence->add(new TaskBatchDataLoad());
	sequence->add(new TaskIndexFile());
	sequence->add(new TaskSendNotifications());

	return sequence;

}
