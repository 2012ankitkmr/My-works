#include<bits/stdc++.h>
using namespace std;
#define ll long long
/* REfrence taken from geeksforgeeks*/
struct Box
{
  ll h, w, d;  // for simplicity of solution, always keep w <= d
};
 
int compare (const void *a, const void * b)
{
    return ( (*(Box *)b).d * (*(Box *)b).w ) -
           ( (*(Box *)a).d * (*(Box *)a).w );
}
 
ll maxStackHeight( Box arr[], ll n )
{
   Box rot[3*n];
   ll index = 0;
   for (ll i = 0; i < n; i++)
   {
      rot[index] = arr[i];
      index++;
 
      rot[index].h = arr[i].w;
      rot[index].d = max(arr[i].h, arr[i].d);
      rot[index].w = min(arr[i].h, arr[i].d);
      index++;
      rot[index].h = arr[i].d;
      rot[index].d = max(arr[i].h, arr[i].w);
      rot[index].w = min(arr[i].h, arr[i].w);
      index++;
   }
 
   n = 3*n;
   qsort (rot, n, sizeof(rot[0]), compare);
 
   ll msh[n];
   for (ll i = 0; i < n; i++ )
      msh[i] = rot[i].h;
   for (ll i = 1; i < n; i++ )
      for (ll j = 0; j < i; j++ )
         if ( rot[i].w < rot[j].w &&
              rot[i].d < rot[j].d &&
              msh[i] < msh[j] + rot[i].h
            )
         {
              msh[i] = msh[j] + rot[i].h;
         }
 
 
   ll max = -1;
   for ( ll i = 0; i < n; i++ )
      if ( max < msh[i] )
         max = msh[i];
 
   return max;
}
int main()
{
 ll n;
 Box arr[152];
  cin>>n;
  for(ll i = 0;i<n;i++)
  {
  	scanf("%lld%lld%lld",&arr[i].h,&arr[i].w,&arr[i].d);
  }
 
  printf("%lld",maxStackHeight (arr, n) );
 
  return 0;
}
