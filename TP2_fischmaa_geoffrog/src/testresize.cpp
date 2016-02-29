#include "Dvector.h"
#include <iostream>
#include <fstream>
#include <cassert>
#include <sstream>
using namespace std;

int main()
{
   Dvector R(2,1);
   std::stringstream str;
   cout<<"Debut du test de resize:"<<endl;
   R.resize(4,7);
   str.str(std::string());
   R.display(str);
   assert(str.str() == "1\n1\n7\n7\n");
   cout<<"OK"<<endl;

  return 0;
    
    
}
