BUILDER=g++
TARGET=ControlClient
DIR=src/TaskManagementService/

all: build

build:
	$(BUILDER) -o $(TARGET) $(DIR)main.cpp $(DIR)ClientControl.cpp $(DIR)*/*.cpp $(DIR)*/*/*.cpp $(DIR)*/*/*/*.cpp

execute:
	./$(TARGET)
