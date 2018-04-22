//
// prototypes
//
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <ctype.h>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <stdlib.h>

#include <typeinfo>

#define FEPSILON 0.000001
#define DEPSILON 0.0000000000001


using namespace std;

template <class T>
class matrix
{
public:

   matrix( void );
   matrix( int nr );
   matrix( int nr, int nc );
   matrix( string id, int nr);
   matrix( string id, int nr, int nc );
   matrix( const matrix<T> & );
    
   ~matrix (void );


   void create( int nr );
   void create( int nr, int nc );
   void create( string id, int nr );
   void create( string id, int nr, int nc );
   void free( void );

 //  int get_size( void );
   int get_num_rows(void);
   int get_num_cols(void);
   string get_name( ); ////////
   void set_name(string s );/////////// work on this!!!!!!!  is it set_name(string s)?  
   void set_value( T value); 
   void set_value( int row, T value );
   void set_value( int row, int col, T value );
   T get_value( int row);
   T get_value( int row, int col);

   T& operator() (int row ) const;
   T& operator() (int row, int col) const;
 //  matrix<T>& operator = ( matrix<T> &);
   matrix<T>& operator = (const matrix <T>& rhs);
   
   void diagonal( T value);
   void identity(void);

   matrix<T> operator * (matrix <T>& b);
   matrix<T> operator + (matrix <T>& b);
   matrix<T> operator - (matrix <T>& b);
   
   void invert( matrix<T>& a, T& det );
   void transpose( matrix <T> & b);
   void multiply(matrix <T>&, matrix <T>&);
   void add(matrix <T>& a, matrix <T>& b);
   void subtract(matrix <T>& a, matrix <T>& b);
 
   bool operator==(matrix<T> &);
   bool operator!=(matrix<T> &);
   bool equals( matrix& );
   bool nequals( matrix& );
   
   void write_to_file( fstream & file);
   void read_from_file( fstream & file);
   
   
   void print(void);
   

 
private:
   void error_mess(int mess);
//   void trace_message(int message);
   void user_trace(int type, string function_name);///////////////////////////////////////
   void copy( const matrix <T>& rhs);
   void set_debug_on();
   void set_debug_off();
   //matrix <T>& copy( const matrix <T>& rhs);
   
   int num_rows, num_cols, max_id_len;
   T *mptr;
   string id;
   //string id.reserve(80);
 
};