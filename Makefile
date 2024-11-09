CXX = g++
CXXFLAGS = -std=c++17 -Wall
all: library

library: main.o library.o book.o
	$(CXX) $(CXXFLAGS) -o library main.o library.o book.o

main.o: main.cpp library.h book.h
	$(CXX) $(CXXFLAGS) -c main.cpp

library.o: library.cpp library.h book.h
	$(CXX) $(CXXFLAGS) -c library.cpp

book.o: book.cpp book.h
	$(CXX) $(CXXFLAGS) -c book.cpp

clean:
	rm -f *.o library
