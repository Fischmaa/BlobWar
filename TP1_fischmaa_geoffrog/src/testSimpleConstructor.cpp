#include "Dvector.h"
#include <iostream>
#include <fstream>
#include <cassert>
#include <sstream>
using namespace std;

int main()
{
  cout<<"Debut du test grace au constructeur simple"<<endl;
  Dvector P(2,1.0);
  assert(P.size()==2);
  std::stringstream str1;
  P.display(str1);
  assert(str1.str() == "1\n1\n");
  cout<<"OK"<<endl;

  cout<<"Debut du test grace au constructeur simple avec argument optionnel"<<endl;
  Dvector Q(4);
  assert(Q.size()==4);
  std::stringstream str2;
  Q.display(str2);
  assert(str2.str() == "0\n0\n0\n0\n");
  cout<<"OK"<<endl;

  return 0;

  
}
