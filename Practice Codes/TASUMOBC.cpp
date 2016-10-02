#include<stdio.h>
long long int fact(long long int x,long long int y)
{ if(x==y)
	return 1;
	else if(x==1)
	return 1;
	else if(x==0)
	return 1;
	else
        return fact(x-1,y)*x;
}

long long int fact1(long long int z)
{
	if(z==0)
	return 1;
	else if(z==1)
	return 1;
	
	else
	return fact1(z-1)*z;
	
} 
int main(){
	long int t;
	scanf("%ld",&t);
	long long int n,r,d,e,h,f;
	while(t--)
	{ 
		scanf("%lld",&n);
		d=0;
		h=n/2;
		for(r=0;r<h;r++)
		{
		  e=fact(n,n-r);
		  
		  
		  if(fact1(r));
		  e=e/fact1(r);
		 // printf("e=%lld\n",e);
		  e=e%3;
		  d=d+e;
		}	
		d=2*d;
	//	 printf("d=%lld\n",d);
		if(n%2==1)
		{ e=fact(n,h+1);
		if(fact1(h))
		   e=e/fact1(h);
		e=e%3;
		d=d+2*e;
	}
		else
		{
		e=fact(n,h);
		if(fact1(h))
		e=e/fact1(h);
		e=e%3;
		d=d+e;
	}
		d=d%1000000007;
		printf("%lld\n",d);	
}
return 0;	
}
