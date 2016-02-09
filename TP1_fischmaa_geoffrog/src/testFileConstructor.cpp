#include "Dvector.h"
#include <iostream>
#include <fstream>
#include <cassert>
#include <sstream>
using namespace std;


int main()
{
	std::string name("tp1_test.txt");
	Dvector P = Dvector(name);
	P.display(std::cout);
	return 0 ;
}
