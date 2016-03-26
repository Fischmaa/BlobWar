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
    Triangle(const Point<T> &p1,const Point<T> &p2,const Point<T> &p3);
    Point<T> p1();
    Point<T> p2();
    Point<T> p3();
private:
    Point<T> P1;
    Point<T> P2;
    Point<T> P3;

};

#include "Triangle.txx"
#endif	/* TRIANGLE_H */

