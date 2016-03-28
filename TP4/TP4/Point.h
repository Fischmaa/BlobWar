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
        Point<T>();
        Point<T>(T abs,T ord);
        T x()const;
        T y()const;
    private:
        T abs;
        T ord;
    
};
#include "Point.txx"
#endif	/* POINT_H */

