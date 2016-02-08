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
	Dvector();


/**
 * \brief       Constructeur avec en argument la taille du vecteur
 * \param    d         taille du vecteur
 */
	Dvector(int d);

/**
 * \brief      Constructeur ou l'on precise la taille du vecteur et la valeur d'initialisation
 * \param      d        taille du vecteur.
 * \param      val     valeur d'initialisation
 * \return    Un \e float représentant la distance calculée.
 */
	Dvector(int d, double val);

/**
 * \brief      Constructeur par recopie
 */
	Dvector(const Dvector & P);

/**
 * \brief Destructeur
 */
	~Dvector();



/**
 * \brief     Affiche sur le flux en paramètre le contenu du vecteur
 * \param    str   flux passé en paramètre       
 */
	void display(std::ostream& str);


/**
 * \brief   remplit un vecteur avec un générateur uniforme entre O et 1
 */
        void fillRandomly ();


	double getVect(int i) const;



/**
 * \brief       Calcule la taille d'un vecteur
 * \return    Un entier correspondant à la taille du vecteur
 */
	int size() const;
	

private:
	int dim;	
	double *vect ;

};


#endif
