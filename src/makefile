# the compiler: gcc for C program, define as g++ for C++
CC = g++
 
# compiler flags:
#  -g     - this flag adds debugging information to the executable file
#  -Wall  - this flag is used to turn on most compiler warnings
CFLAGS  = -g -Wall -std=c++11
COMP =  lexer.o symbole.o etat.o automate.o main.o
LDLIBS+=-lstdc++ 
 
# The build target 
TARGET = main

etat.o: etat.cpp etat.h 
	$(CC) -c $(CFLAGS) etat.cpp
automate.o: automate.cpp automate.h 
	$(CC) -c $(CFLAGS) automate.cpp
lexer.o: lexer.cpp lexer.h 
	$(CC) -c $(CFLAGS)  lexer.cpp
symbole.o: symbole.cpp symbole.h
	$(CC) -c $(CFLAGS) symbole.cpp 
main.o: main.cpp lexer.h 
	$(CC) -c $(CFLAGS) main.cpp
	
$(TARGET): $(COMP) 
	$(CC) $(CFLAGS) $(COMP) -o $(TARGET)

clean:
	rm *.o

run: clean $(TARGET)
	./main
