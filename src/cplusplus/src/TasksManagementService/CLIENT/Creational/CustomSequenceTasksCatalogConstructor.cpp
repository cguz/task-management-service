/*
 * CustomSequenceCatalogConstructor.cpp
 *
 *  Created on: 07 may. 2021
 *
 *  Author: Cesar Augusto Guzman
 *  Email: cguzwork@cguz.org
 */


#include "CustomSequenceTasksCatalogConstructor.h"

#include "Factories/CustomSeqExampleTasksToExecuteFactory.h"


//################### CONSTRUCTOR ###################

CustomSequenceTasksCatalogConstructor::CustomSequenceTasksCatalogConstructor()
{
	init();

}

CustomSequenceTasksCatalogConstructor::~CustomSequenceTasksCatalogConstructor() {
	cout<< "\nDestructor of the class CustomSequenceCatalogConstructor (FSCC)";
}




//################### METHODS ###################

void CustomSequenceTasksCatalogConstructor::init(){

	// we add the custom sequence
	sequenceTasksFactoryCatalog[SEQ_CUSTOM1] = new CustomSeqExampleTasksToExecuteFactory();

}
