
#include "matrix_class.h"

bool debug = false;
//
// constructors

//*****************************************************************************
//*             class  : matrix ()                                            *
//*             Author : Sunday Aduloju                                       *
//*             submitted to Prof. Dodds                                      *
//*             Last Modified: 4/15/2018                                      *
//*                                                                           *
//*****************************************************************************
//
//constructor function for the matrix 
//
template < class T >
matrix<T> :: matrix(void)
{
   set_debug_on();
   if(debug) {user_trace(1, " cons_tor (void)");}
   
   num_rows = 0; num_cols = 0; mptr = NULL; 
   max_id_len = 80; id = " ";
     
   if(debug) {user_trace(2, "cons_tor (void)");}
   set_debug_off();
   return;   
}


template < class T >
matrix<T> :: matrix(int nr)
{
   set_debug_off();
   if(debug) {user_trace(1, " cons_tor (nr)");}
   
   create ("", nr);
   
   if(debug) {user_trace(2, " cons_tor (nr)");}
   set_debug_off();
   return;   
}

template < class T >
matrix<T> :: matrix(int nr, int nc)
{
   set_debug_off();
   if(debug) {user_trace(1, " cons_tor (nr,nc)");}
   
   create ("", nr, nc);
   // some1 said we shoul add set_value. How does it come in?
   
   if(debug) {user_trace(2, " cons_tor (nr,nc)");}
   set_debug_off();
   return;   
}

template < class T >
matrix<T> :: matrix(string id, int nr)
{
   set_debug_off();
   if(debug) {user_trace(1, " cons_tor (id,nr)");}
   
   create (id, nr);
   
   if(debug) {user_trace(2, " cons_tor (id,nr)");}
   set_debug_off();
   return;   
}


template < class T >
matrix<T> :: matrix( string id, int nr, int nc )
{
   set_debug_off();
   if(debug) {user_trace(1, " cons_tor (id,nr,nc)");}
   
   mptr=NULL;
   create (id, nr, nc);
   // some1 said we shoul add set_value. How does it come in?
   
   if(debug) {user_trace(2, " cons_tor (id,nr,nc)");}
   set_debug_off();
   return;   
}


template <class T>
matrix<T> :: matrix( const matrix<T> & a)
{
   set_debug_off();
   if(debug) {user_trace(1, "cons_tor (matrix<T> &a)");}
   if(a.mptr==NULL){error_mess(10);}
   mptr=NULL; /////this is there cos of the create function ask Prof Dodds
   create ( a.id, a.num_rows, a.num_cols);
   for(int j=1; j<=num_rows*num_cols; j++)
      { (*this)(j)= a(j);}
  
   if(debug) {user_trace(2, "cons_tor (matrix<T> &a)");}
   set_debug_off();
   return;  
}

//
// destructor
//
template < class T >
matrix<T> :: ~matrix(void)
{
   set_debug_off();
   if(debug) {user_trace(1, "destructor");}
   
   free();
   
   if(debug) {user_trace(2, "destructor");}
   set_debug_off();
   return;   
}

//
// create and Free Matrices
//

//*****************************************************************************
//*             class  : create                                               *
//*             Author : Sunday Aduloju                                       *
//*             submitted to Prof. Dodds                                      *
//*             Last Modified: 4/15/2018                                      *
//*                                                                           *
//*****************************************************************************
//
// This function creates a vector
//
template < class T >
void matrix <T> :: create( int nr )
{
   set_debug_off();
   if(debug) {user_trace(1, "create(nr)");}
   
   if(! nr > 0) {error_mess(21); return; }
   if( mptr != NULL) { error_mess(22); return;}
   mptr = new T[nr];
   num_rows = nr; num_cols = 1; ////////////////////Ask Prof Dodds
   
   if(debug) {user_trace(2, "create(nr)");}
   set_debug_off();
   return;	
}



template < class T >
void matrix <T> :: create (string s, int nr)
{
   set_debug_off();
   if(debug) {user_trace(1, "create (s,nr)");}
   
   if(! nr > 0) {error_mess(21); return; }
   if( mptr != NULL) { error_mess(22); return;}
//   if (s.size()> max_id_len){ max_id_len=s.size();};
   id.reserve(max_id_len);//////////should it be included?	
//   cout <<  s.size()<< "thaT is the size for mat_1\n";/////////remove
   id = s;
   mptr = new T[nr];
   num_rows = nr; num_cols = 1;
   
   if(debug) {user_trace(2, "create (s,nr)");}
   set_debug_off();   
   return;	
}

