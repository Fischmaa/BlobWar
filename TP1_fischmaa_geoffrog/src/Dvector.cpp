#include "Dvector.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

Dvector::Dvector()
{
	this->dim = 1 ;
	this->vect = new double[dim];
	this->vect[0] = 0 ;
}
Dvector::Dvector(int d, double val = 0)
{
	this->dim = d;
	this->vect = new double[dim];
	for( int i=0; i < dim ; i++ ){
		this->vect[i]= val;
	}
}

Dvector::Dvector(const Dvector & P)
{
	dim=P.size();
	if(dim == 0) return;
	vect=new double[dim];
	for(int i=0;i<dim;i++){
		vect[i]=P.getVect(i);
	}
}

Dvector::Dvector(std::string name)
{
	std::ifstream file(name.c_str(),std::ios::in);
	std::vector<double> v(1,0.);
	double val ;
	if(file)
	{
		this->dim = 0;
		this->vect = NULL;
	}
	else
	{
		while(file>>val){
			v.push_back(val);
		}

		this->dim = v.size();
		this->vect = new double[dim];
		for( int i=0; i < dim ; i++ ){
			this->vect[i]= v[i];
		}

		file.close();
	}
}




int Dvector::size() const
{
	return dim;
}



double Dvector::getVect(int i) const
{
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

void Dvector::fillRandomly()
{
	for(int i=0;i<dim;i++){
		vect[i]= (double)rand() / (double)RAND_MAX ;
	}
}



