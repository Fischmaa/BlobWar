#include "Dvector.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cassert>
using namespace std;
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
        *this=P;

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

double* Dvector::getAdressVect() const{
    return this->vect;
     }

int Dvector::size() const
{
	return dim;
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
	assert(i>=0 && i<=(this->size()-1));
	return this->vect[i];
}

double& Dvector::operator()(int i){
	assert(i>=0 && i<=(this->size()-1));
	return this->vect[i];
}

Dvector& Dvector::operator=(const Dvector &P){
    dim=P.size();
    vect=new double[dim];
    memcpy(vect,P.getAdressVect(),dim*sizeof(double));
    return *this;
}

Dvector& Dvector::operator+=(const Dvector&  elem){
	assert(elem.size() == this->size());
        Dvector &P=*this;
	for (int i = 0; i < this->size() ; i++){
		P(i) += elem(i);
	}
        return P;
}

Dvector& Dvector::operator+=(const double val){
	for (int i = 0; i < this->size() ; i++){
		this->vect[i] += val;
	}
        return *this;
}

Dvector& Dvector::operator-=(const Dvector&  elem){
	assert(elem.size() == this->size());
	for (int i = 0; i < this->size() ; i++){
		this->vect[i] -= elem(i);
	}
        return *this;
}

Dvector& Dvector::operator-=(const double val){
	for (int i = 0; i < this->size() ; i++){
		this->vect[i] -= val;
	}
        return *this;
}

Dvector& Dvector::operator*=(const Dvector& elem){
    	assert(elem.size() == this->size());
	for (int i = 0; i < this->size() ; i++){
		this->vect[i]*=elem(i);
	}
        return *this;
}

Dvector& Dvector::operator*=(const double val){
	for (int i = 0; i < this->size() ; i++){
		this->vect[i] *= val;
	}
        return *this;
}



void Dvector::operator/=(const double val) {
	for (int i = 0; i < this->size() ; i++){
		this->vect[i] /= val;
	}
}

bool Dvector::operator==(const Dvector& elem) const{
	if(this->size()!=elem.size()){
		return false;
	}
	else{
		for(int i = 0 ; i< this->size();i++){
			if(this->vect[i] != elem.vect[i]){
                            return false;
			}
		}
		return true;;
	}

}

bool Dvector::operator!=(const Dvector& elem) const{
	bool res = *this==(elem);
	return !res;
}


 void Dvector::resize(int ndim,double val){
     if (ndim>dim){
         double *temp=new double[ndim];
          memcpy(temp,vect,dim*sizeof(double));
          for(int i=dim;i<ndim;i++){
              temp[i]=val;
          }
          delete vect;
          vect=temp;
     }
     dim=ndim;
 }

Dvector operator/(const Dvector &P,const double val){
    	Dvector res(P);
        res/=val;
        return res;
}


Dvector operator+(const Dvector & P,const Dvector & Q){
    Dvector R(P);
    R+=Q;
    return R;
}

Dvector operator+(const double val,const Dvector &P){
    	Dvector res(P);
        res+=val;
	return res ;
}

Dvector operator+(const Dvector &P,const double val){
    return val+P;
}

Dvector operator-(const Dvector & P,const Dvector & Q){
    Dvector R(P);
    R-=Q;
    return R;
}

Dvector operator-(const double val,const Dvector &P){
    return (-1)*P+val;
}


Dvector operator-(const Dvector &P,const double val){
        Dvector res(P);
        res-=val;
        return res;
}


Dvector operator*(const Dvector & P,const Dvector & Q){
    Dvector R(P);
    R*=Q;
    return R;
}


Dvector operator*(const double val,const Dvector &P){
    	Dvector res(P);
        res*=val;
        return res;
}

Dvector operator*(const Dvector &P,const double val){
    return val*P;
}

ostream & operator <<(ostream &OPut, const Dvector &P)
{
OPut<<"Vecteur : ";
for(int i=0;i<P.size();i++){ 
    OPut<<P(i)<<" " ; 
}
OPut<<endl;
return OPut;
}

istream & operator >>(istream& Stream, Dvector &P)
{
    for(int i=0;i<P.size();i++){ 
        Stream>>P(i); 
    }
    return Stream;
}
