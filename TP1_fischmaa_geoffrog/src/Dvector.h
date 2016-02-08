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
	void fillRandomly ();
	double getVect(int i) const;
	int size() const;
	

private:
	int dim;	
	double *vect ;

};


#endif
