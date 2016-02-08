#ifndef DVECTOR_H
#define DVECTOR_H

#include <iostream>
class Dvector
{
public:
	Dvector();
	Dvector(int d);
	Dvector(int d, double val);
	Dvector(const Dvector & P);
	~Dvector();
	void display(std::ostream& str);
	int Getdim();
	void SetDim(int dim);
	double* Getvect();
        void SetVect(double *vect); 
	void alloc(int d);
private:
	int dim;	
	double *vect ;
	/* data */
};

#endif
