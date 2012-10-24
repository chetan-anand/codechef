#include <stdio.h>
#include <math.h>
#define x 50000
int main () {
  int i, j, l = sqrt(x) + 1,t, num ;
  long long int ans ;
//function 1

//here initiallizing the array
  char array1[x] = {0} ;
  for (i=2;i<l;i++ )
  {
    if( array1[i] == 0 )
    {
      for(j=i*i;j<x;j=j+i)
    array1[j] = 1 ;
    }
  }
  scanf ( "%d", &t ) ;


  while ( t -- )
   {
    l = 0 ;
    scanf ( "%d", &num ) ;
    ans = 1 ;
    for ( i = num+1 ; i <= x ; i ++ )
      if ( array1[i] == 0 )
        break ;
    ans =ans*i ;
    for ( ++i ; i <= x ; i ++ )
      if ( array1[i] == 0 )
        break ;
    ans =ans*i ;
    printf ( "%d\n", ans ) ;
  }


  return 0 ;
}
