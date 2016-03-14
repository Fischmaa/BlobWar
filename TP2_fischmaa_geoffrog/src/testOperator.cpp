#include "Dvector.h"
#include <iostream>
#include <fstream>
#include <cassert>
#include <sstream>
using namespace std;

int main()
{
  Dvector P(2,1.0);
  P=P;
  P=-P;
  return 0;
 }
