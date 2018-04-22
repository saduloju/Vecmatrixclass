#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <iomanip>
#include "matrix.h"
using namespace std;

int main ()
{
   int i;
   matrix a,b;
   
   a.create(2,10); b.create(100);
   
   for( i = 1; i <=10; i++)
     { a(1,i)= static_cast<double>(i*i);
	   a(2,i)= static_cast<double>(i);}

   for( i = 1; i <=100; i++)
     { b(i)= static_cast<double>(i*i);};

   for( i = 1; i <=10; i++)
     { cout << "2," << i << " " << a(2,i) << endl;}
   for( i = 1; i <=10; i++)
     { cout << "1," << i << " " << a(1,i) << endl;}
   for( i = 1; i <=100; i++)
     { cout << i << "  " << b(i) << endl;}
 
   a.free(); //
   b.free();
  
  cout << "aaaa\n"; ///////////////////////////////////////////////
   
   return (0);
}