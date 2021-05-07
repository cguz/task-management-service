/*
 * CustomSequenceCatalogConstructor.h
 *
 *  Created on: 07 may. 2021
 *
 *  Author: Cesar Augusto Guzman
 *  Email: cguzwork@cguz.org
 */


#ifndef CUSTOMSEQUENCECATALOGCONSTRUCTOR_H_
#define CUSTOMSEQUENCECATALOGCONSTRUCTOR_H_

#pragma hdrstop

#include <iostream>
#include <unordered_map>
#include <vector>
#include "../../Creational/SequenceTasksCatalogConstructor.h"

using namespace std;

/**
 * Class to create a Custom catalog of sequence tasks
 */
class CustomSequenceCatalogConstructor : public SequenceTasksCatalogConstructor {


	public:

		//################### CONSTRUCTOR ###################
		CustomSequenceCatalogConstructor();
		virtual ~CustomSequenceCatalogConstructor();


		//################### GLOBAL ENUMERATE ###################

		// In our case we inherits the factories
		enum FRIDASequenceFactoryIds {
			SEQ_CUSTOM1 = SEQ_TASKS_GROUP2+1, SEQ_CUSTOM2
		};


	protected:

		//################### METHODS ###################

		/**
		 * Initialize the CustomSequenceCatalogConstructor
		 */
		void init();


};

#endif /* CUSTOMSEQUENCECATALOGCONSTRUCTOR_H_ */
