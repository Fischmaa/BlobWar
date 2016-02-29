#include "Dvector.h"
#include <iostream>
#include <fstream>
#include <cassert>
#include <sstream>
using namespace std;

int main()
{
  cout<<"Debut du test de l'opérateur d'accession en lecture:"<<endl;
  Dvector P(2,1.0);
  assert(P.size()==2);
  std::stringstream str;
  P.display(str);
  assert(str.str() == "1\n1\n");
  assert(P(1)==1);
  cout<<"OK"<<endl;
  

  cout<<"Debut du test de l'opérateur d'accession en écriture:"<<endl;
  Dvector Q(2,1.0);
  assert(Q.size()==2);
  str.str(std::string()); // réinitialisation de str
  Q.display(str);
  assert(str.str() == "1\n1\n");
  Q(1)=3;
  assert(Q(1)==3);
  str.str(std::string());
  Q.display(str);
  assert(str.str() == "1\n3\n");
  cout<<"OK"<<endl;
  
  cout<<"Debut du test de ==:"<<endl;
  bool b=P==Q;
  assert(b==false);
  Dvector N(P);
  b=P==N;
  assert(b==true);
  cout<<"OK"<<endl;
  
  cout<<"Debut du test de !=:"<<endl;
  b=P!=Q;
  assert(b==true);
  b=P!=N;
  assert(b==false);
  cout<<"OK"<<endl;
  
  cout<<"Debut du test de /= avec un double':"<<endl;
  N/=2;
  str.str(std::string());
  N.display(str);
  assert(str.str() == "0.5\n0.5\n");
  cout<<"OK"<<endl;
  
  // cout<<"Debut du test de / avec un double':"<<endl;
  // N=N/2;
  // str.str(std::string());
  // N.display(str);
  // assert(str.str() == "0.25\n0.25\n");
  // cout<<"OK"<<endl;


  cout<<"Debut du test de l'addition de deux vecteurs':"<<endl;
  Dvector R = P + Q ;
  str.str(std::string());
  R.display(str);
  assert(str.str() == "2\n4\n");
  cout<<"OK"<<endl;
  
  cout<<"Debut du test de l'addition de deux vecteurs sur un des deux':"<<endl;
  R = R + Q ;
  str.str(std::string());
  R.display(str);
  assert(str.str() == "3\n7\n");
  cout<<"OK"<<endl;


  // cout<<"Debut du test de l'opérateur += avec un vecteur:"<<endl;
  // R += P ;
  // str.str(std::string());
  // R.display(str);
  // assert(str.str() == "4\n8\n");
  // cout<<"OK"<<endl;


  // cout<<"Debut du test de l'opérateur -= avec un vecteur:"<<endl;
  // R -= P ;
  // str.str(std::string());
  // R.display(str);
  // assert(str.str() == "3\n7\n");
  // cout<<"OK"<<endl;

  // cout<<"Debut du test de l'opérateur - avec un vecteur:"<<endl;
  // R = R-P ;
  // str.str(std::string());
  // R.display(str);
  // assert(str.str() == "2\n6\n");
  // cout<<"OK"<<endl;


  // cout<<"Debut du test de l'opérateur *= avec un vecteur:"<<endl;
  // R *= P;
  // str.str(std::string());
  // R.display(str);
  // assert(str.str() == "2\n6\n");
  // cout<<"OK"<<endl;



  // cout<<"Debut du test de l'opérateur * avec un vecteur:"<<endl;
  // R = R*P ;
  // str.str(std::string());
  // R.display(str);
  // assert(str.str() == "2\n6\n");
  // cout<<"OK"<<endl;


  // cout<<"Debut du test de l'opérateur + avec un reel en externe:"<<endl;
  // R = R+1;
  // str.str(std::string());
  // R.display(str);
  // assert(str.str() == "3\n7\n");
  // cout<<"OK"<<endl;

  // cout<<"Debut du test de l'opérateur * avec un reel en externe:"<<endl;
  // R = R*2;
  // str.str(std::string());
  // R.display(str);
  // assert(str.str() == "6\n14\n");
  // cout<<"OK"<<endl;

  // cout<<"Debut du test de l'opérateur - avec un reel en externe:"<<endl;
  // R = R-1 ;
  // str.str(std::string());
  // R.display(str);
  // assert(str.str() == "5\n13\n");
  // cout<<"OK"<<endl;

  // cout<<"Debut du test de l'opérateur - :"<<endl;
  // R = -R ;
  // str.str(std::string());
  // R.display(str);
  // assert(str.str() == "-5\n-13\n");
  // cout<<"OK"<<endl;
  
  //cout<<"Debut du test de redirection vers sortie standard:"<<endl;

  // cout<<"R doit valoir R puis 13"<<R;
  // cin.width(1);
  // cin>>R;
  // cout<<R;

  // cout<<"Debut du test de resize:"<<endl;
  // R.resize(4,7);
  // str.str(std::string());
  // R.display(str);
  // assert(str.str() == "-5\n-13\n7\n7\n");
  // cout<<"OK"<<endl;

  return 0;
  
}
