#include "Dvector.cpp"
#include <iostream>
#include <fstream>

int main()
{
  Dvector P(5,0.);
  P.display(std::cout);
  P.fillRandomly();
  P.display(std::cout);
	return 0 ;
}
