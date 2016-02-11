#include "Dvector.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

Dvector::Dvector()
{
	std::cout << "Appel de Dvector() \n";
	this->dim = 0 ;
	this->vect = NULL;	
}

Dvector::Dvector(int d, double val )
{	
	std::cout << "Appel de Dvector(int d, double val = 0.0) \n";
	this->dim = d;
	this->vect = new double[dim];
	for( int i=0; i < dim ; i++ ){
		this->vect[i]= val;
	}
}

Dvector::Dvector(const Dvector & P)
{
	std::cout << "Appel de Dvector(const Dvector & P) \n";
	dim=P.size();
	if(dim == 0) return;
	vect=new double[dim];
	for(int i=0;i<dim;i++){
		vect[i]=P.getVect(i);
	}
}

Dvector::Dvector(const std::string& name)
{
	std::cout << "Appel de Dvector(std::string name) \n";
	std::ifstream file(name.c_str(),std::ios::in);
	std::vector<double> v;
	double val ;
	if(!file)
	{
		std::cout << "Echec de l'ouverture du fichier : "<< name << "\n";
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

double Dvector::operator()(int i){	
	return this->vect[i];
}


