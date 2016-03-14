/* 
 * File:   Darray.cpp
 * Author: geoffrog
 * 
 * Created on 11 mars 2016, 16:16
 */

#include "Darray.h"
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
#include <string> 
#include <vector>
#include <cassert>
using namespace std;

Darray::Darray()
{
	std::cout << "Appel de Darray() \n";
	this->dim = 0 ;
	this->vect = NULL;	
}

Darray::Darray(int d, double val )
{	
	std::cout << "Appel de Darray(int d, double val = 0.0) \n";
	this->dim = d;
        if(dim==0){
            this->vect=NULL;
        }
	this->vect = new double[dim];
	for( int i=0; i < dim ; i++ ){
		this->vect[i]= val;
	}
}

Darray::Darray(const Darray & P)
{
	std::cout << "Appel de Darray(const Darray & P) \n";
        dim=P.size();
	if(dim == 0){
            this->dim = 0;
            this->vect = NULL;
        }
	vect=new double[dim];
	for(int i=0;i<dim;i++){
		vect[i]=P(i);
	}
}

Darray::Darray(const std::string& name)
{
	std::cout << "Appel de Darray(std::string name) \n";
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

double* Darray::getAdressVect() const{
    return this->vect;
     }

int Darray::size() const
{
	return dim;
}

Darray::~Darray()
{
	delete [] vect ;
}



double Darray::operator()(int i) const{	
	assert(i>=0 && i<=(this->size()-1));
	return this->vect[i];
}

double& Darray::operator()(int i){
	assert(i>=0 && i<=(this->size()-1));
	return this->vect[i];
}

Darray& Darray::operator=(const Darray &P){
    cout<<"passage par darray";
    if(dim!=P.size()){
        this->resize(P.size(),0);
        }
        std::memcpy(vect,P.getAdressVect(),dim*sizeof(double));
        return *this;
    }
 
        
   

/*
Darray& Darray::operator=(const Darray &P){
    assert(dim==P.size());
    for(int i=0;i<dim;i++){
    vect[i]=P(i);
    }
    return *this;
}*/

Darray& Darray::operator+=(const Darray&  elem){
	assert(elem.size() == this->size());
        Darray &P=*this;
	for (int i = 0; i < this->size() ; i++){
		P(i) += elem(i);
	}
        return P;
}

Darray& Darray::operator+=(const double val){
	for (int i = 0; i < this->size() ; i++){
		this->vect[i] += val;
	}
        return *this;
}

Darray& Darray::operator-=(const Darray&  elem){
	assert(elem.size() == this->size());
	for (int i = 0; i < this->size() ; i++){
		this->vect[i] -= elem(i);
	}
        return *this;
}

Darray& Darray::operator-=(const double val){
	for (int i = 0; i < this->size() ; i++){
		this->vect[i] -= val;
	}
        return *this;
}

Darray& Darray::operator*=(const Darray& elem){
    	assert(elem.size() == this->size());
	for (int i = 0; i < this->size() ; i++){
		this->vect[i]*=elem(i);
	}
        return *this;
}

Darray& Darray::operator*=(const double val){
	for (int i = 0; i < this->size() ; i++){
		this->vect[i] *= val;
	}
        return *this;
}

Darray Darray::operator-() const{
    Darray R(*this);
	for (int i = 0; i < this->size() ; i++){
		R(i) = -this->vect[i] ;
	}
	return R;
}

 void Darray::resize(int ndim,double val){
     if (ndim>dim){
         double *temp=new double[ndim];
         std::memcpy(temp,vect,dim*sizeof(double));
         for(int i=dim;i<ndim;i++){
         	temp[i]=val;
         }
         delete [] vect;
         vect=temp;
     }
     dim=ndim;
 }
 
 
 
 
 Darray Darray::operator+(const Darray& elem){
	assert(elem.size() == this->size());
        Darray res(*this);
        res+=elem;
	return res ;
}

Darray Darray::operator+(const double val){
        Darray res(*this);
        res+=val;
	return res ;
}

Darray Darray::operator-(const Darray& elem){
	assert(elem.size() == this->size());
        Darray res(*this);
        res-=elem;
	return res ;
}

Darray Darray::operator-(const double val){
        Darray res(*this);
        res-=val;
	return res ;
}


Darray& Darray::operator/=(const double val) {
	for (int i = 0; i < this->size() ; i++){
		this->vect[i] /= val;
	}
        return *this;
}

Darray Darray::operator/(const double val){
    	Darray res(*this);
        res/=val;
        return res;
}
