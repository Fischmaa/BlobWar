#ifndef DVECTOR_H
#define DVECTOR_H
#include <iostream>
/**
  * \file      Dvector.cpp
  * \author    Adrien et Germain
  * \brief     Définit la base d'une classe vecteur
 */

  class Dvector
  {

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
  Dvector(int d, double val = 0.0);

/**
  * \brief   Constructeur par recopie
 */
  Dvector(const Dvector & P);

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
 void display(std::ostream& str);

/**
 * \brief   remplit un vecteur avec un générateur uniforme entre O et 1
 */
 void fillRandomly ();

 double getVect(int i) const;

/**
 * \brief     Calcul la taille d'un vecteur
 * \return    Un entier correspondant à la taille du vecteur
 */
 int size() const;

 double operator()(int i) const;

 double& operator()(int i);

 Dvector operator+(const Dvector& elem);

 void operator+=(const Dvector& elem);

 Dvector operator+(const double val);

 void operator+=(const double val);

 Dvector operator-(const Dvector& elem);

 void operator-=(const Dvector& elem);

 Dvector operator-(const double val);

 void operator-=(const double val);

 Dvector operator-();

 Dvector operator*(const double val);

 Dvector operator/(const double val);

 void operator*=(const double val);

 void operator/=(const double val);

 bool operator==(const Dvector elem);

 bool operator!=(const Dvector elem);

private:
	int dim;	
	double *vect ;

};


#endif
