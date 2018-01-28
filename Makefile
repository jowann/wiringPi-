# Declaration of variables
CC = g++
CC_FLAGS = -Wall
INCPATH=-I.
# File names
EXEC = run
SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)

# Main target
$(EXEC): $(OBJECTS)
	$(CC)   $(OBJECTS) -lwiringPi -lpthread -o $(EXEC)

# To obtain object files
%.o: %.cpp %.hpp
	$(CC) $(INCPATH) -c $(CC_FLAGS) $< -o $@

# To remove generated files
clean:
	rm -f $(EXEC) $(OBJECTS)
