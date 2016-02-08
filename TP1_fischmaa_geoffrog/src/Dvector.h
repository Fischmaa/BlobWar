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
	int  Getdim()const ;

	double Getvect(int i) const;
  

private:
	int dim;	
	double *vect ;
	/* data */
};

#endif
