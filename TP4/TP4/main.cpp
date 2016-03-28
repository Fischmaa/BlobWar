/* 
 * File:   main.cpp
 * Author: gergeoffroy
 *
 * Created on 26 mars 2016, 18:06
 */

#include <cstdlib>
#include <iostream>
#include "Point.h"
#include "Triangle.h"
#include "Maillage.h"
#include <vector>

/*
 * 
 */
int main(int argc, char** argv) {
    Point<double> P(3.5,4.3);
    double x=P.x();
    double y=P.y();
    std::cout<<x;
    std::cout<<y;
    Triangle<double> T(P,P,P);
    std::cout<<T.p1().x();
    Triangle<double> T1;
    std::cout<<T1.p1().x();
    Maillage<double,std::vector> M(4,3,P);
    M.add_Triangle(T);
    std::cout<<M;
    Maillage<double,std::vector> N(1,1,Point<double>(0,0));
    std::cout<<N;
    return 0;
}

