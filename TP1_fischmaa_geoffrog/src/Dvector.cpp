#include "Dvector.h"
#include <iostream>
#include <fstream>
Dvector::Dvector()
{
	Dvector(0.);
}
Dvector::Dvector(double d)
{
	dim = d;
	vect = new double[d];
	for(int i=0; i<dim;i++){
		vect[i]=0;
	}
}

Dvector::~Dvector()
{
	delete [] vect ;
}
Dvector::display( std::ostream& str)
{
	std::
}
