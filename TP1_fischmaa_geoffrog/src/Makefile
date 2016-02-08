CXX = g++
CXXFLAGS = -O2 -Wall -g
TARGET = main.o 
SOURCES = main.cpp Dvector.cpp
OBJETS = $(SOURCES:.cxx=.o)

main: main.o
	$(CXX) $(CXXFLAGS) -o $@ $^ 

clean:
	rm -f $(TARGET) *.o