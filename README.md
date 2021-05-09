[![Maintenance](https://img.shields.io/badge/Maintained%3F-yes-green.svg)](https://gitHub.com/cguz/)
[![Eclipse](https://img.shields.io/badge/-Eclipse%20C%2FC%2B%2B-blueviolet)](https://eclipse.org/) 
[![Eclipse](https://img.shields.io/badge/-Cmake-success)](https://cmake.org/) 
[![Drawio](https://img.shields.io/badge/-Drawio-orange)](https://drawio-app.com/)
[![Codacy Badge](https://app.codacy.com/project/badge/Grade/79bf6932c2e844eea15d0fb1ed7e415c)](https://app.codacy.com/gh/cguz/task-management-service?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=ESMValGroup/ESMValTool&amp;utm_campaign=Badge_Grade)

# Task Management Service

<center><a href="http://visionspace.com/"><img src="https://user-images.githubusercontent.com/15159632/117484138-f7920900-af66-11eb-8def-6e9880860c4a.png" alt="VisionSpace" title="VisionSpace" height="100px" /></a></center>

Author: Cesar Augusto Guzman Alvarez [@cguz](https://github.com/cguz/)

[**Documentation**](https://task-management-service.readthedocs.io/en/latest/)

## Description

The goal of this service is to handle the execution of multiple types of Tasks. 

### Requirements

*   A Task can be executed instantly or can be scheduled for later execution;
*   A Task can be in one of the following states: QUEUED, RUNNING, SUCCESS, FAILED;
*   Failed Tasks shall not have any side effects;
*   A user can cancel Tasks using the Task Management Service.

### Examples of the Tasks to execute

*   Batch data load to a data warehouse;
*   Index files;
*   Send notifications.

## Solution

The proposed solution not only meets the requirements but also implements the following new functionalities:

*   Execute a task and/or a set of tasks.
*   Execute a task instantly or scheduled for later execution if more tasks are executing.
*   Implementation with thread to execute the tasks form the client side.
*   Prepare before execution the task or set of tasks to execute.
*   Simulate randomly the duration of a task. The duration can be a value between 0 and 5.
*   Simulate randomly the failure of a task. The task can fail with a probability of 0.05. 
*   Separate the task generation from the task execution. Allowing to add more tasks and monitor their execution easily.
*   Add two more states, CANCEL, and PAUSE (explained later).
*   Implement integration test. The Unit test can be implemented similarl way.

### Design

The design is in the folder ( 📁 ) ["design"](https://github.com/cguz/task-management-service/tree/main/design)

The class diagram is as follow:

<img src="https://raw.githubusercontent.com/cguz/task-management-service/4fb73a3c4c544c2f0ba223eb7c79e6f2c941b626/design/TaskManagementService.svg" alt="Architecture" title="Architecture" height="600px" />

The **ClientControl** class creates tasks sequence and executes one task or a set of tasks (tasks sequence).

The **ClientControl** generates the tasks sequence through the class  **SequenceTasksCatalogConstructor**, procedure build(id: short), where id is the identifier of the tasks sequence. 

The **SequenceTasksCatalogConstructor** class contains a catalog of task sequence factories. A tasks sequence factory (class **SequenceTasksFactory**) contains the necessary information to create one (class **Task**) or more tasks (class **SequenceTasks**) to be executed.

The **TaskManagementService** class is the start point to execute any task or task sequence.

We implemented the **SequenceTasks** (tasks sequence), **Task**, and **ITask** classes using the composite pattern. This pattern allows us to treat the **SequenceTasks** and **Task** classes as a single instance of the same **ITask** class. 

The **SequenceTasks** class controls the iteration of the tasks throughout the private variable **iterate**, which is an instance of the **ControllIterator** class. The **ControllIterator** class allows easy tracking of the current and previous tasks executed. The **SequenceTasks** class works like a queue.

The **TaskSendNotifications**, **TaskIndexFiles**, and **TaskBatchDataLoad** classes inherit from the class **Task** and implement Examples of the Tasks to execute Batch data load to a data warehouse; Index files; and Send notifications, respectively.

Finally, we applied a finite state machine (using the state design pattern) to control the execution state of the tasks. The state variable in the **ITask** class contains the current state. 

The state transition of a task's finite state machine is as follow:

<img src="https://raw.githubusercontent.com/cguz/task-management-service/b4911a248339fdd3fadec891f4efc77b691dc474/design/StateDiagram.svg" alt="State transition diagram" title="State transition diagram" height="400px" />

The states are:

*   QUEUED : means that the tasks are planned for their execution.
*   RUNNING : means that the tasks are executing.
*   SUCCESS : means that the tasks finish successfully.
*   FAILED : means that the task fails during its execution.

We added two more states:

*   CANCEL : means that the user cancels the task.
*   PAUSED : means that the task is stopped and can be resumed. 
  
## Development
The source code in C++ is in the folder ( 📁 ) ["src/cplusplus/"](https://github.com/cguz/task-management-service/tree/main/src/cplusplus). In that folder, we can find all the computational requirements needed to execute the code.

Since the repository contains submodules (google test library), please, clone the repository as follow:

    git clone --recurse-submodules -j8 https://github.com/cguz/task-management-service.git

Some examples of how to use the **ClientControl** class are in the files:

* "src/cplusplus/src/main.cpp"
* "src/cplusplus/tests/Integration-Test.cpp"

For instance, the method **testExecutionOneTask**:

    void testExecutionOneTask() {

      createClientControl();

      cout << "\n\n------------------------------------------" << endl;
      cout << "3. Choose the sequence task SEQ_TASKS_GROUP1 for execution" << endl;
      cout << "--------------------------------------------" << endl;

      controlClient->select(SequenceTasksCatalogConstructor::SEQ_TASKS_GROUP1);

      try {

        cout << "\n\n--------------------------------------------";
        cout << "\n4. START The execution of SEQ_TASKS_GROUP1 ";
        cout << "\n--------------------------------------------" << endl;

        controlClient->execute();

        cout << "\n\n-----------------------------------------";
        cout << "\n4. END The execution of SEQ_TASKS_GROUP1";
        cout << "\n-----------------------------------------" << endl;

      } catch(char const* exception) {
        cout << endl << exception << endl;
      }
    }
    
Select the tasks sequence **SEQ_TASKS_GROUP1** that contains only one dummy Task (see the factory file [TasksGroup1Factory.cpp](https://github.com/cguz/task-management-service/blob/main/src/cplusplus/src/TasksManagementService/Creational/Factories/TasksGroup1Factory.cpp)). Then, execute the task.

Anothe example is the method **testClientTasksAddNewOnePause**:

    void testClientTasksAddNewOnePause() {

      createClientControlCustomCatalog();

      cout << "\n\n-----------------------------------" << endl;
      cout << "3. Choose the sequence task SEQ_CUSTOM1 for execution" << endl;
      cout << "---------------------------------------" << endl;

      // SEQ_CUSTOM1 contains three tasks: 1.) Batch data load to a data warehouse;, 2) Index files; and 3) Send notifications.
      controlClient->select(CustomSequenceTasksCatalogConstructor::SEQ_CUSTOM1);

      try {

        cout << "\n\n--------------------------------------------";
        cout << "\n4. START The execution of SEQ_CUSTOM1 ";
        cout << "\n--------------------------------------------" << endl;

        // execute the tasks in parallel
        std::thread executeThread(&ClientControl::execute, std::ref(controlClient));
        executeThread.detach();

        // add the new task
        controlClient->add(new TaskIndexFile());

        // wait two seconds
        cout << endl <<"wait for 2 seconds "<<endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));

        // pause the execution of the tasks.
        controlClient->pause();

        // wait five seconds
        cout << "wait for 5 seconds "<<endl;
        std::this_thread::sleep_for(std::chrono::seconds(5));

        controlClient->execute();

        // wait until the tasks finish their execution
        std::this_thread::sleep_for(std::chrono::seconds(30));

        cout << "\n\n-----------------------------------------";
        cout << "\n4. END The execution of SEQ_CUSTOM1";
        cout << "\n-----------------------------------------" << endl;

      } catch(char const* exception) {
        cout << endl << exception << endl;
      }
    }
    
This method selects the tasks sequence **SEQ_TASKS_GROUP1** that contains three tasks: 1.) Batch data load to a data warehouse;, 2) Index files; and 3) Send notifications (see the factory file [CustomSeqExampleTasksToExecuteFactory.cpp](https://github.com/cguz/task-management-service/blob/main/src/cplusplus/src/TasksManagementService/CLIENT/Creational/Factories/CustomSeqExampleTasksToExecuteFactory.cpp)). 

Then, execute the task sequence using the std::thread. During execution add a new Task Index File, and wait for two seconds. Next, it pauses the task sequence for 5 seconds and executes it again. Finally, it waits for 30 seconds until the tasks sequence thread finishes.

