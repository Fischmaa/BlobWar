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
        void fillRandomly ();

	double getVect(int i) const;
	int size() const;
	
  

private:
	int dim;	
	double *vect ;
	/* data */
};


#endif