//*****************************************************************************
//*             class  : create                                               *
//*             Author : Sunday Aduloju                                       *
//*             submitted to Prof. Dodds                                      *
//*             Last Modified: 4/15/2018                                      *
//*                                                                           *
//*****************************************************************************
// This is an overloaded create function 
// it creates a 2-D matrix
//
template < class T >
void matrix <T> :: create( int nr, int nc )
{
   set_debug_off();
   if(debug) {user_trace(1, "create(nr,nc)");}
   
   if(! nr > 0) {error_mess(1); return; }
   if(! nc > 0) {error_mess(5); return; }
   if( mptr != NULL) { error_mess(2); return;}
   num_rows = nr; num_cols = nc;
   mptr = new T[nr*nc];
   
   if(debug) {user_trace(2, "create(nr,nc)");}
   set_debug_off();
   return;
}


template < class T >
void matrix <T> :: create( string s, int nr, int nc )
{
   set_debug_off();
   if(debug) {user_trace(1, "create(s,nr,nc)");}
   
   if(! nr > 0) {error_mess(1); return; }
   if(! nc > 0) {error_mess(5); return; }
 //  if( mptr != NULL) { error_mess(2); return;} //////////////////////main.cc caused
///THIS IS 2 lines ARE causing trouble
//   if (s.size()> max_id_len){ max_id_len=s.size();};
  // id.reserve(max_id_len);//////////should it be included?	
   id = s;
   num_rows = nr; num_cols = nc;
   mptr = new T[nr*nc];
   
   if(debug) {user_trace(2, "create(s,nr,nc)");}
   set_debug_off();
   return;
}

//*****************************************************************************
//*             class  : free                                                 *
//*             Author : Sunday Aduloju                                       *
//*             submitted to Prof. Dodds                                      *
//*             Last Modified: 4/15/2018                                      *
//*                                                                           *
//*****************************************************************************
//
//This function frees vector or 2-D matrix
//
template < class T >
void matrix<T> :: free( void )
{
   set_debug_off();
   if(debug) {user_trace(1, "free");}
   
   num_rows = 0; num_cols = 0; id = " ";
   if( mptr != NULL ){ delete[] mptr;}
   mptr = NULL;
   
   if(debug) {user_trace(2, "free");}
   set_debug_off();
   return;  
}

//
// Functions that provide protected access
//

//*****************************************************************************
//*             class : get_num_rows                                          *
//*             Author : Sunday Aduloju                                       *
//*             submitted to Prof. Dodds                                      *
//*             Last Modified: 4/28/2018                                      *
//*                                                                           *
//*****************************************************************************
//
// This function provides the number of rows 
// of a vector or a 2-D matrix. 
// 
template < class T >
int matrix <T> :: get_num_rows( void)
{
   set_debug_off();
   if(debug) {user_trace(1, "get_num_rows");}
   
   if( mptr == NULL) { error_mess(6); return(0);}
   
   if(debug) {user_trace(2, "get_num_rows");}
   set_debug_off();   
   return ( num_rows);      
}

//*****************************************************************************
//*             class : get_num_rows                                          *
//*             Author : Sunday Aduloju                                       *
//*             submitted to Prof. Dodds                                      *
//*             Last Modified: 4/28/2018                                      *
//*                                                                           *
//*****************************************************************************
//
// This function provides the number of cols 
// a 2-D matrix has. 
// It can also be used to check if the instance is a vector (num_cols=1)
//

template < class T >
int matrix <T> :: get_num_cols( void)
{
   set_debug_off();
   if(debug) {user_trace(1, "get_num_cols");}

   if( mptr == NULL) { error_mess(6); return(0);}
 
   if(debug) {user_trace(2, "get_num_cols");}     
   set_debug_off();
   return ( num_cols); 
 
}

template < class T >
string matrix <T> :: get_name()
{
   set_debug_off();
   if(debug) {user_trace(1, "get_name");}

   if( mptr == NULL) { error_mess(6); return("ERROR!");}
   if( id == " ") { error_mess(7); return ("ERROR!");}

   if(debug) {user_trace(1, "get_name");}
   set_debug_off();   
   return(id);	
}

