#include "Dvector.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cassert>

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

double Dvector::operator()(int i) const{	
	assert(i>0 && i<=(this->size()-1));
	return this->vect[i];
}

double& Dvector::operator()(int i){
	assert(i>0 && i<=(this->size()-1));
	return this->vect[i];
}

Dvector Dvector::operator+(const Dvector& elem){
	assert(elem.size() == this->size());
	Dvector res(this->size());
	for (int i = 0; i < this->size() ; i++){
		res.vect[i]=this->vect[i] + elem.vect[i];
	}
	return res ;
}

Dvector Dvector::operator+(const double val){
	Dvector res(this->size());
	for (int i = 0; i < this->size() ; i++){
		res.vect[i] = this->vect[i] + val;
	}
	return res ;
}

void Dvector::operator+=(const Dvector&  elem){
	assert(elem.size() == this->size());
	for (int i = 0; i < this->size() ; i++){
		this->vect[i] += elem.vect[i];
	}

}

void Dvector::operator+=(const double val){
	for (int i = 0; i < this->size() ; i++){
		this->vect[i] += val;
	}

}

Dvector Dvector::operator-(const Dvector& elem){
	assert(elem.size() == this->size());
	Dvector res(this->size());
	for (int i = 0; i < this->size() ; i++){
		res.vect[i]=this->vect[i] - elem.vect[i];
	}
	return res ;
}

Dvector Dvector::operator-(const double val){
	Dvector res(this->size());
	for (int i = 0; i < this->size() ; i++){
		res.vect[i] = this->vect[i] - val;
	}
	return res ;
}

void Dvector::operator-=(const Dvector&  elem){
	assert(elem.size() == this->size());
	for (int i = 0; i < this->size() ; i++){
		this->vect[i] -= elem.vect[i];
	}

}

void Dvector::operator-=(const double val){
	for (int i = 0; i < this->size() ; i++){
		this->vect[i] -= val;
	}

}

Dvector Dvector::operator-(){
	for (int i = 0; i < this->size() ; i++){
		this->vect[i] = -this->vect[i] ;
	}
	return *this ;
}

Dvector Dvector::operator*(const double val){
	for (int i = 0; i < this->size() ; i++){
		this->vect[i] *= val;
	}
	return *this ;
}

void Dvector::operator*=(const double val){
	for (int i = 0; i < this->size() ; i++){
		this->vect[i] *= val;
	}
}

Dvector Dvector::operator/(const double val){
	for (int i = 0; i < this->size() ; i++){
		this->vect[i] /= val;
	}
	return *this ;
}

void Dvector::operator/=(const double val){
	for (int i = 0; i < this->size() ; i++){
		this->vect[i] /= val;
	}
}

bool Dvector::operator==(const Dvector elem){
	if(this->size()!=elem.size()){
		return false;
	}
	else{
		bool res = true;
		for(int i = 0 ; i< this->size();i++){
			if(this->vect[i] != elem.vect[i]){
				res = false ;
				i=this->size() - 1 ; // on sort de la boucle for ( a revoir)
			}
		}
		return res;
	}

}

bool Dvector::operator!=(const Dvector elem){
	bool res = *this==(elem);
	return !res;
}

