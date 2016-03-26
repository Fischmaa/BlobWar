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
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Point<double> P(3.5,4.3);
    double x=P.x();
    double y=P.y();
    std::cout<<x;
    std::cout<<y;
           
    return 0;
}

