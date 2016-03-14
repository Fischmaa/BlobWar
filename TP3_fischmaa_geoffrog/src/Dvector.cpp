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
Dvector::Dvector():Darray(){
    
};

Dvector::Dvector(int d, double val ):Darray(d,val){
    
};

Dvector::Dvector(const Darray & P):Darray(P){
    
};

Dvector::Dvector(const std::string& name):Darray(name){
    
};


Dvector::~Dvector(){
    
};

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

double Dvector::operator*(const Dvector& elem) const{
    assert(this->size()==elem.size());
    double res=0;
    for(int i = 0 ; i< this->size();i++){
        res=this->vect[i]+elem(i);
    }   
    return res;
    
}




ostream & operator <<(ostream &OPut, const Dvector &P)
{
    P.display(OPut);
    return OPut;
}

// a tripatou

istream & operator >>(istream& Stream, Dvector &P)
{
 
    std::string str;
    for(int i=0;i<P.size();i++){ 
        getline( Stream, str );
        char *cptr = new char[str.size()+1]; // +1 to account for \0 byte
        std::strncpy(cptr,str.c_str(), str.size());
        P(i) = atof(cptr);
       
    }
    return Stream;
}
