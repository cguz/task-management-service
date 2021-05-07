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

The class diagram is as follow:

<img src="https://user-images.githubusercontent.com/15159632/117512725-79e2f300-af90-11eb-8bde-8a369c86bd32.png" alt="Architecture" title="Architecture" height="600px" />
  
The state transition of a task is as follow:

<img src="https://raw.githubusercontent.com/cguz/task-management-service/708bc7b59824075c9531412f4b65caf8285127cd/design/StateDiagram.svg" alt="State transition diagram" title="State transition diagram" height="400px" />

The states are:

* QUEUED : means that the tasks are planned for their execution.
* RUNNING : means that the tasks are executing.
* SUCCESS : means that the tasks finish successfully.
* FAILED : means that the task fails during its execution.

We added two more states:

* CANCEL : means that the user cancels the task.
* PAUSED : means that the task is stopped and can be resumed. 
  
## Development

The source code in C++ is in the folder ( 📁 ) ["src/cplusplus/"](https://github.com/cguz/task-management-service/tree/main/src/cplusplus)

