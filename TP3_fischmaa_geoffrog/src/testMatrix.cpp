#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <fstream>
#include "Dmatrix.h"
#include "Darray.h"
#include "Dvector.h"
#include <cassert>
#include <sstream>

using namespace std;

int main()
{
	cout<<"Debut du test de lines() et columns() :"<<endl;
	const Dmatrix m1(3,3,2);
	int lines = m1.lines();
	int columns = m1.columns();
	assert(lines == 3);
	cout<<"OK"<<endl;
	assert(columns == 3);
	cout<<"OK"<<endl;

	cout<<"Debut du test de = :"<<endl;
	Dmatrix m2 = m1;
	lines = m2.lines();
	columns = m2.columns();
	assert(lines == 3);
	cout<<"OK"<<endl;
	assert(columns == 3);
	cout<<"OK"<<endl;

	cout<<"Debut du test de line() et column() :"<<endl;
	m2(1,1) = 0.0 ;
	Dvector vect = m2.line(1);
	for(int k = 0; k<vect.size();k++){
		std::cout<<vect(k)<<endl;
	}
	cout<<"OK"<<endl;

	cout<<"Debut du test de *(vector) :"<<endl;
	Dmatrix m3(5,3,1);
	Dvector vect1 = m3*vect;
	for(int k = 0; k<vect1.size();k++){
		std::cout<<vect1(k)<<endl;
	}
	std::cout<<"OK"<<endl;

	cout<<"Debut du test de *(matrix) :"<<endl;
	Dmatrix m4(3,4,2);
	Dmatrix m5(4,2,5);
	std::cout<<" m4"<<endl;
	for(int i =0; i<3;i++){
		m4(i,i)=0;
	}
	std::cout<<" m4"<<endl;
	for(int i =0; i<m4.lines();i++){
		for(int j = 0; j<m4.columns();j++){
			std::cout<<m4(i,j);
			std::cout<<" ";
		}
		std::cout<<endl;
	}
	std::cout<<" m5"<<endl;
	for(int i =0; i<m5.lines();i++){
		for(int j = 0; j<m5.columns();j++){
			std::cout<<m5(i,j);
			std::cout<<" ";
		}
		std::cout<<endl;
	}
	Dmatrix m6 = m4*m5;
	std::cout<<" m6"<<endl;
	for(int i =0; i<m6.lines();i++){
		for(int j = 0; j<m6.columns();j++){
			std::cout<<m6(i,j);
			std::cout<<" ";
		}
		std::cout<<endl;
	}
	std::cout<<"OK"<<endl;
	
	cout<<"Debut du test de + :"<<endl;
	Dvector v = vect + vect ;
	for(int i =0; i<v.size();i++){
		std::cout<<v(i)<<endl;
	}
	

	std::cout<<"OK"<<endl;

	cout<<"Debut du test de transpose() :"<<endl;
	std::cout<<" m4"<<endl;
	for(int i =0; i<m4.lines();i++){
		for(int j = 0; j<m4.columns();j++){
			std::cout<<m4(i,j);
			std::cout<<" ";
		}
		std::cout<<endl;
	}
	Dmatrix m7 = m4.transpose();
	std::cout<<" m4.transpose()"<<endl;
	for(int i =0; i<m7.lines();i++){
		for(int j = 0; j<m7.columns();j++){
			std::cout<<m7(i,j);
			std::cout<<" ";
		}
		std::cout<<endl;
	}
	std::cout<<"OK"<<endl;

	cout<<"Debut du test de cholesky() :"<<endl;
	Dmatrix M(3,3,0);
	M(0,0)= 20;
	M(1,0)= 4;
	M(2,0)= 5;
	M(1,1)= 10;
	M(2,1)= 1;
	M(2,2)= 7;
	std::cout<<" M "<<endl;
	for(int i =0; i<M.lines();i++){
		for(int j = 0; j<M.columns();j++){
			std::cout<<M(i,j);
			std::cout<<" ";
		}
		std::cout<<endl;
	}
	Dmatrix A = M*M.transpose();
	std::cout<<" A "<<endl;
	for(int i =0; i<A.lines();i++){
		for(int j = 0; j<A.columns();j++){
			std::cout<<A(i,j);
			std::cout<<" ";
		}
		std::cout<<endl;
	}

	Dmatrix B = A.cholesky();
	std::cout<<" B "<<endl;
	for(int i =0; i<B.lines();i++){
		for(int j = 0; j<B.columns();j++){
			std::cout<<B(i,j);
			std::cout<<" ";
		}
		std::cout<<endl;
	}

	std::cout<<"OK"<<endl;

	
}