template < class T >
void matrix <T> :: set_name(string s)
{
   set_debug_off();
   if(debug) {user_trace(1, "set_name");}

 //  if( mptr == NULL) { error_mess(6); return;}// must u always define the size before naming?
//   if (s.size()> max_id_len){ max_id_len=s.size();};
   id.reserve(max_id_len);//////////should it be included?	
   id = s;	
	
   if(debug) {user_trace(2, "set_name");}
   set_debug_off();
   return;	
}

template < class T >
void matrix <T> :: set_value( T value)
{
   set_debug_off();
   if(debug) {user_trace(1, "set_value(value)");}	
   
   if( mptr == NULL) { error_mess(6); return;}
   for(int i=1; i<=num_rows; i++)
      {
		 for( int j=1; j<= num_cols; j++)
		    { (*this)(i,j) = value;}			 
	  }
	  
   if(debug) {user_trace(2, "set_value(value)");}
   set_debug_off();   
   return;	
}

template < class T >
void matrix <T> :: set_value( int row, T value )
{  
   set_debug_off();
   if(debug) {user_trace(1, "set_value(row,value )");}
   
   if ( num_cols > 1){ error_mess(12); return;}
   if( mptr == NULL) { error_mess(26); return;}
   if(row > num_rows) { error_mess(3);return;}
   mptr[row -1] = value;
   
   if(debug) {user_trace(2, "set_value(row,value )");}
   set_debug_off();
   return;
}

////////////////////////////////////////////////////////////////////change to *this
template < class T >
void matrix <T> :: set_value( int row, int col, T value )
{
  set_debug_off();
  if(debug) {user_trace(1, "set_value(row,col,value )");}
  
  if( num_cols == 1){ error_mess(14); return;}
  if( mptr == NULL) { error_mess(16); return;} 	
  if(row > num_rows) { error_mess(3);return;}
  if(col > num_cols) { error_mess(4);return;}
  mptr[num_cols*(row-1)+ col-1]= value;

  if(debug) {user_trace(2, "set_value(row,col,value )");}
  set_debug_off();  
  return;
}

template < class T >
T matrix <T> :: get_value( int row)
{
   set_debug_off();
   if(debug) {user_trace(1, "get_value(row)");}
    
   if( num_cols > 1){ error_mess(13); return(0);}
   if( mptr == NULL) { error_mess(26); return(0);}
   if(row > num_rows) { error_mess(3);return(0);}
   
   if(debug) {user_trace(2, "get_value(row)");}
   set_debug_off();
   return( mptr[row-1]);	
}

template < class T >
T matrix <T> :: get_value( int row, int col)
{
	set_debug_off();
	if(debug) {user_trace(1, "get_value(row,col)");}
	
	if( num_cols == 1){ error_mess(15); return(0);}
	if( mptr == NULL) { error_mess(6); return(0);}
	if(row > num_rows) { error_mess(3);return(0);}
	if( num_cols == 1){ error_mess(11); return(0);}
	if(col > num_cols) { error_mess(4);return(0);}
	
	if(debug) {user_trace(2, "get_value(row,col)");}
	set_debug_off();
    return( (*this)(row,col) );	
}




//*****************************************************************************
//*             class : operator ()(i)                                           *
//*             Author : Sunday Aduloju                                       *
//*             submitted to Prof. Dodds                                      *
//*             Last Modified: 4/28/2018                                      *
//*                                                                           *
//*****************************************************************************
//
// This function overloads the () operator
// for indexing into a vector  
// 
template < class T >
T& matrix <T> :: operator () (int row) const
{ 
//   set_debug_off();
  //   if(debug) {user_trace(1, "operator(row)");}
   
 //   if( mptr == NULL) { error_mess(26); return(0);}//
 //  if(row > num_rows) { error_mess(3); return (0);}//
   
 //  if(debug) {user_trace(2, "operator(row)");}
//   set_debug_off();
   return (mptr[row-1]);	
}

