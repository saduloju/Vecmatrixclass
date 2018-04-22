#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <iomanip>
#include "matrix_class.h"
using namespace std;

int main ()
{
   int i,j;
   matrix <double> *list;
   matrix <int> int_vec;
   matrix <double> b;
//   b.create("checking",5);
//   b.create("checking",5,5);
//   b.set_value(5);
 //  for(i=1; i<= 6; i++)cout<< i << "   " << b.get_value(i)<<  endl;
/*   for(i=1; i<= 5; i++)
     { for(j=1; j<= 4; j++)
		 {   cout<< i << " "<<j << "   " << b.get_value(i,j)<<  endl;}*/
   b.identity();
   matrix<double>mob;
   mob=b;
   for(i=1; i<= 5; i++)
     { for(j=1; j<= 5; j++)
	 {   cout<< i << " "<<j << "   " << mob.get_value(i,j)<<  endl;}}  
   
//   for(i=1; i<= 26; i++)cout<< i << "   " << mob.get_value(i)<<  endl;
   
   //matrix<double>d;
//   matrix <int> check_string;
 //  matrix <double> zy(b);
 //  matrix <double> zz=b;
 //  matrix<double> c;
 // cout << "get numof rows" << c.get_num_rows()<< endl;
  // c.set_name("nodal storage");
 //  c.create(5);
  // c.create(5);
   //d.identity();
//   list = new matrix <double> [10];
//   list[0].create( "mat_1",4,5);
 //  list[0].set_value(5.1);
 //  list[0].set_value(4,5,20.3); 
   int_vec.create( "simple list of my books at University of Tennessee", 5);
   int_vec.set_value( 20);
 //    mob=b;
 //  cout << int_vec.get_name()<< endl;
 //  cout << "list[0](4,6)" <<list[0].get_value(4,6)<< endl;
 //cout << "c.get_name()"<< c.get_name()<<endl;
 /*  for(i=1; i<= 5; i++) cout<< "i"<< i << "  "<< int_vec.get_value(i)<< endl;

 
   for(i=1; i<= 5; i++)
    {  for(j=1; j<= 6; j++)
		{cout << "i" << i<<"  j" << j << "     " <<list[0].get_value(i,j)<< endl;}
	}
   */
   
   
   return(0);
}