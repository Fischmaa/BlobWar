#ifndef DVECTOR_H
#define DVECTOR_H
class Dvector
{
public:
	double dim;
	double *vect;
	Dvector();
	Dvector(double d);
	~Dvector();
	void display ( std::ostream& str);

	/* data */
};

#endif