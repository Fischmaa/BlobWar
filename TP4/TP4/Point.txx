#include "Point.h"
#include <iostream>


template <typename T>
Point<T>::Point(){
    abs=0;
    ord=0;
}



template <typename T>
Point<T>::Point(T x, T y){
    abs=x;
    ord=y;
}

template <typename T>
T Point<T>::x()const{
    return abs;
}

template <typename T>
T Point<T>::y()const{
    return ord;
}