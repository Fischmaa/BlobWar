#include "Dvector.h"
#include <iostream>
#include <sstream>
#include <cassert>
using namespace std;
int main()
{	
	cout<<"Début du test du constructeur à partir du fichier tp1_test1.txt."<<endl;
	std::string name("tp1_test1.txt");
	//Dvector P = Dvector("tp1_test1.txt"); // marche aussi
	Dvector P = Dvector(name);
	assert(P.size()==10);
	std::stringstream str;
	P.display(str);
	//Il y a des arrondis en sortie, ce qui justifie les modifications par rapport au fichier d'entrée.
	assert(str.str() == "0.162182\n0.794285\n0.311215\n0.528533\n0.165649\n0.601982\n0.262971\n0.654079\n0.689214\n0.748152\n");
	std::cout <<"OK\n";

	return 0 ;
}
