#include "Dvector.h"
#include <ctime>
#include <cstdlib>
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
  dim=P.size();
  if(dim == 0) return;
  vect=new double[dim];
  for(int i=0;i<dim;i++){
    vect[i]=P.getVect(i);
  }
}



int Dvector::size() const {
  return dim;
}



double Dvector::getVect(int i) const {
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


void Dvector::fillRandomly (){
  for(int i=0;i<dim;i++){
  vect[i]= (double)rand() / (double)RAND_MAX ;
}



}
