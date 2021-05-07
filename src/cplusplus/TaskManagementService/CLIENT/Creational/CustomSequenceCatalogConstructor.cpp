/*
 * CustomSequenceCatalogConstructor.cpp
 *
 *  Created on: 07 may. 2021
 *
 *  Author: Cesar Augusto Guzman
 *  Email: cguzwork@cguz.org
 */


#include "CustomSequenceCatalogConstructor.h"
#include "Factories/CustomSeqNAME1Factory.h"


//################### CONSTRUCTOR ###################

CustomSequenceCatalogConstructor::CustomSequenceCatalogConstructor()
{
	init();

}

CustomSequenceCatalogConstructor::~CustomSequenceCatalogConstructor() {
	cout<< "\nDestructor of the class FRIDASequenceCatalogConstructor (FSCC)";
}




//################### METHODS ###################

void CustomSequenceCatalogConstructor::init(){

	// we add the sequence of FRIDA instrument
	sequenceTasksFactoryCatalog[SEQ_CUSTOM1] = new CustomSeqNAME1Factory();

}
