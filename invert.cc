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
  ncol = nrow;
  assert( nrow > 0 && ncol > 0 );
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
  return;
}
