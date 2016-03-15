#ifndef DMATRIX_H
#define DMATRIX_H
#include "Darray.h"
#include "Dvector.h"
#include <iostream>

class Dmatrix : public Darray {

private:
	int n; /*nombre de lignes	*/
	int m; /*nombre de colonnes*/

public:
/**
  * \brief      Constructeur par defaut cree un vecteur de taille 1 initialisé à zéro
 */
  Dmatrix();

/**
  * \brief      Constructeur ou l'on precise la taille de la matrice ( nombre lignes et colonnes) et la valeur d'initialisation
  * \param      n        nombre de lignes de la matrice.
  * \param      m        nombre de colonnes de la matrice.
  * \param      val     valeur d'initialisation
 */
  explicit Dmatrix(int n, int m, double val = 0.0);

/**
  * \brief   Constructeur par recopie
 */
  Dmatrix(const Dmatrix & M);


/**
  * \brief   Destructeur
 */
  ~Dmatrix();

  double operator()(int i, int j) const;

  double& operator()(int i, int j);

  Dmatrix& operator=(const Dmatrix &M);

  int lines() const;

  int columns() const;

  Dvector line(int position) const;

  Dvector column(int position) const;

  Dvector operator*(const Dvector V) const;

  Dmatrix operator*(const Dmatrix M) const;

};

#endif