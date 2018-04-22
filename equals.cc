
Add these lines to your *.h file for matrix class
=================================================

#include <typeinfo>

#define FEPSILON 0.000001
#define DEPSILON 0.0000000000001


Add these four prototypes in *.h for your matrix class
======================================================

      bool operator==(matrix<T> &);
      bool operator!=(matrix<T> &);
      bool equals( matrix& );
      bool nequals( matrix& );


Add these functions to your matrix class. May need to change some variable
names based on your scheme
============================================================================


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
  bool use_dequals;
  int i,j;
  double epsilon;
//
  if( debug ) trace_message(18);
  if( a.num_rows != num_rows || a.num_cols != num_cols ) message(5);
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
  return (*this).nequals(b);
}
