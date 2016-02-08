#ifndef DVECTOR_H
#define DVECTOR_H

#include <iostream>
class Dvector
{
public:
	Dvector();
	Dvector(int d, double val);
	Dvector(const Dvector & P);
	Dvector(std::string name);
	~Dvector();

	void display(std::ostream& str);
	int  getDim()const ;
	double getVect(int i) const;
  

private:
	int dim;	
	double *vect ;

};

#endif
