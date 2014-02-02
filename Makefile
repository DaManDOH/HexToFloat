CC=g++
CFLAGS=--std=c++11 -Wall -Wextra -O2
CDBGFLAGS=-g -ggdb
SOURCES=main.cpp
OBJECTS=$(SOURCES:.cpp=.o)
TARGET=h2f
DEBUGTARGET=$(TARGET)_d

all: $(SOURCES) $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

debug:
	$(CC) $(CFLAGS) $(CDBGFLAGS) -o $(DEBUGTARGET) $(SOURCES)

clean:
	rm -rf *.o $(TARGET) $(DEBUGTARGET)
