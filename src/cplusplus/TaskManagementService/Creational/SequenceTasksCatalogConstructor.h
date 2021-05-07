/*
 * SequenceTasksCatalogConstructor.h
 *
 *  Created on: 07 may. 2021
 *
 *  Author: Cesar Augusto Guzman
 *  Email: cguzwork@cguz.org
 */

#ifndef FACTORYPM_SEQUENCETASKSCONSTRUCTOR_H_
#define FACTORYPM_SEQUENCETASKSCONSTRUCTOR_H_

#pragma hdrstop

#include <iostream>
#include <unordered_map>
#include <vector>
#include "SequenceTasksFactory.h"

using namespace std;

/**
 * Constructor to create a sequence tasks catalog
 */
class SequenceTasksCatalogConstructor {


	public:

		//################### CONSTRUCTOR ###################
		SequenceTasksCatalogConstructor();
		virtual ~SequenceTasksCatalogConstructor();



		//################### METHODS ###################
		/**
		 * Create the sequence tasks of the given id
		 *
		 * @param Id
		 * @return abstract class ITasks that represents the predefined sequence tasks to execute
		 */
		ITask* 				build(short Id);

		/**
		 * Retrieves a list of sequence ids
		 */
		vector<int> 		getSequenceIds();



		//################### GLOBAL ENUMERATE ###################

		// Predefined group tasks Ids
		enum SequenceFactoryIds {
			SEQ_TASKS_GROUP1, SEQ_TASKS_GROUP2
		};


	private:

		//################### METHODS ###################
		/**
		 * Retrieve the factory of the given sequence id
		 *
		 * @param short Id
		 * @return abstract class SequenceFactory
		 */
		SequenceTasksFactory* getFactory_(short Id);


	protected:

		// Catalog of the sequence tasks Factory
		unordered_map <short, SequenceTasksFactory*> sequenceTasksFactoryCatalog;


		//################### METHODS ###################

		/**
		 * Initialize
		 */
		void init();


};

#endif /* FACTORYPM_SEQUENCETASKSCONSTRUCTOR_H_ */
