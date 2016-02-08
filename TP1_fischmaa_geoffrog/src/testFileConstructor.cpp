#include "Dvector.h"
#include <iostream>
#include <fstream>

int main()
{	
	std::stringstream str;
	Dvector P = Dvector(5,2);
	P.display(str);
	Dvector Q = Dvector(str.str());
	Q.display(std::cout);
	return 0 ;
}
