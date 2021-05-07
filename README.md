[![Eclipse](https://img.shields.io/badge/-Eclipse%20C%2FC%2B%2B-blueviolet)](https://eclipse.org/) 
[![Eclipse](https://img.shields.io/badge/-Cmake-success)](https://cmake.org/) 
[![Drawio](https://img.shields.io/badge/-Drawio-orange)](https://drawio-app.com/)

# Task Management Service

<center><a href="http://visionspace.com/"><img src="https://user-images.githubusercontent.com/15159632/117484138-f7920900-af66-11eb-8def-6e9880860c4a.png" alt="VisionSpace" title="VisionSpace" height="100px" /></a></center>

Author: Cesar Augusto Guzman Alvarez [@cguz](https://github.com/cguz/)

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

The design is in the folder ( 📁 ) ["design"](https://github.com/cguz/task-management-service/tree/main/design)

<img src="https://raw.githubusercontent.com/cguz/task-management-service/cf0e94b9e0b9cd48a27c5dfd90e71d97d41bca5c/design/TaskManagementService.svg" alt="Architecture" title="Architecture" height="600px" />
  
## Development

The source code in C++ is in the folder ( 📁 ) ["src/cplusplus/"](https://github.com/cguz/task-management-service/tree/main/src/cplusplus)

