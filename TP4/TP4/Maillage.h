/* 
 * File:   Maillage.h
 * Author: gergeoffroy
 *
 * Created on 28 mars 2016, 16:47
 */

#ifndef MAILLAGE_H
#define	MAILLAGE_H
#include "Triangle.h"


template <typename T, template<typename T1, typename = std::allocator<T1 > > class ContainerT >
class Maillage{
    public:
        Maillage();
        void add_Triangle(const Triangle<T> P);
        Maillage( int m, int n, const Point<T>& origine );
        //Triangle_iterator beginiter();
        //Triangle_iterator enditer();
    private:
        typedef ContainerT<Triangle<T>  > Container;
      //  typedef typename Container::iterator rTiangle_iterator;
        Container figures;

};

#include "Maillage.txx"


#endif	/* MAILLAGE_H */

