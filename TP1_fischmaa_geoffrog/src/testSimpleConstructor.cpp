#include "Dvector.h"
#include <iostream>
#include <fstream>
#include <cassert>
#include <sstream>
using namespace std;

int main()
{
  cout<<"Debut du test grace au constructeur simple"<<endl;
  Dvector P(2,0.);
  assert(P.size()==2);
  std::stringstream str1;
  P.display(str1);
  assert(str1.str() == "0\n0\n");
  cout<<"OK"<<endl;
  return 0;

  
}
