/* 
 * File:   Triangle.cpp
 * Author: gergeoffroy
 * 
 * Created on 26 mars 2016, 18:38
 */

#include "Triangle.h"
template <typename T>
Triangle<T>::Triangle(){
};

template <typename T>
Triangle<T>::Triangle(const Point<T> &p1,const Point<T> &p2,const Point<T> &p3) 
{
    P1=p1;
    P2=p2;
    P3=p3;
}

template <typename T>
Point<T> Triangle<T>::p1()const{
    return P1;
}

template <typename T>
Point<T> Triangle<T>::p2()const{
    return P2;
}

template <typename T>       
Point<T> Triangle<T>::p3()const{
    return P3;
}


