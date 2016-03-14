CXX = g++
CXXFLAGS = -Wall -g
TARGET = simpleConstructor copyConstructor fileConstructor size fill operator resize chevron comparaisonegal
SOURCES = testComparaisonEgal.cpp testresize.cpp testChevron.cpp testOperator.cpp testSimpleConstructor.cpp testCopyConstructor.cpp testFileConstructor.cpp testSize.cpp testFill.cpp Dvector.cpp Darray.cpp
OBJETS = $(SOURCES:.cpp=.o) 

all: $(TARGET)

simpleConstructor: Darray.o Dvector.o testSimpleConstructor.o
	$(CXX) $(CXXFLAGS) -o $@ Darray.o Dvector.o testSimpleConstructor.o

copyConstructor: Darray.o Dvector.o testCopyConstructor.o
	$(CXX) $(CXXFLAGS) -o $@ Darray.o Dvector.o testCopyConstructor.o

fileConstructor: Darray.o Dvector.o testFileConstructor.o
	$(CXX) $(CXXFLAGS) -o $@ Darray.o Dvector.o testFileConstructor.o

size: Darray.o Dvector.o testSize.o
	$(CXX) $(CXXFLAGS) -o $@ Darray.o Dvector.o testSize.o

fill: Darray.o Dvector.o testFill.o
	$(CXX) $(CXXFLAGS) -o $@ Darray.o Dvector.o testFill.o

operator: Darray.o Dvector.o testOperator.o
	$(CXX) $(CXXFLAGS) -o $@ Darray.o Dvector.o testOperator.o
	
resize: Darray.o Dvector.o testresize.o
	$(CXX) $(CXXFLAGS) -o $@ Darray.o Dvector.o testresize.o	

chevron: Darray.o Dvector.o testChevron.o
	$(CXX) $(CXXFLAGS) -o $@ Darray.o Dvector.o testChevron.o
	
comparaisonegal: Darray.o Dvector.o testComparaisonEgal.o
	$(CXX) $(CXXFLAGS) -o $@ Darray.o Dvector.o testComparaisonEgal.o	
	
check: $(TARGET)
	./simpleConstructor && ./copyConstructor && ./fileConstructor && ./size && ./fill

clean:
	rm $(TARGET) $(OBJETS)