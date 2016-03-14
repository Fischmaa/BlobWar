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
   cout<<"Debut du test de redirection <<:"<<endl;
   str<<R;
   cout<<str.str();
   assert(str.str()=="Vecteur : 1 1 \n");   

  return 0;
    
    
}
