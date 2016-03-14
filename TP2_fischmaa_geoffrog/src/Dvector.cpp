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

Dvector::Dvector(const Dvector & P):Darray(P){
    
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
