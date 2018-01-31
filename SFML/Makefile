CXX=g++
CXXFLAGS=-std=c++11 -g -Wall -Wextra -Wpedantic
CC=$(CXX)
CFLAGS=
LDFLAGS=-lsfml-graphics -lsfml-window -lsfml-system
CPPFLAGS=
SOURCES=cannonball.cpp utilities.cpp game.cpp GameObjects.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=game

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)

.PHONY: clean
clean:
	$(RM) $(OBJECTS) $(EXECUTABLE)
