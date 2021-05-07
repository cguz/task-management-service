/*
 * IterativeSequence.h
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

#include "ControlIterator.h"
#include "ITask.h"
#include "SequenceTasks.h"
#include "States/State.h"

using namespace std;

/**
 * Composite of an Iterative Sequence to execute
 */
class SequenceIterative : public SequenceTasks {

	public:

		//################### CONSTRUCTOR ###################

		SequenceIterative(string name, ControlIterator* iterate);
		~SequenceIterative();


		//################### METHODS ###################

		void execute();

};

#endif /* ITERATIVESEQUENCE_H_ */
