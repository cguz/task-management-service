[![Cplusplus](https://img.shields.io/badge/C%2B%2B-11-blue)](https://isocpp.org/)
[![eclipse](https://img.shields.io/badge/Eclipse-2020%E2%80%9112-orange)](https://www.eclipse.org) 
[![debian](https://img.shields.io/badge/-Debian-red)](https://www.debian.org) 
[![Google Test](https://img.shields.io/badge/-GTest-green)](ampus121.unad.edu.co/) 


# Requirements

* Linux 4.19.0-16-amd64. Debian 4.19.181-1 (2021-03-19)
* cmake version 3.13.4 : it can be installed executing as root the next command "apt install cmake".
* Eclipse IDE for C/C++ Version: 2021-03 (4.19.0)
* C/C++ CMake Build Support - Preview	10.2.0.202012191711	org.eclipse.cdt.cmake.feature.group	Eclipse CDT
* Google Test library - Release 1.10.x. It is added as a submodule in the GitHub. 


  > With version 2.13 of Git and later, --recurse-submodules can be used instead of --recursive:

  > git clone --recurse-submodules -j8 git://github.com/foo/bar.git
  > cd bar

  > Editor’s note: -j8 is an optional performance optimization that became available in version 2.8, and fetches up to 8 submodules at a time in parallel — see man git-clone.

  > With version 1.9 of Git up until version 2.12 (-j flag only available in version 2.8+):

  > git clone --recursive -j8 git://github.com/foo/bar.git
  cd bar

  > With version 1.6.5 of Git and later, you can use:

  > git clone --recursive git://github.com/foo/bar.git
  cd bar

  > For already cloned repos, or older Git versions, use:

  > git clone git://github.com/foo/bar.git
  > cd bar
  > git submodule update --init --recursive


# Code

The code is in the folder ( 📁 ) ["TaskManegementService"](https://github.com/cguz/task-management-service/tree/main/src/cplusplus/TaskManagementService).


The following rules are in the Makefile. They can be run automatically from eclipse. 

## Makefile

- [build](#build)
- [run](#run)
- [integrationTest](#integrationTest)

## build

g++ -o ControlClient TaskManagementService/main.cpp TaskManagementService/Control.cpp TaskManagementService/\*/\*.cpp TaskManagementService/\*/\*/\*.cpp TaskManagementService/\*/\*/\*/\*.cpp


## run

  ./ControlClient

## integrationTest

  cd build && cmake .. -DCMAKE_BUILD_TYPE=Debug -G "Unix Makefiles" && make all && ./tests/TasksManagementService_test
