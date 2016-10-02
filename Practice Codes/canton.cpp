#include<stdio.h>
#include<math.h>
int main()
{
    long long int n , x ,i , j ,sub , sum , t;
    
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&x);
        n=ceil((-1+sqrt(1+8*x))/2);
        sub = x - n*(n-1)/2;
        sum = n+1;
        if (n%2==0)
            printf("TERM %lld IS %lld/%lld\n",x , sub , sum-sub);    
        else
            printf("TERM %lld IS %lld/%lld\n",x, sum -sub ,sub);            
    }
    return 0;
}
