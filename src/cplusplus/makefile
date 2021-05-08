BUILDER=g++
TARGET=ControlClient
PROJECT=TasksManagementService
DIR=src/$(PROJECT)/

all: build

build:
	$(BUILDER) -o $(TARGET) $(DIR)main.cpp $(DIR)ClientControl.cpp $(DIR)*/*.cpp $(DIR)*/*/*.cpp $(DIR)*/*/*/*.cpp

execute:
	./$(TARGET)

IntegrationTest:
	cd build && cmake .. -DCMAKE_BUILD_TYPE=Debug -G "Unix Makefiles" && make all && ./tests/$(PROJECT)_test