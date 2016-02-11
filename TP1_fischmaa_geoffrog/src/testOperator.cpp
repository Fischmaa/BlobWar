#include "Dvector.h"
#include <iostream>
#include <fstream>
#include <cassert>
#include <sstream>
using namespace std;

int main()
{
  cout<<"Debut du test de l'opérateur d'accession :"<<endl;
  Dvector P(2,1.0);
  assert(P.size()==2);
  std::stringstream str1;
  P.display(str1);
  assert(str1.str() == "1\n1\n");
  assert(P(1)==1);
  cout<<"OK"<<endl;

  return 0;
  
}
