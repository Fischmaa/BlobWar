CXX = g++
CXXFLAGS = -Wall -g
TARGET = simpleConstructor copyConstructor fileConstructor size fill operator resize chevron comparaisonegal
SOURCES = testComparaisonEgal.cpp testresize.cpp testChevron.cpp testOperator.cpp testSimpleConstructor.cpp testCopyConstructor.cpp testFileConstructor.cpp testSize.cpp testFill.cpp Dvector.cpp 
OBJETS = $(SOURCES:.cpp=.o)

all: $(TARGET)

simpleConstructor: Dvector.o testSimpleConstructor.o
	$(CXX) $(CXXFLAGS) -o $@ Dvector.o testSimpleConstructor.o

copyConstructor: Dvector.o testCopyConstructor.o
	$(CXX) $(CXXFLAGS) -o $@ Dvector.o testCopyConstructor.o

fileConstructor: Dvector.o testFileConstructor.o
	$(CXX) $(CXXFLAGS) -o $@ Dvector.o testFileConstructor.o

size: Dvector.o testSize.o
	$(CXX) $(CXXFLAGS) -o $@ Dvector.o testSize.o

fill: Dvector.o testFill.o
	$(CXX) $(CXXFLAGS) -o $@ Dvector.o testFill.o

operator: Dvector.o testOperator.o
	$(CXX) $(CXXFLAGS) -o $@ Dvector.o testOperator.o
	
resize: Dvector.o testresize.o
	$(CXX) $(CXXFLAGS) -o $@ Dvector.o testresize.o	

chevron: Dvector.o testChevron.o
	$(CXX) $(CXXFLAGS) -o $@ Dvector.o testChevron.o
	
comparaisonegal: Dvector.o testComparaisonEgal.o
	$(CXX) $(CXXFLAGS) -o $@ Dvector.o testComparaisonEgal.o	
	
check: $(TARGET)
	./simpleConstructor && ./copyConstructor && ./fileConstructor && ./size && ./fill

clean:
	rm $(TARGET) $(OBJETS)