CXX = g++
CXXFLAGS = -O2 -Wall -g
EXECUTABLE = exe 
SOURCES = main.cpp
OBJETS = $(SOURCES:.cxx=.o)

$(EXECUTABLE): $(OBJETS)
	$(CXX) $(CXXFLAGS) -o $@ $^ 

.cxx.o: 
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -f $(EXECUTABLE) *.o