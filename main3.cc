#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <iomanip>
#include "matrix_class_template.h"
using namespace std;

int main ()
{
   int i;
   string mat_id;
   mat_id.reserve(80);
   matrix <double> a,b,c;
   
   a.create("coords x and y",2,10); b.create("temperatures",100);
   c.create("unit", 10,10);
   
   for( i = 1; i <=10; i++)
     { a(1,i)= static_cast<double>(i*i);
	   a(2,i)= static_cast<double>(i);}

   for( i = 1; i <=100; i++)
     { b(i)= static_cast<double>(i*i);};

   a.get_name(mat_id);
   cout<< "matrix aid: " << mat_id << endl;
   cout<< "matrix aid2: " << a.get_name()<< endl;
   
   cout<< "matrix bid: " << mat_id << endl;
   cout<< "matrix bid2: " << b.get_name()<< endl;   
   
   c.identity();
  /* for( i = 1; i <=10; i++)
     { cout << "2," << i << " " << a(2,i) << endl;}
   for( i = 1; i <=10; i++)
     { cout << "1," << i << " " << a(1,i) << endl;}
   for( i = 1; i <=100; i++)
     { cout << i << "  " << b(i) << endl;}*/
 

   a.free(); //
   b.free();
  
  cout << "aaaa\n"; ///////////////////////////////////////////////
   
   return (0);
}