/*
 * CustomSequenceFactory.H
 *
 *  Created on: 07 may. 2021
 *
 *  Author: Cesar Augusto Guzman
 *  Email: cguzwork@cguz.org
 */


#ifndef CUSTOMSEQUENCEFACTORY_H_
#define CUSTOMSEQUENCEFACTORY_H_

#include "../../Creational/SequenceTasksFactory.h"

/**
 * Interface to create Custom task Sequence
 */
class CustomSequenceFactory : public SequenceTasksFactory {

	public:

		//################### CONSTRUCTOR ###################
		CustomSequenceFactory();
		virtual ~CustomSequenceFactory();


		//################### METHODS ###################

};

#endif /* CUSTOMSEQUENCEFACTORY_H_ */
