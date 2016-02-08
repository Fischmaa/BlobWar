#include "Dvector.h"
#include <iostream>
#include <fstream>

int main()
{
	std::string name("tp1_test.txt");
	Dvector P = Dvector(name);
	P.display(std::cout);
	return 0 ;
}
