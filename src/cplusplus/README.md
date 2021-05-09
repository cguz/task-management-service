[![Cplusplus](https://img.shields.io/badge/C%2B%2B-11-blue)](https://isocpp.org/)
[![eclipse](https://img.shields.io/badge/Eclipse-2020%E2%80%9112-orange)](https://www.eclipse.org) 
[![debian](https://img.shields.io/badge/-Debian-red)](https://www.debian.org) 
[![Google Test](https://img.shields.io/badge/-GTest-green)](ampus121.unad.edu.co/) 
[![Codacy Badge](https://app.codacy.com/project/badge/Grade/79bf6932c2e844eea15d0fb1ed7e415c)](https://app.codacy.com/gh/cguz/task-management-service?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=ESMValGroup/ESMValTool&amp;utm_campaign=Badge_Grade)

# Source code

## Requirements

*   Linux 4.19.0-16-amd64. Debian 4.19.181-1 (2021-03-19)
*   cmake version 3.13.4 : it can be installed executing as root the next command "apt install cmake".
*   Eclipse IDE for C/C++ Version: 2021-03 (4.19.0)
*   C/C++ CMake Build Support - Preview	10.2.0.202012191711	org.eclipse.cdt.cmake.feature.group	Eclipse CDT
*   Google Test library - Release 1.10.x. It is added as a submodule in the GitHub. 

  > With version 2.13 of Git and later, --recurse-submodules can be used instead of --recursive:

      git clone --recurse-submodules -j8 https://github.com/cguz/task-management-service.git

  > -j8 is an optional performance optimization that became available in version 2.8, and fetches up to 8 submodules at a time in parallel — see man git-clone.

  > With version 1.9 of Git up until version 2.12 (-j flag only available in version 2.8+):

      git clone --recursive -j8 https://github.com/cguz/task-management-service.git

  > With version 1.6.5 of Git and later, you can use:

      git clone --recursive https://github.com/cguz/task-management-service.git

  > For already cloned repos, or older Git versions, use:

      git clone https://github.com/cguz/task-management-service.git
      cd task-management-service
      git submodule update --init --recursive

## Code

The code is in the folder ( 📁 ) ["TaskManegementService"](https://github.com/cguz/task-management-service/tree/main/src/cplusplus/TaskManagementService).

The following rules are in the Makefile. They can be run automatically from eclipse. 

The folder ( 📁 ) ["build"](https://github.com/cguz/task-management-service/tree/main/src/cplusplus/build) is necessary to execute the **IntegrationTest**.

To execute the **build** and **execute** command of the makefile please remove the folder ( 📁 ) "build". 

## Makefile

*   [build](#build)
*   [run](#run)
*   [integrationTest](#integrationTest)

## build

Compile the source code

    g++ -pthread -o ControlClient TaskManagementService/main.cpp TaskManagementService/Control.cpp TaskManagementService/\*/\*.cpp TaskManagementService/\*/\*/\*.cpp TaskManagementService/\*/\*/\*/\*.cpp

## run

Execute the main of the ControlClient 

    ./ControlClient

## integrationTest

Compile and execute all the integration tests.

    cd build && cmake .. -DCMAKE_BUILD_TYPE=Debug -G "Unix Makefiles" && make all && ./tests/TasksManagementService_test
