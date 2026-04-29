CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -O2
TARGET = dictionary
SOURCES = main.cpp dictionary.cpp
HEADERS = dictionary.h
OBJECTS = $(SOURCES:.cpp=.o)

# Default target
all: $(TARGET)

# Build the executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Compile source files to object files
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up compiled files
clean:
	rm -f $(OBJECTS) $(TARGET)

# Run the program
run: $(TARGET)
	./$(TARGET)

# Rebuild
rebuild: clean all

.PHONY: all clean run rebuild