//*****************************************************************************
//*             class : operator ()(i,j)                                           *
//*             Author : Sunday Aduloju                                       *
//*             submitted to Prof. Dodds                                      *
//*             Last Modified: 4/28/2018                                      *
//*                                                                           *
//*****************************************************************************
//
// This function overloads the () operator
// for indexing into a 2-D matrix  
//
template < class T >
T& matrix <T> :: operator() (int row, int col) const
{
//   set_debug_off();
//   if(debug) {user_trace(1, "operator(row,col)");}
   
//   if( mptr == NULL) { error_mess(6); return (0);}
//   if(row > num_rows) { error_mess(3);return(0);}
//   if(col > num_cols) { error_mess(4);return(0);}
   
 //  if(debug) {user_trace(2, "operator(row,col)");}
 //  set_debug_off();
   return( mptr[num_cols*(row-1)+ col-1] );	
}

/*
template < class T >
matrix<T>& matrix<T> :: operator = ( matrix<T> & rhs)
{
   if(debug) {user_trace(1,"operator=( const matrix<T> & rhs)");} 
   
   if( rhs.mptr == NULL) 
   {error_mess(17);(*this)(1)=1;(*this)(2)=1; return(*this);}///////////work on this
   if( mptr == rhs.mptr){ return (*this);}
   free();
 //  mptr = NULL;
   create( " ", rhs.num_rows, rhs.num_cols);
   for(int j=1; j<= num_rows*num_cols; j++)
	  {(*this)(j) = rhs(j);}

   if(debug) {user_trace(2,"operator=( const matrix<T> & rhs)");}
   return (*this);
}	

*/


template < class T >
matrix<T> matrix<T> :: operator * (matrix <T>& b)
{
   set_debug_off();
   if(debug) {user_trace(1, "operator * (matrix <T>& b)");}
   
   int nrow, ncol; 
   if( mptr == NULL) { error_mess(16); (*this)(1)=1;(*this)(2)=1; return(*this);}//////////////////
   if(num_cols != b.num_rows ) {error_mess(19); (*this)(1)=1;(*this)(2)=1; return(*this);}//////////////////
   matrix<T> temp;
   temp.multiply (*this,b);
   
   if(debug) {user_trace(2, "operator * (matrix <T>& b)");}
   set_debug_off();
   return temp;   
}

template < class T >
matrix<T> matrix<T> :: operator + (matrix <T>& b)
{
   set_debug_off();
   if(debug) {user_trace(1, "operator + (matrix <T>& b)");}
   
   int nrow, ncol;
   if( mptr == NULL) { error_mess(16); (*this)(1)=1;(*this)(2)=1; return(*this);}//////////////////
   if( b.mptr == NULL) { error_mess(6); (*this)(1)=1;(*this)(2)=1; return(*this);}  
   if(num_rows != b.num_rows){ error_mess(29); (*this)(1)=1;(*this)(2)=1; return(*this);}//Prof Dodds said we could use exit(0)
   if(num_cols != b.num_cols){ error_mess(30); (*this)(1)=1;(*this)(2)=1; return(*this);}//Prof Dodds said we could use exit(0)
   matrix<T> temp;
   temp.add (*this,b);
   
   if(debug) {user_trace(2, "operator + (matrix <T>& b)");}
   set_debug_off();
   return temp;   
}

template < class T >
matrix<T> matrix<T> :: operator - (matrix <T>& b)
{
   set_debug_off();
   if(debug) {user_trace(1, "operator - (matrix <T>& b)");}
   
   int nrow, ncol;
   if( mptr == NULL) { error_mess(16); (*this)(1)=1;(*this)(2)=1; return(*this);}//////////////////
   if( b.mptr == NULL) { error_mess(6); (*this)(1)=1;(*this)(2)=1; return(*this);}  
   if(num_rows != b.num_rows){ error_mess(29); (*this)(1)=1;(*this)(2)=1; return(*this);}//Prof Dodds said we could use exit(0)
   if(num_cols != b.num_cols){ error_mess(30); (*this)(1)=1;(*this)(2)=1; return(*this);}//Prof Dodds said we could use exit(0)
   matrix<T> temp;
   temp.subtract (*this,b);
   
   if(debug) {user_trace(2, "operator - (matrix <T>& b)");}
   set_debug_off();
   return temp;   
}

template < class T >
matrix<T>& matrix<T> :: operator = (const matrix <T>& rhs)
{
   set_debug_off();
   if(debug) {user_trace(1, "operator = (const matrix <T>& rhs)");}

   string save_id = rhs.id;
   if( mptr == rhs.mptr) return(*this);
   assert( rhs.num_rows >0);
   create( save_id, rhs.num_rows, rhs.num_cols );
   (*this).copy( rhs);
  
   if(debug) {user_trace(2, "operator = (const matrix <T>& rhs)");} 
   set_debug_off();   
   return (*this);
}



