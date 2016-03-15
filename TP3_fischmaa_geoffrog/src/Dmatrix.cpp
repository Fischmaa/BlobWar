#include "Dmatrix.h"
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
#include <string> 
#include <vector>
#include <cassert>

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
};

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


