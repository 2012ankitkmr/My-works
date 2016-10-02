#include<stdio.h>
long int a[400004],b[400004];
long int next_int()
{
       long int n = 0;
        char c = getchar_unlocked();
        while (!('0' <= c && c <= '9'))
        {
                c = getchar_unlocked(); 
        }
        while ('0' <= c && c <= '9')
        {
                n = (n<<3)+(n<<1) + c - '0';
                c = getchar_unlocked();
        }
        return n;
}
 
int main()
{
	int t;
	long int i,n,d,ans,f,sum;
	for(t=next_int();t--;)
	{
		n=next_int();
		for(i=1;i<=n;i++)
		{
			a[i]=next_int();
		}
		
		for(i=1;i<=n;i++)
		{
			b[i]=next_int();
		}
		
		d=next_int();
	
	ans=1000000007;
	
	for(i=1;i<=n;i++)
	{
		f=d+1-a[i];
		sum=a[i]+b[i];
		sum=sum*f;
		sum=sum-b[i];
	if(ans>d)
	d=i;
	}
	printf("%ld\n",ans);
		
	}
	return 0;
}
