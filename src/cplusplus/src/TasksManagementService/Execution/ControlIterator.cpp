/*
 * ControlIterator.cpp
 *
 *  Created on: 07 may. 2021
 *
 *  Author: Cesar Augusto Guzman
 *  Email: cguzwork@cguz.org
 */

// Includes
#include "ControlIterator.h"

#include <math.h>


//####################### CONSTRUCTOR #####################
//----------------------------------------------------------------------
// Constructor
//----------------------------------------------------------------------
ControlIterator::ControlIterator() {
	init();
	totalNumberOfSteps_ = 0;
	lastStep_ = totalNumberOfSteps_-1;
	totalNumberIterations_ = 1;
}

ControlIterator::ControlIterator(int totalNumberIterations) : totalNumberIterations_(totalNumberIterations) {
	init();
	totalNumberOfSteps_ = 0;
	lastStep_ = totalNumberOfSteps_-1;
}

ControlIterator::ControlIterator(long currentStep, int totalNumberIterations) : totalNumberIterations_(totalNumberIterations) {
	currentIteration_ = 0;
	currentStepExecution_ = currentStep;
	totalNumberOfSteps_=0;
	lastStep_ = totalNumberOfSteps_-1;
}


//########################## METHODS ############################
void ControlIterator::init()
{
	currentStepExecution_ = -1;
	currentIteration_ = 0;
}

void ControlIterator::begin()
{
	currentStepExecution_ = 0;
}

void ControlIterator::next()
{
	currentStepExecution_++;
}

void ControlIterator::previous()
{
	currentStepExecution_--;
}

void ControlIterator::nextIteration()
{
	currentIteration_++;
}

void ControlIterator::previousIteration()
{
	currentIteration_--;
}


//########################## GETTER & SETTERS ############################
long ControlIterator::getCurrentStepExecution()
{
	return currentStepExecution_;
}

long ControlIterator::getTotalNumberOfSteps()
{
	return totalNumberOfSteps_;
}

long ControlIterator::lastStep()
{
	return lastStep_;
}

long ControlIterator::getTotalNumberIterations()
{
	return totalNumberIterations_;
}

void ControlIterator::setCurrentStep(long currentStep)
{
	currentStepExecution_ = currentStep;
}

void ControlIterator::setTotalNumberOfSteps(long totalNumberOfSteps)
{
	totalNumberOfSteps_ = totalNumberOfSteps;
	lastStep_ = totalNumberOfSteps_-1; //The index changes from 0 to totalNumberOfSteps_-1
}

void ControlIterator::setTotalNumberIterations(long totalNumberIterations)
{
	totalNumberIterations_ = totalNumberIterations;
}


//########################## METHODS TO VERIFY ############################
bool ControlIterator::isAllProcessCompleted()
{
	return  (isEnd() && isEndIterations());
}

bool ControlIterator::isEnd()
{
	// cout << endl << "("<<stepExecution_<<" == "<<totalNumberOfSteps_<<")"<<endl;
	return (currentStepExecution_ == totalNumberOfSteps_);
}

bool ControlIterator::isEndIterations() {
	return (currentIteration_ == totalNumberIterations_);
}

bool ControlIterator::isFirst()
{
	return (currentStepExecution_ == 0);
}
