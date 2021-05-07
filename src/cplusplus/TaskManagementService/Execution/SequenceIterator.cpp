/*
 * SequenceIterator.cpp
 *
 *  Created on: 07 may. 2021
 *
 *  Author: Cesar Augusto Guzman
 *  Email: cguzwork@cguz.org
 */

// Includes
#include "SequenceIterator.h"

#include <math.h>


//####################### CONSTRUCTOR #####################
//----------------------------------------------------------------------
// Constructor
//----------------------------------------------------------------------
SequenceIterator::SequenceIterator() {
	init();
	totalNumberOfSteps_ = 0;
	lastStep_ = totalNumberOfSteps_-1;
}
/*
SequenceIterator::SequenceIterator(long totalNumberOfSteps) : totalNumberOfSteps_(totalNumberOfSteps) {
	init();
	totalNumberIterations_ = 1;
	lastStep_ = totalNumberOfSteps_-1;
}
*/
SequenceIterator::SequenceIterator(int totalNumberIterations) : totalNumberIterations_(totalNumberIterations) {
	init();
	totalNumberOfSteps_ = 0;
	lastStep_ = totalNumberOfSteps_-1;
}

SequenceIterator::SequenceIterator(long currentStep, int totalNumberIterations) : totalNumberIterations_(totalNumberIterations) {
	currentIteration_ = 0;
	currentStepExecution_ = currentStep;
	totalNumberOfSteps_=0;
	lastStep_ = totalNumberOfSteps_-1;
}


//########################## METHODS ############################
void SequenceIterator::init()
{
	currentStepExecution_ = -1;
	currentIteration_ = 0;
}

void SequenceIterator::begin()
{
	currentStepExecution_ = 0;
}

void SequenceIterator::next()
{
	currentStepExecution_++;
}

void SequenceIterator::previous()
{
	currentStepExecution_--;
}

void SequenceIterator::nextIteration()
{
	currentIteration_++;
}

void SequenceIterator::previousIteration()
{
	currentIteration_--;
}


//########################## GETTER & SETTERS ############################
long SequenceIterator::getCurrentStepExecution()
{
	return currentStepExecution_;
}

long SequenceIterator::getTotalNumberOfSteps()
{
	return totalNumberOfSteps_;
}

long SequenceIterator::lastStep()
{
	return lastStep_;
}

long SequenceIterator::getTotalNumberIterations()
{
	return totalNumberIterations_;
}

void SequenceIterator::setCurrentStep(long currentStep)
{
	currentStepExecution_ = currentStep;
}

void SequenceIterator::setTotalNumberOfSteps(long totalNumberOfSteps)
{
	totalNumberOfSteps_ = totalNumberOfSteps;
	lastStep_ = totalNumberOfSteps_-1; //The index changes from 0 to totalNumberOfSteps_-1
}

void SequenceIterator::setTotalNumberIterations(long totalNumberIterations)
{
	totalNumberIterations_ = totalNumberIterations;
}


//########################## METHODS TO VERIFY ############################
bool SequenceIterator::isAllProcessCompleted()
{
	return  (isEnd() && isEndIterations());
}

bool SequenceIterator::isEnd()
{
	// cout << endl << "("<<stepExecution_<<" == "<<totalNumberOfSteps_<<")"<<endl;
	return (currentStepExecution_ == totalNumberOfSteps_);
}

bool SequenceIterator::isEndIterations() {
	return (currentIteration_ == totalNumberIterations_);
}

bool SequenceIterator::isFirst()
{
	return (currentStepExecution_ == 0);
}
