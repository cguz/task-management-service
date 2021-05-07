/*
 * CustomSeqNAME1Factory.h
 *
 *  Created on: 07 may. 2021
 *
 *  Author: Cesar Augusto Guzman
 *  Email: cguzwork@cguz.org
 */



#ifndef CUSTOMSEQNAM1FACTORY_H_
#define CUSTOMSEQNAM1FACTORY_H_

#include <iostream>

#include "../../../Execution/IterativeSequence.h"
#include "../../../Execution/Task.h"

#include "../../Execution/TaskBatchDataLoad.h"
#include "../../Execution/TaskIndexFile.h"
#include "../../Execution/TaskSendNotifications.h"
#include "../CustomSequenceFactory.h"


using namespace std;

/**
 * Dummy example 1
 *
 * This class test the functionality with a dummy sequence tasks example
 */
class CustomSeqNAME1Factory : public CustomSequenceFactory {

	public:

		//################### CONSTRUCTOR ###################
		CustomSeqNAME1Factory();
		virtual ~CustomSeqNAME1Factory();


		//################### METHODS ###################
		/**
		 * Create the sequence
		 */
		ITask* build();

};

#endif /* CUSTOMSEQNAM1FACTORY_H_ */
