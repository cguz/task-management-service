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

The proposed design not only meets the requirements, but ialso implements the following new functionalities:

* Execute a task and/or a set of tasks.
* Execute a task instantly or scheduled for later execution if there are more tasks executing.
* Prepare before execution the task or set of task to execute.
* Simulate randomly the duration of a task. The duration can be a value between 0 and 5.
* Simulate randomly the failure of a task. The task can fail with a probability of 0.05. 
* Separate the task generation from the task execution. Allowing to add more tasks and monitor its execution easily.
* Add two more states, CANCEL and PAUSE (explained later).


The design is in the folder ( 📁 ) ["design"](https://github.com/cguz/task-management-service/tree/main/design)

The class diagram is as follow:

<img src="https://user-images.githubusercontent.com/15159632/117512725-79e2f300-af90-11eb-8bde-8a369c86bd32.png" alt="Architecture" title="Architecture" height="600px" />

**ClientControl** class creates tasks sequence and executes one task or a set of tasks (tasks sequence).

The **ClientControl** generates the tasks sequence through the class  **SequenceTasksCatalogConstructor**, procedure build(id: short), where id is the identifier of the tasks sequence. 

**SequenceTasksCatalogConstructor** class contains a catalog of task sequence factories. A tasks sequence factory (class **SequenceTasksFactory**) contains the necessary information to create one (class **Task**) or more tasks (class **SequenceTasks**) to be executed.

**TaskManagementService** class is the start point to execute any task or task sequence.

We implemented the **SequenceTasks** (tasks sequence), **Task**, and **ITask** classes using the composite pattern. This pattern allows us to treat the **SequenceTasks** and **Task** classes as a single instance of the same **ITask** class. 

The **SequenceTasks** class controls the iteration of the tasks throughout the private variable **iterate**, which is an instance of the **ControllIterator** class. The **ControllIterator** class allows easy tracking of the current and previous tasks executed. 

The **TaskSendNotifications**, **TaskIndexFiles**, and **TaskBatchDataLoad** classes inherit from the class **Task** and implement Examples of the Tasks to execute Batch data load to a data warehouse; Index files; and Send notifications, respectively.

Finally, we applied a finite state machine (using the state design pattern) to control the execution state of the tasks. The state variable in the **ITask** class contains the current state. 

The state transition of a task's finite state machine is as follow:

<img src="https://raw.githubusercontent.com/cguz/task-management-service/b4911a248339fdd3fadec891f4efc77b691dc474/design/StateDiagram.svg" alt="State transition diagram" title="State transition diagram" height="400px" />

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

