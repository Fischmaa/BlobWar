#ifndef DVECTOR_H
#define DVECTOR_H

#include <iostream>
class Dvector
{
public:
	Dvector();
	Dvector(int d);
	Dvector(int d, double val);
	~Dvector();
	void display(std::ostream& str);
private:
	int dim;	
	double *vect ;
	/* data */
};

#endif