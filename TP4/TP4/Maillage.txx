#include "Maillage.h"
#include "Point.h"
#include <iostream>
#include <fstream>


template <typename T, template<typename sol= Triangle<T>, typename = std::allocator<Triangle<T> > > class ContainerT >
Maillage<T,ContainerT>::Maillage(){
    figures=ContainerT<Triangle<T> >();
}

template <typename T, template<typename sol= Triangle<T>, typename = std::allocator<Triangle<T> > > class ContainerT >
void Maillage<T,ContainerT>::add_Triangle(const Triangle<T> P){
    figures.push_back(P);    
}

template <typename T, template<typename sol= Triangle<T>, typename = std::allocator<Triangle<T> > > class ContainerT >
Maillage<T,ContainerT>::Maillage( int m, int n, const Point<T>& origine ){
    T x0=origine.x();
    T y0=origine.y();
    for(int j=0;j<n;j++){
        for(int i=0;i<n;i++){
            Point<T> P1(x0+i,y0+j);
            Point<T> P2(x0+i+1,y0+j);           
            Point<T> P3(x0+i,y0+j+1);
            Point<T> P4(x0+i+1,y0+j+1);
            Triangle<T> T1(P1,P2,P3);
            Triangle<T> T2(P2,P3,P4);
            (*this).add_Triangle(T1);
            (*this).add_Triangle(T2);
        }
    }
}

template <typename T, template<typename sol= Triangle<T>, typename = std::allocator<Triangle<T> > > class ContainerT >
typename ContainerT<Triangle<T> >::const_iterator Maillage<T,ContainerT>::beginiter(){
    typename ContainerT<Triangle<T> >::const_iterator it=(*this).figures.begin();
    return it;
}

template <typename T, template<typename sol= Triangle<T>, typename = std::allocator<Triangle<T> > > class ContainerT >
typename ContainerT<Triangle<T> >::const_iterator Maillage<T,ContainerT>::enditer(){
    typename ContainerT<Triangle<T> >::const_iterator it=(*this).figures.end();
    return it;
}



template <typename T, template<typename sol= Triangle<T>, typename = std::allocator<Triangle<T> > > class ContainerT >
std::ostream & operator <<(std::ostream &OPut, Maillage<T,ContainerT> &P)
{
    typename ContainerT<Triangle<T> >::const_iterator it;
    for(it=P.figures.begin();it!=P.figures.end();it++){
        OPut<<it->p1().x()<<" "<<it->p1().y()<<"\n";
        OPut<<it->p2().x()<<" "<<it->p2().y()<<"\n";
        OPut<<it->p3().x()<<" "<<it->p3().y()<<"\n";
        OPut<<it->p1().x()<<" "<<it->p1().y()<<"\n \n";
    }
    return OPut;
}