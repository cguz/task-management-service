/*
 * IterativeSequence.cpp
 *
 *  Created on: 07 may. 2021
 *
 *  Author: Cesar Augusto Guzman
 *  Email: cguzwork@cguz.org
 */
#ifndef ITERATIVESEQUENCE_H_
#define ITERATIVESEQUENCE_H_

#include <iostream>
#include <vector>

#include "ITask.h"
#include "SequenceIterator.h"
#include "SequenceTasks.h"
#include "StateDesign/State.h"

using namespace std;

/**
 * Composite of an Iterative Sequence to execute
 */
class IterativeSequence : public SequenceTasks {

	public:

		//################### CONSTRUCTOR ###################

		IterativeSequence(string name, SequenceIterator* iterate);
		~IterativeSequence();


		//################### METHODS ###################

		void execute();


		/**
		 * Retrieve the sequence as a string
		 */
		string 	getParameters();

};

#endif /* ITERATIVESEQUENCE_H_ */