template < class T >
void matrix <T> :: copy( const matrix <T>& rhs)
//matrix <T>& matrix <T> :: copy( const matrix <T>& rhs)
{
   set_debug_off();
   if(debug) {user_trace(1, "copy");}
   
   ///remove the (*this)(1)=1;(*this)(2)=1;
   if( mptr == NULL) { error_mess(16); (*this)(1)=1;(*this)(2)=1; return;}//(*this);}//////////////////
   if(num_rows != rhs.num_rows ) {error_mess(27); (*this)(1)=1;(*this)(2)=1; return;}//(*this);}////////////////// 
   if(num_cols != rhs.num_cols ) {error_mess(28); (*this)(1)=1;(*this)(2)=1; return;}//(*this);}//////////////////   
   for(int j=1; j<= num_rows*num_cols; j++)
	 {(*this)(j) = rhs(j);}
   
   if(debug) {user_trace(2, "copy");}
   set_debug_off();   
   return;
//   return(*this);	
}

template < class T >
void matrix <T> :: diagonal( T value)
{
   set_debug_off();
   if(debug) {user_trace(1, "diagonal");}
  
   if( mptr == NULL) { error_mess(6); return;}
   if( num_cols ==1){ error_mess(18); return;}
   if( ! num_rows == num_cols){ error_mess(8); return;}
   // check if the matrix has been created
   int i, j; double dzero =0.0;
   for( i=1; i <=num_rows; i++)
      {	 
         for( j=1; j <= num_cols; j++)
		    { (*this)(i,j)=dzero; }
	     (*this)(i,i) = value;
	  } 
	  
   if(debug) {user_trace(2, "diagonal");}
   set_debug_off();   
   return;
}

template < class T >
void matrix <T> :: identity(void)
{
   set_debug_off();
   if(debug) {user_trace(1, "identity");}
  
   if( mptr == NULL) { error_mess(6); return;}
   if( num_cols ==1){ error_mess(18); return;}
   if( ! num_rows == num_cols){ error_mess(8); return;}
   // check if the matrix has been created
   int i, j; double dzero =0.0, done=1.0;
   for( i=1; i <=num_rows; i++)
      {	 
         for( j=1; j <= num_cols; j++)
		    { (*this)(i,j)=dzero; }
	     (*this)(i,i) = done;
	  }
	  
   if(debug) {user_trace(2, "identity");}
   set_debug_off();   
   return;
}








//*****************************************************
//
//    invert service (method) of matrix class
//
//*****************************************************
//
//
template <class T>
void matrix <T> :: invert( matrix<T>& a, T& det )
{
   set_debug_off();
      if(debug) {user_trace(1, "invert");}
	  
   int  k, j, i, nrow, ncol;
//
//   inverts a matrix by gauss-jordan elimination.
//   also computes the determinant. check for singular matrix.
//
//   use of temporary enables non-modification of left-side
//   if matrix is singular.
//
   T zero = static_cast<T> (0.0);
   T one  = static_cast<T> (1.0);
   det  = one;
   nrow = a.num_rows;
   ncol = a.num_cols;
   assert( nrow > 0 && ncol > 0 );
   if(nrow != ncol){ error_mess(33); return;}
   matrix <T> temp( a );
//
   for( k=1; k<=nrow; k++ )
    {
     if( temp(k,k) == zero ) { det = zero; return; }
     det = det * temp(k,k);
     for( j=1; j<=ncol; j++ )
       if( j!=k ) temp(k,j) = temp(k,j) / temp(k,k);
     temp(k,k) = one / temp(k,k);
     for( i=1; i<=nrow; i++ )
       {
         if( i==k ) continue;
         for( j=1; j<=ncol; j++ )
           if( j!=k ) temp(i,j) = temp(i,j) -
                      temp(i,k) * temp(k,j);
         temp(i,k) = -temp(i,k) * temp(k,k);
       }
    }
//
   (*this) = temp;
   
   if(debug) {user_trace(2, "invert");}   
   set_debug_off();
   return;
}


/// still needs to work on error messages!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

