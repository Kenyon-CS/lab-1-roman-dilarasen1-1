# Variables
CXX = g++
CXXFLAGS = -Wall -std=c++11

# Target executable
TARGET = roman_program

# Source files
SRCS = main.cpp Roman.cpp

# Object files
OBJS = main.o Roman.o

# Default target
all: $(TARGET)

# Rule to link object files and create the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile main.cpp into main.o
main.o: main.cpp Roman.h
	$(CXX) $(CXXFLAGS) -c main.cpp

# Rule to compile Roman.cpp into Roman.o
Roman.o: Roman.cpp Roman.h
	$(CXX) $(CXXFLAGS) -c Roman.cpp

# Clean up build files
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets (targets that aren't actual files)
.PHONY: all clean
