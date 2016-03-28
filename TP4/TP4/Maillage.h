/* 
 * File:   Maillage.h
 * Author: gergeoffroy
 *
 * Created on 28 mars 2016, 16:47
 */

#ifndef MAILLAGE_H
#define	MAILLAGE_H
#include "Triangle.h"
#include <iostream>


template <typename T, template<typename sol= Triangle<T>, typename = std::allocator<Triangle<T> > > class ContainerT >
class Maillage{
    public:
        /**
	 * @brief Constructeur d'un maillage vide
	 */
        Maillage();
        /**
	 * @brief Ajoute un triangle d'ans le conteneur
         * @param Triangle à ajouter
	 */
        void add_Triangle(const Triangle<T> P);
        /**
	 * @brief Constructeur d'un maillage a partir d'une origne et de m et n longueurs
         * @param m lonbueur en abcisse
         * @param n longueur en ordonnee
         * @param origine Point d'origine
	 */
        Maillage( int m, int n, const Point<T>& origine );
        
        
        /**
	 * @brief Retourne un iterateur constant sur le debut du conteneur
	 */        
        typename ContainerT<Triangle<T> >::const_iterator beginiter();
        
        /**
	 * @brief Retourne un iterateur constant sur la fin du conteneur
	 */         
        typename ContainerT<Triangle<T> >::const_iterator enditer();
        ContainerT<Triangle<T> > figures;
        /**
	 * @brief Operateur de redirection d'une maille vers un flux
         * @param OPut flux de redirection
         * @param P Maillage
	 */        
        friend std::ostream & operator <<(std::ostream &OPut, const Maillage &P);


};

template <typename T, template<typename sol= Triangle<T>, typename = std::allocator<Triangle<T> > > class ContainerT >



std::ostream & operator <<(std::ostream &OPut, const Maillage<T,ContainerT> &P);

#include "Maillage.txx"


#endif	/* MAILLAGE_H */

