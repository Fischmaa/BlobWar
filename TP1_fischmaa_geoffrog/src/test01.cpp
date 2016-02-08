#include "Dvector.cpp"
#include <iostream>
#include <fstream>
#include <cassert>
#include <sstream>
using namespace std;

int main()
{

  cout<<"Début des differents test avec l'aide de la fonction assert"<<endl;
  cout<<"Construction d'un vecteur de taille 4 avec initialisation à 3.5 avec le constructeur approprié"<<endl;
  Dvector P(4,3.5);
  assert(P.size()==4);
    cout<<"Le vecteur est bien de taille 4"<<endl;
  std::stringstream str;
  P.display(str);
  assert(str.str() == "3.5\n3.5\n3.5\n3.5\n");
  cout<<"contenu ok"<<endl;
  cout<<"construction d'un vecteur par copie"<<endl;
  Dvector D(P);
  assert(D.size()==4);
    cout<<"Le vecteur est bien de taille 4"<<endl;
    std::stringstream str1;
  D.display(str1);
  assert(str1.str() == "3.5\n3.5\n3.5\n3.5\n");
  cout<<"contenu ok"<<endl;
  cout<<"test remplissage vecteur selon loi uniforme entre 0 et 1:"<<endl;
  D.fillRandomly(); 
 for(int i=0;i<D.size();i++){
    if (D.getVect(i)<0 || D.getVect(i)>1){
    assert(1==0);
       }
  }  
  cout<<"OK"<<endl;



	return 0 ;
}
