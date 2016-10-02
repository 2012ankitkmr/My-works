#include <bits/stdc++.h>
using namespace std ;
#define LIM 1000010
long zoro [LIM] ;

int main(){
   long i , j ,k , n , p , ans ;
   zoro[0] = 0 ;
   zoro[1] = 0 ;
   for ( i = 2 ; i < LIM-5 ; i++ )
   zoro[i] = (i-1)^zoro[i-1] ;
   
   cin >> n ;
   cin >> p ;
   ans = p ;
   for ( i = 1 ; i < n ; i++ )
   {
   	  scanf("%ld",&p);
   	  ans ^= p ;
   }

   for ( i = 1 ; i <= n ; i++ ){
   	   long temp = zoro[i]^0 ;
   	   if ( (n/i) % 2 )
   	   ans = ans ^ temp ;

   	   long rem ;
   	   rem = n%i ;
   	   if ( rem ){
   	   	 ans ^= zoro[rem+1] ;
   	   }
   }

   cout << ans<<endl;
	return 0  ;
}
