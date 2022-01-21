# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g     - this flag adds debugging information to the executable file
#  -Wall  - this flag is used to turn on most compiler warnings
CFLAGS  = -g -Wall -std=c++11
OBJECTS =  main.cpp lexer.cpp symbole.cpp
COMP = lexer.o symbole.o main.o
LDLIBS+=-lstdc++

# The build target
TARGET = main

E0.o: E0.cpp E0.h
	$(CC) -c $(CFLAGS)  E0.cpp
Etat.o: Etat.cpp Etat.h
	$(CC) -c $(CFLAGS) Etat.cpp
main.o: main.cpp E0.h
	$(CC) -c $(CFLAGS) main.cpp
$(TARGET): $(COMP)
	$(CC) $(CFLAGS) $(COMP) -o $(TARGET)

clean:
	rm *.o