CXX=g++
CFLAGS=-std=c++20 -Wall

all : main.o mirrorer.o mirroredOutput.o
	$(CXX) $(CFLAGS) main.o mirrorer.o mirroredOutput.o -o mirror

main.o : main.cpp mirrorer.hpp
	$(CXX) $(CFLAGS) -c main.cpp

mirrorer.o : mirrorer.cpp mirrorer.hpp mirroredOutput.hpp
	$(CXX) $(CFLAGS) -c mirrorer.cpp

mirroredOutput.o : mirroredOutput.cpp mirroredOutput.hpp
	$(CXX) $(CFLAGS) -c mirroredOutput.cpp

clean :
	rm *.o