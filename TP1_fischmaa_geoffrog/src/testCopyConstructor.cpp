#include "Dvector.cpp"
#include <iostream>
#include <fstream>
#include <cassert>
#include <sstream>
using namespace std;

int main()
{
 
 cout<<"Test du constructeur par recopie"<<endl;
 Dvector P(4,3.5);
 Dvector D(P);
 assert(D.size()==4);
 std::stringstream str1;
 D.display(str1);
 assert(str1.str() == "3.5\n3.5\n3.5\n3.5\n");
 cout<<"OK"<<endl;
 return 0;
}
