/* 
 * File:   Triangle.h
 * Author: gergeoffroy
 *
 * Created on 26 mars 2016, 18:38
 */

#ifndef TRIANGLE_H
#define	TRIANGLE_H

template <typename T> 
class Triangle {
    public:
        /**
	 * @brief Constructeur simple
	 *
	 */
        Triangle<T>();
        /**
	 * @brief Constructeur a partir de points
	 * @param P1 les differebts points
	 * Construit un triangle via 3 points
	 */        
        Triangle(const Point<T> &p1,const Point<T> &p2,const Point<T> &p3);
        
        /**
	 * @brief Lecture de P1
	 */        
        Point<T> p1() const;
        /**
	 * @brief Lecture de P2
	 */          
        Point<T> p2() const;
        /**
	 * @brief Lecture de P3
	 */  
        Point<T> p3() const;
    protected:
        Point<T> P1;
        Point<T> P2;
        Point<T> P3;

};

#include "Triangle.txx"
#endif	/* TRIANGLE_H */

