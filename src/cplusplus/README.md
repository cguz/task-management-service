[![Cplusplus](https://img.shields.io/badge/C%2B%2B-11-blue)](https://isocpp.org/)
[![eclipse](https://img.shields.io/badge/Eclipse-2020%E2%80%9112-orange)](https://www.eclipse.org) 


# Requirements

* Eclipse IDE for C/C++ Version: 2021-03 (4.19.0)

# Code

The code is in the folder ( 📁 ) ["TaskManegementService"](https://github.com/cguz/task-management-service/tree/main/src/cplusplus/TaskManagementService).


The following two rules are in the Makefile

## Makefile

- [build](#build)
- [run](#run)

## build

g++ -o ControlClient TaskManagementService/main.cpp TaskManagementService/Control.cpp TaskManagementService/*/*.cpp TaskManagementService/*/*/*.cpp TaskManagementService/*/*/*/*.cpp


## run

./ControlClient

