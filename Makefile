CC=g++
CFLAGS=-std=c++20 -Wall

all : main.o mirrorer.o
	$(CC) $(CFLAGS) main.o mirrorer.o -o mirror

main.o : main.cpp mirrorer.hpp
	$(CC) $(CFLAGS) -c main.cpp

mirrorer.o : mirrorer.cpp mirrorer.hpp
	$(CC) $(CFLAGS) -c mirrorer.cpp

clean :
	rm *.o