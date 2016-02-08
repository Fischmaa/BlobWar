#include "Dvector.cpp"
#include <iostream>
#include <fstream>

int main()
{

	//Dvector V = Dvector("test.txt");
	// Dvector V = Dvector(4);
	// V.display(std::cout);

  Dvector P(5,0.);
  P.display(std::cout);
  P.fillRandomly();
  P.display(std::cout);

	return 0 ;
}
