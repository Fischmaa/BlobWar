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

Dvector::Dvector(const Dvector & P){
  dim=P.Getdim();
  if(dim == 0) return;
  vect=new double[dim];
  for(int i=0;i<dim;i++){
    vect[i]=P.Getvect(i);
  }
}



int Dvector::Getdim() const {
  return dim;
}



double Dvector::Getvect(int i) const {
  return vect[i];
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



