#include "Dvector.cpp"
#include <iostream>
#include <fstream>
#include <cassert>
#include <sstream>
using namespace std;

int main()
{
  cout<<"Test remplissage fonction uniforme"<<endl;
  Dvector P(4,3.5);
  P.fillRandomly(); 
  for(int i=0;i<P.size();i++){
    if (P.getVect(i)<0 || P.getVect(i)>1){
      assert(1==0);
    }
  }  
  cout<<"OK"<<endl;
}
