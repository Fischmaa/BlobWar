#include "Maillage.h"
#include "Point.h"

template <typename T, template<typename T1, typename = std::allocator<T1 > > class ContainerT >
Maillage<T,ContainerT>::Maillage(){
    figures=Container();
}

template <typename T, template<typename T1, typename = std::allocator<T1 > > class ContainerT >
void Maillage<T,ContainerT>::add_Triangle(const Triangle<T> P){
    figures.push_back(P);    
}

template <typename T, template<typename T1, typename = std::allocator<T1 > > class ContainerT >
Maillage<T,ContainerT>::Maillage( int m, int n, const Point<T>& origine ){
    T x0=origine.x();
    T y0=origine.y();
    for(int j=0;j<n;j++)
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
/*
template <typename T, template<typename T1, typename = std::allocator<T1 > > class ContainerT >
Triangle_iterator Maillage<T,ContainerT>::beginiter(){
    return figures.cbegin();
}
*/

/*template <typename T, template<typename T1, typename = std::allocator<T1 > > class ContainerT >
Triangle_iterator Maillage<T,ContainerT>::enditer(){
    return figures.cend();
}*/
