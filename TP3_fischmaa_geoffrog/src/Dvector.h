#ifndef DVECTOR_H
#define DVECTOR_H
#include <iostream>
#include "Darray.h"
using namespace std;
/**
  * \file      Dvector.cpp
  * \author    Adrien et Germain
  * \brief     Définit la base d'une classe vecteur
 */

  class Dvector: public Darray {

  public:

/**
  * \brief      Constructeur par defaut cree un vecteur de taille 1 initialisé à zéro
 */
  Dvector();
/**
  * \brief      Constructeur ou l'on precise la taille du vecteur et la valeur d'initialisation
  * \param      d        taille du vecteur.
  * \param      val     valeur d'initialisation
 */
  explicit Dvector(int d, double val = 0.0);

/**
  * \brief   Constructeur par recopie
 */
  Dvector(const Darray & P);

/**
  * \brief   Constructeur à partir d'un fichier
 *
 */
  Dvector(const std::string& name);


/**
  * \brief   Destructeur
 */
  ~Dvector();


/**
 * \brief    Affiche sur le flux en paramètre le contenu du vecteur
 * \param    str   flux passé en paramètre       
 */
 void display(std::ostream& str) const;

/**
 * \brief   remplit un vecteur avec un générateur uniforme entre O et 1
 */
 void fillRandomly ();
 


 bool operator==(const Dvector &elem) const;

 bool operator!=(const Dvector &elem) const;
 
 double operator*(const Dvector& elem) const;
 /**
   * \brief     Redimensionne un vecteur
   *\param      ndim nouvelle taille du vecteur
   * \param      val     valeur d'initialisation des nouveaux indices
   */



friend ostream & operator <<(ostream &OPut, const Dvector &P);

friend istream & operator >>(istream& Stream, Dvector &P);


};



ostream & operator <<(ostream &OPut, const Dvector &P);

istream & operator >>(istream& Stream,  Dvector &P);


#endif
