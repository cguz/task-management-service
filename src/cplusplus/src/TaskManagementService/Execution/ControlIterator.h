/*
 * ControlIterator.h
 *
 *  Created on: 07 may. 2021
 *
 *  Author: Cesar Augusto Guzman
 *  Email: cguzwork@cguz.org
 */
#ifndef _SequenceIterator_h_
#define _SequenceIterator_h_

// Includes
#include <string>
#include <iostream>

using namespace std;

/**
 * The aim of this class is to wrap the different indexes of a sequence execution:
 *   . total number of steps
 *   . current step
 *   . last step
 *   . total number of repetitions
 */
class ControlIterator {

	//-----------------------------------------------------------------
	// private section
	//-----------------------------------------------------------------
	private:

		//########################## Step index data #########################

		// Index of current step
		long currentStepExecution_;

		// Current iteration of the execution
		long currentIteration_;

		// total number of steps
		long totalNumberOfSteps_;

		// Index of last step
		long lastStep_;

		// total number of repetitions
		long totalNumberIterations_;


	//--------------------------------------------------
	// public section
	//--------------------------------------------------
	public:


		//####################### CONSTRUCTOR #####################
		ControlIterator();

		// SequenceIterator(long totalNumberOfSteps);

		ControlIterator(int totalNumberIterations);

		ControlIterator(long currentStep, int totalNumberIterations);


		//########################## METHODS ############################
		// Method to reset the step indexes
		void init();

		// Method to set the step indexes to the first step
		void begin();

		// Method to increment the current step index
		void next();

		// Method to decrement the current step index
		void previous();

		// Method to increment the current repetition index
		void nextIteration();

		// Method to decrement the current repetition index
		void previousIteration();


		//########################## GETTER & SETTERS ############################
		// Method to get the current step index
		long getCurrentStepExecution();

		// Method to get the total number of steps
		long getTotalNumberOfSteps();

		// Method to get the last step
		long lastStep();

		// Method to get the total number of iterations
		long getTotalNumberIterations();

		// Method to set the current step index to the specified step
		void setCurrentStep(long currentStep);

		// Method to set the total number of steps and the last step
		void setTotalNumberOfSteps(long totalNumberOfSteps);

		// Method to set the total number of iterator
		void setTotalNumberIterations(long totalNumberIterations);


		//########################## METHODS TO VERIFY ############################
		// It returns true when the current step is equal to the total number of steps
		bool isAllProcessCompleted();

		// It returns true when the current step is equal to the total number of steps
		bool isEnd();

		// It returns true when the current repetition is equal to the total number of iterations
		bool isEndIterations();

		// It returns true when the current step is equal to the first step
		bool isFirst();

};

#endif // _SequenceIterator_h_

