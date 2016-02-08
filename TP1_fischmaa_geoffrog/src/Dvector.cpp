#include "Dvector.h"
#include <iostream>
#include <fstream>
Dvector::Dvector()
{
	Dvector(0);
}
Dvector::Dvector(int d){
	Dvector(d, 0.);
}
Dvector::Dvector(int d, double val)
{
	this->dim = d;
	this->vect = new double[dim];
	for( int i=0; i < dim ; i++ ){
		this->vect[i]= val;
	}
}

Dvector::~Dvector()
{
	delete [] vect ;
}
void Dvector::display( std::ostream& str)
{
	for (int i = 0; i < dim ; i++){
		str << this->vect[i] << "\n" ;
	}
}
