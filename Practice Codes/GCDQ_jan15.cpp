#include<stdio.h>

long int ArrayGCD(long int *a,long int first,long int last)
{
   long int x = 0, y = 0, gcd = 0;
    if(first == last)
    {
        gcd = a[first];
        return gcd;
    }
    else
    {
        x = ArrayGCD(a,first,(first+last)/2);
        y = ArrayGCD(a,(first+last)/2+1,last);
        while(x != y)
        {
            if(x > y)
            {
                x = x-y;
            }
            else
            {
                y = y-x;
            }
        }
        gcd = x;
        return gcd;
    }
}



int main()
{
	int t;
	long int n,g,i,j,q,a[100005],l,r,e,c;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%ld%ld",&n,&q);
		
		for(i=1;i<=n;i++)
		scanf("%ld",&a[i]);
		
		for(i=0;i<q;i++)
		{ 
		e=a[1];
		scanf("%ld%ld",&l,&r);
		if(l==1)
		e=a[r+1];
		if(l!=1)
		{
			g=ArrayGCD(a,1,l-1);
			if(e>g)
			e=g;
		}	
		c=a[r];
		a[r]=e;
		g=ArrayGCD(a,r,n);
		if(e>g)
		e=g;	
		a[r]=c;	
		printf("%ld\n",e);	
		}
	}
	return 0;
}


