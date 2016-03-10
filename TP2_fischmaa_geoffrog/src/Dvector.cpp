#include "Dvector.h"
#include <ctime>
#include <cstdlib>
#include <cstring>
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
        if(dim==0){
            this->vect=NULL;
        }
	this->vect = new double[dim];
	for( int i=0; i < dim ; i++ ){
		this->vect[i]= val;
	}
}

Dvector::Dvector(const Dvector & P)
{
	std::cout << "Appel de Dvector(const Dvector & P) \n";
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

void Dvector::display( std::ostream& str) const
{
	for (int i = 0; i < dim ; i++){
		str << this->vect[i] << "\n" ;
	}
}


void Dvector::fillRandomly() {
    static bool init = false;
    if (!init) {
        init = true;
        srand(time(NULL)); // Initialisation pour rand
    }

    // Generateur de nombre aleatoire
    for (int i = 0; i < dim; i++) {
        vect[i] = rand() / (double) RAND_MAX; // Loi Uniforme entre 0 et 1
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
    if(dim!=P.size()){
        this->resize(P.size(),0);
        }
        std::memcpy(vect,P.getAdressVect(),dim*sizeof(double));
        return *this;
    }
 
        
   

/*
Dvector& Dvector::operator=(const Dvector &P){
    assert(dim==P.size());
    for(int i=0;i<dim;i++){
    vect[i]=P(i);
    }
    return *this;
}*/

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
         std::memcpy(temp,vect,dim*sizeof(double));
         for(int i=dim;i<ndim;i++){
         	temp[i]=val;
         }
         delete [] vect;
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
        
        //a+b cest un nouvel objet on renvoie un nouvel objet
        //res va etre detruit car cest local donc on peut pas renvoyer de reference dessus
        //la seule possibilite serais de renvoyer une reference sur this mais ca na pas de sens
        // reference sur += car on veut chainer le truc
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

Dvector Dvector::operator-(){
	for (int i = 0; i < this->size() ; i++){
		this->vect[i] = -this->vect[i] ;
	}
	return *this ;
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
    P.display(OPut);
    return OPut;
}

// a tripatouiller
/*
istream & operator >>(istream& Stream, Dvector &P)
{
 
    std::string str;
    for(int i=0;i<P.size();i++){ 
        getline( Stream, str );
        P(i) = atof(str);
        
    }
    return Stream;
}*/
