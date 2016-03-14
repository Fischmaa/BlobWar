/* 
 * File:   Darray.h
 * Author: geoffrog
 *
 * Created on 11 mars 2016, 16:16
 */

#ifndef DARRAY_H
#define	DARRAY_H
#include <iostream>

class Darray {
public:
/**
  * \brief      Constructeur par defaut cree un vecteur de taille 1 initialisé à zéro
 */
  Darray();
/**
  * \brief      Constructeur ou l'on precise la taille du vecteur et la valeur d'initialisation
  * \param      d        taille du vecteur.
  * \param      val     valeur d'initialisation
 */
  Darray(int d, double val = 0.0);

/**
  * \brief   Constructeur par recopie
 */
  Darray(const Darray & P);

/**
  * \brief   Constructeur à partir d'un fichier
 *
 */
 Darray(const std::string& name);


/**
  * \brief   Destructeur
 */
  ~Darray();
  
  int size() const;
  
  double* getAdressVect() const;


 double operator()(int i) const;

 double& operator()(int i);
 
 Darray& operator=(const Darray &P);

 Darray& operator+=(const Darray& elem);
 
 Darray& operator+=(const double val);

 Darray& operator-=(const Darray& elem);
 
 Darray& operator-=(const double val);

 Darray& operator*=(const Darray& elem);
  
 Darray& operator*=(const double val);
 
 Darray operator-() const;

 void resize(int ndim,double val);
  
 Darray operator+(const Darray& elem);
 
 Darray operator+(const double val);
 
 Darray operator-(const Darray& elem);
 
 Darray operator-(const double val);
 
 Darray& operator/=(const double val) ;
 
 Darray operator/(const double val);
 
 
protected:
	int dim;	
	double *vect ;

};

#endif	/* DARRAY_H */

