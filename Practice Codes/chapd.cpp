# include <stdio.h>
# include <math.h>
 
long long int gcd(long long int a,long long int b)
{
	 if ( a==0 ) return b;
  return gcd ( b%a, a );
}
int main()
{
    long long int t,x,ans,y;
    for(scanf("%lld",&t);t--;)
    {
    	scanf("%lld",&x);
    	scanf("%lld",&y);
    	ans=2;
    	while(ans!=1)
    	{
    	ans=gcd(x,y);
    	y/=ans;
    	}
    	if(y==1)
    	printf("Yes\n");
    	else
    	printf("No\n");
   }
    return 0;
} 
