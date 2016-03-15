#include "Dmatrix.h"
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
#include <string> 
#include <vector>
#include <cassert>
#include <math.h>

/**
  * \brief      Constructeur par defaut cree un vecteur de taille 1 initialisé à zéro
 */
  Dmatrix::Dmatrix():Darray(),n(0),m(0){

  }

/**
  * \brief      Constructeur ou l'on precise la taille de la matrice ( nombre lignes et colonnes) et la valeur d'initialisation
  * \param      n        nombre de lignes de la matrice.
  * \param      m        nombre de colonnes de la matrice.
  * \param      val     valeur d'initialisation
 */
  Dmatrix::Dmatrix(int n, int m, double val):Darray((m*n),val),n(n),m(m){

  }

/**
  * \brief   Constructeur par recopie
 */
  Dmatrix::Dmatrix(const Dmatrix & M):Darray(M),n(M.n),m(M.m){

  }

/**
  * \brief   Destructeur
 */
  Dmatrix::~Dmatrix(){
    //appelle automatiquement le destructeur par défaut de la classe mère.
  }

  double Dmatrix::operator()(int i, int j) const{	
    assert(i>=0 && i < n && j >= 0 && j < m);
    return this->vect[j + m*i];
}

double& Dmatrix::operator()(int i, int j){
	assert(i>=0 && i < n && j >= 0 && j < m);
	return this->vect[j + m*i];
}

Dmatrix& Dmatrix::operator=(const Dmatrix & M){
  if(dim!=M.size()){
    this->resize(M.size(),0);
}
assert(n==M.lines());
assert(m==M.columns());
std::memcpy(vect,M.getAdressVect(),dim*sizeof(double));
return *this;

}

int Dmatrix::lines() const{
  return this->n ;
}

int Dmatrix::columns() const{
  return this->m ;
}

Dvector Dmatrix::line(int position) const{
  int taille = this->lines();
  Dvector res = Dvector(taille);
  for (int j = 0; j < res.size() ; j++){

    res(j) = (*this)(position, j) ; 

}
return res ;
}

Dvector Dmatrix::column(int position) const{
  int taille = this->columns();
  Dvector res = Dvector(taille);
  for (int i = 0; i < res.size() ; i++){

    res(i) = (*this)(i,position);

}
return res ;
}

Dvector Dmatrix::operator*(const Dvector V) const{
  assert(V.size() == this->columns());
  double somme = 0.0 ;
  Dvector res(this->lines());
  for (int i = 0; i < this->lines() ; i++){
    somme = 0 ;
    for(int k = 0 ; k<V.size();k++){
        somme += (*this)(i,k)*V(k);
    }
    res(i)=somme;
}
return res;
}

Dmatrix Dmatrix::operator*(const Dmatrix M) const{
    assert(this->columns()==M.lines());
    Dmatrix res((*this).lines(), M.columns());
    double somme = 0.0;
    for (int i = 0; i < res.lines() ; i++){
        for(int j = 0 ; j< res.columns();j++){
         somme = 0 ;
         for(int k = 0 ; k< M.lines();k++){
            somme += (*this)(i,k)*M(k,j);
        }
        res(i,j)=somme;
    }
}
return res;
}

Dmatrix Dmatrix::transpose(){
    Dmatrix res = Dmatrix(this->columns(),this->lines());
    for (int i = 0; i < res.lines() ; i++){
        for(int j = 0 ; j< res.columns();j++){
            res(i,j)=(*this)(j,i);
        }
    }
    return res;
}

Dmatrix Dmatrix::cholesky(){
    assert(this->lines()==this->columns()); // matrice carré requise
    Dmatrix res = Dmatrix(this->columns(), this->columns());
    double somme = 0.0 ;
    for(int k = 0; k < res.lines() ; k ++){
        somme = 0.0 ;
        for(int s = 0 ; s<k-1;s++){
            somme += pow(res(k,s),2);
        }
        res(k,k) = sqrt( (*this)(k,k) - somme );

        for(int i = (k + 1) ; i <res.columns(); i ++){
            somme = 0.0 ;
            for(int s = 0 ; s<(k-1);s++){
                somme += res(i,s)*res(k,s);
            }
            res(i,k) = ( (*this)(i,k) - somme )/res(k,k);
        }
    }
    return res ;
}

// Dmatrix Dmatrix::cholesky(){
//     assert(this->lines()==this->columns()); // matrice carré requise
//     Dmatrix res = Dmatrix(this->columns(), this->columns());
//     for(int k = 0; k < res.lines() ; k ++){

//         for(int s = 0 ; s<=k ; s ++){

//             if(s == k){
//                 double somme = 0.0 ;
//                 for(int j = 0 ; j<s;j++){
//                     somme += res(s,j)*res(s,j);
//                 }
//                 res(s,s) = sqrt( (*this)(s,s) - somme );
//             }
//             else{
//                 double somme = 0.0 ;
//                 for(int i = 0 ; i < s; i ++){
//                     somme += res(k,i)*res(s,i);
//                 }
//                 res(k,s) = 1.0/( res(s,s)*( (*this)(k,s) - somme ) );
//             }
//         }
//     }

//     return res ;
// }