//check existence,...............others 
template < class T >
void matrix <T> :: transpose( matrix <T> & b)
{
   set_debug_off();
   if(debug) {user_trace(1, "transpose");}
  
   if( mptr == NULL) { error_mess(6); return;}
//  if( num_cols ==1){ error_mess(18); return;}
//  if( ! num_rows == num_cols){ error_mess(8); return;}
// check if the matrix has been created
   int i, j; 
   for( i=1; i <=num_rows; i++)
      {	 
         for( j=1; j <= num_cols; j++)
		    { (*this)(i,j)=b(j,i); }
	  } 
   
   set_debug_off();
   if(debug) {user_trace(2, "transpose");}	  
   return;
}






template < class T >
void matrix<T> :: multiply(matrix <T>& a, matrix <T>& b)
{
   set_debug_off();
   if(debug) {user_trace(1, "multiply");} 
   
   int nrow, ncol, nterms, i,j,k;
   T zero = static_cast<T> (0);
   T sum; 
   if( a.mptr == NULL) { error_mess(6); return;}
   if( b.mptr == NULL) { error_mess(6); return;}   
   if(a.num_cols != b.num_rows){ error_mess(19); return;}//Prof Dodds said we could use exit(0)
   free();
   nrow = a.num_rows; ncol = b.num_cols;
   create( " ", nrow, ncol);
   //
   for( i=1; i<=nrow; i++)
      {
	   for(j=1; j<=ncol; j++)
	      {
		   sum = zero;
	       for(k=1; k<=a.num_cols; k++)
		      { sum += a(i,k) * b(k,j);}
		      (*this)(i,j) = sum;
		  }
	  }
	  
   if(debug) {user_trace(2, "multiply");}  
   set_debug_off();
   return;  
}
   

template < class T >
void matrix<T> :: add(matrix <T>& a, matrix <T>& b)
{
   set_debug_off();
   if(debug) {user_trace(1, "add");}
   
   int nrow, ncol, i,j; 
   
   if( a.mptr == NULL) { error_mess(6); return;}
   if( b.mptr == NULL) { error_mess(6); return;}  
   if(a.num_rows != b.num_rows){ error_mess(29); return;}//Prof Dodds said we could use exit(0)
   if(a.num_cols != b.num_cols){ error_mess(30); return;}//Prof Dodds said we could use exit(0)
   free();
   nrow = a.num_rows; ncol = a.num_cols;
   create( " ", nrow, ncol);
   for( i=1; i<=nrow; i++)
      {
	   for(j=1; j<=ncol; j++)
	      {
			  (*this)(i,j)= a(i,j) + b(i,j);
		  }
	  }
	  
   if(debug) {user_trace(2, "add");}
   set_debug_off();
   return;  
}
   
 
template < class T >
void matrix<T> :: subtract(matrix <T>& a, matrix <T>& b)
{
   set_debug_off();
   if(debug) {user_trace(1, "subtract");}
   
   int nrow, ncol, i,j; 
   
   if( a.mptr == NULL) { error_mess(6); return;}
   if( b.mptr == NULL) { error_mess(6); return;}  
   if(a.num_rows != b.num_rows){ error_mess(31); return;}//Prof Dodds said we could use exit(0)
   if(a.num_cols != b.num_cols){ error_mess(32); return;}//Prof Dodds said we could use exit(0)
   free();
   nrow = a.num_rows; ncol = a.num_cols;
   create( " ", nrow, ncol);
   for( i=1; i<=nrow; i++)
      {
	   for(j=1; j<=ncol; j++)
	      {
			  (*this)(i,j)= a(i,j) - b(i,j);
		  }
	  }
	  
   if(debug) {user_trace(2, "subtract");}
   set_debug_off();
   return;  
}
 
 
template < class T >
void matrix<T> :: write_to_file( fstream & file)
 {
   set_debug_off();
   if(debug) {user_trace(1, "write_to_file");} 
   
   if( num_rows == 0 ) return;
   file.write( reinterpret_cast <char *> (&num_rows), sizeof(int));
   file.write( reinterpret_cast <char *> (&num_cols), sizeof(int));
   file.write( id.c_str(), max_id_len);
   file.write( reinterpret_cast <char *> (&mptr[0]), num_rows*num_cols*sizeof(T));
   
   if(debug) {user_trace(2, "write_to_file");}   
   set_debug_off();
   return; 
 }
  
