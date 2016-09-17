CFLAGS=-Wall -Werror -std=c++0x -g
SOURCES=HeaderComparison.cpp main.cpp Person.cpp Sort.cpp Stats.cpp Tests.cpp
EXECUTABLE=Main

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(SOURCES)
	g++ $(CFLAGS) $(SOURCES) -o $(EXECUTABLE)

clean:
	rm Main
