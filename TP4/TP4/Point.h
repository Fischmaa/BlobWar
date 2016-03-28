/* 
 * File:   Point.h
 * Author: gergeoffroy
 *
 * Created on 26 mars 2016, 18:06
 */

#ifndef POINT_H
#define	POINT_H


template <typename T>
class Point {
    public:

        
        /**
	 * @brief Constructeur simple
	 * 
	 * 
	 */
        Point<T>();
        /**
	 * @brief Constructeur avec abcisse ordonne
	 * @param abs abcisse
	 * @param ord ordonnee
	 * Construit un point a partir de labcisse et lordonnee
	 */
        Point<T>(T abs,T ord);
         /**
	 * @brief Lecture de l'abcisse
	 */  
        T x()const;
         /**
	 * @brief Lecture de l'ordonnee
	 */  
        T y()const;
    protected:
        T abs;
        T ord;
    
};
#include "Point.txx"
#endif	/* POINT_H */

