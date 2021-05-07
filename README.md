# Task Management Service

![image](https://user-images.githubusercontent.com/15159632/117484138-f7920900-af66-11eb-8def-6e9880860c4a.png)

Author: [Cesar Augusto Guzman Alvarez](https://github.com/cguz/)

## Description

The goal of this service is to handle the execution of multiple types of Tasks. 

### Requirements

* A Task can be executed instantly or can be scheduled for later execution;
* A Task can be in one of the following states: QUEUED, RUNNING, SUCCESS, FAILED;
* Failed Tasks shall not have any side effects;
* A user can cancel Tasks using the Task Management Service.

### Examples of the Tasks to execute:

* Batch data load to a data warehouse;
* Index files;
* Send notifications.


## Design 

![architecture](https://raw.githubusercontent.com/cguz/task-management-service/d641f146654b114cfcdb7c2f84192080cbe7e9c6/design/TaskManagementService.svg)

## Development

The source code in C++ is in the 📁 "src/cplusplus/"

