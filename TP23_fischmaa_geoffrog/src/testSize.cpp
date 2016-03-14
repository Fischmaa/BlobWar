#include "Dvector.h"
#include <iostream>
#include <fstream>
#include <cassert>
#include <sstream>
using namespace std;

int main()
{
  cout<<"Debut du test de size"<<endl;
  Dvector P(2,0.);
  assert(P.size()==2);
  cout<<"OK"<<endl;
  return 0;

  
}