template < class T >
void matrix<T> :: read_from_file( fstream & file)
 {
   set_debug_off();
   if(debug) {user_trace(2, "read_from_file");}
   
   file.read( reinterpret_cast <char *> (&num_rows), sizeof(int));
   if(file.eof()) return;
   file.read( reinterpret_cast <char *> (&num_cols), sizeof(int));
   char temp_id[80];
   file.read( temp_id, max_id_len); id = temp_id;
   create( id, num_rows, num_cols );
   file.read( reinterpret_cast <char *> (&mptr[0]), num_rows*num_cols*sizeof(T));

   if(debug) {user_trace(2, "read_from_file");}   
   set_debug_off(); 
   return; 
 }   

 
template < class T >
void matrix <T> :: print(void)
{
   set_debug_on();
   if(debug) {user_trace(1, "print");}
  
   cout << "Matrix id:" << id << endl;
   cout << "No rows, columns: " << get_num_rows(); 
   cout <<"  "<< get_num_cols() << endl;
   cout << "Matrix values:\n";
   for( int i=1; i<=num_rows; i++)
      {
	    for(int j=1; j<=num_cols; j++)
           {
	         cout<<setw(13)<<setiosflags(ios::fixed);
		     cout<< setprecision(3)<<(*this)(i,j);
           } 
	    cout << endl;
       }
	   
    if(debug) {user_trace(2, "print");}
    set_debug_off();	
   return;
}

template < class T >
void matrix<T> :: set_debug_on(void) 
{
   debug = true;
   return;	
}
 
 
template < class T >
void matrix<T> :: set_debug_off(void) 
{
   debug = false;
   return;	
}

 

template < class T >
void matrix<T> :: user_trace(int type, string function_name )
{
  const bool on = true;
  if(! on) return;
  if(type == 1 )
	  cout << "... Trace. Entering: " << function_name << endl;
   if( type == 2)
	   cout << "...Trace. Leaving: " << function_name << endl;
   return;
}



template < class T >
void matrix<T> :: error_mess( int mess )
{
switch( mess ) 
 { 
   case 1 : 
     cout << ">>>ERROR!:Invalid matrix row no\n";
	 break;
   case 2 : 
     cout << ">>>ERROR!: The matrix has been created before \n";
	 break;
	 case 3 :
     cout << "ERRoR! row > num_rows\n";
	 break;
   case 4 : 
     cout << "ERRoR! col > num_cols\n";
	 break;	 
   case 5 : 
     cout << ">>>ERROR!:Invalid matrix col no\n";
	 break;
   case 6 : 
     cout << ">>>ERROR!: The matrix has not been created!\n";
	 break;
   case 7 : 
     cout << ">>>ERROR!: No name associated with the object!\n";
	 break;
   case 8 : 
     cout << ">>>ERROR!: num_rows not equal to num_cols"; 
	 cout << "for this identity matrix!\n";
	 break;
   case 9 : 
     cout << ">>>ERROR!: num_rows not equal to num_cols"; /////////////////////change it
	 cout << "for this identity matrix!\n";
	 break;
   case 10 : 
     cout << ">>>ERROR!: you can not create a copy\n"; /////////////////////change it
	 cout << "of a matrix that has not been created!\n";
	 break;	 
   case 11 : 
     cout << ">>>WRONG FUNCTION!:This a vector ";
	 cout << "use the right function!\n";
	 break;
   case 12 : 
     cout << ">>>WRONG FUNCTION!:This a matrix ";
	 cout << "use the right set_value function!\n";
	 break;
   case 13 : 
     cout << ">>>WRONG FUNCTION!:This a matrix ";
	 cout << "use the right get_value function!\n";
	 break;
   case 14 : 
     cout << ">>>WRONG FUNCTION!:This a vector";
	 cout << "use the right set_value function!\n";
	 break;
   case 15 : 
     cout << ">>>WRONG FUNCTION!:This a vector ";
	 cout << "use the right get_value function!\n";
	 break;
	 case 16 : 
     cout << ">>>ERROR!: The object has not been created!\n";
	 break;
   case 17 : 
     cout << ">>>ERROR!: The object to be assigned has not been created!\n";
	 break;
   case 18 : 
     cout << ">>>ERROR!: This is a vector!\n";
	 cout << "there is only identity matrix!\n";
	 break;
   case 19 : 
     cout << ">>>ERROR!: The num_cols of the first matrix !\n";
	 cout << "must be same for multiply!\n";
	 break;
	 case 21 : 
     cout << ">>>ERROR!:Invalid vector row no\n";
	 break;	
   case 22 : 
     cout << ">>>ERROR!: The vector has been created before \n";
	 break;	 
   case 26 : 
     cout << ">>>ERROR!: The vector has not been created!\n";
	 break;
   case 27 : 
     cout << ">>>ERROR!: (copy function)the num of rows of both matrices\n";
	 cout << " must be the same\n";
	 break;
   case 28 : 
     cout << ">>>ERROR!:(Copy function) the num of cols of both matrices\n";
	 cout << " must be the same\n";
   case 29 : 
     cout << ">>>ERROR!: (addition)the num of rows of both matrices\n";
	 cout << " must be the same\n";
	 break;
   case 30 : 
     cout << ">>>ERROR!:(addition) the num of cols of both matrices\n";
	 cout << " must be the same\n"; 
     break;	 
   case 31 : 
     cout << ">>>ERROR!: (subtraction)the num of rows of both matrices\n";
	 cout << " must be the same\n";
	 break;
   case 32 : 
     cout << ">>>ERROR!:(subtraction) the num of cols of both matrices\n";
	 cout << " must be the same\n"; 
     break;
   case 33 : 
     cout << ">>>ERROR!:(invert) the num of rows must be equal to the\n";
	 cout << " the num of cols\n"; 
     break;
   case 35 : 
     cout << ">>>ERROR!:in compatible matrix!";
     break;
	 case 59 : 
     cout << ">>>ERROR!:Invalid row no\n";
	 break;
   case 60:
   cout<< ">>> ERROR: work on it later is not a double!\n"; 
     break;
   default:
     cout << " invalid message number..../n please crosscheck...\n";
     break;
 }
return ;	
	
}


