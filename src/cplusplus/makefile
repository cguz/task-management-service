BUILDER=g++
TARGET=prototipo
DIR=TaskManagementService/

all: build

build:
	$(BUILDER) -o $(TARGET) $(DIR)main.cpp $(DIR)Sequencer.cpp $(DIR)*/*.cpp $(DIR)*/*/*.cpp $(DIR)*/*/*/*.cpp

execute:
	./$(TARGET)