//***************************************************************************
//
//               matrix class:  equals
//
//***************************************************************************
//
//
template <class T>
bool matrix <T> :: equals( matrix<T>& a )
{
//
// Local variables
//
   set_debug_off();
   if(debug) {user_trace(1, "equals( matrix<T>& a )");}
   bool use_dequals;
   int i,j;
   double epsilon;
//
   if( a.num_rows != num_rows || a.num_cols != num_cols ) error_mess(35);
//
//     Switch on datatype to detect doubles/floats.  If not, just blindly use ==
//
   if( typeid(T) == typeid(double) )
     {
      use_dequals = false;
      epsilon = (double) DEPSILON;
     }
   else if( typeid(T) == typeid(float) )
     {
      use_dequals = false;
      epsilon = (double) FEPSILON;
     }
   else
     {
      use_dequals = true;
     }
//
//       Now either compare with floating point or with ==
//
   if( use_dequals )
     {
      for (i=1; i<= num_rows; i++)
        for (j=1; j<=num_cols; j++)
          if ( (*this)(i,j) != a.get_value(i,j) ) return false;
     }
   else
     {
      for (i=1; i<=num_rows; i++)
        for (j=1; j<=num_cols; j++)
        if ( (double) fabs((*this)(i,j)-a.get_value(i,j)) > epsilon) return false;
     }
//
   if(debug) {user_trace(2, "equals( matrix<T>& a )");}
   set_debug_off();
   return true;
}


//***************************************************************************
//
//               matrix class:  nequals
//
//***************************************************************************
//
//
template <class T>
bool matrix <T> :: nequals( matrix<T>& a)
{
  return !( (*this).equals(a) );
}

//***************************************************************************
//
//               matrix class:  operator==
//
//***************************************************************************
//
//
template <class T>
bool matrix<T> :: operator==(matrix<T>&b)
{
   set_debug_off();
   if(debug) {user_trace(1, "operator==(matrix<T>&b)");}
  
   return (*this).equals(b);
}

//***************************************************************************
//
//               matrix class:  operator!=
//
//***************************************************************************
//
//
template <class T>
bool matrix<T> :: operator!=(matrix<T>&b)
{
   set_debug_off();
   if(debug) {user_trace(1, "operator!=(matrix<T>&b)");}
   
   return (*this).nequals(b);
}

template class matrix <int>;
template class matrix <float>;
template class matrix <double>;



