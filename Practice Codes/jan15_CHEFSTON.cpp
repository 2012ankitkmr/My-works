#include<stdio.h>

/*long int next_int()
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
*/
int main()
{ int flag;
	long int t,n,j,k,i;
	double a[100003],b[100003];
	long long int ans; 
	double e;
   scanf("%ld",&t);
   //t=next_int();	
	while(t--)
	{flag=0;
		scanf("%ld%ld",&n,&k);
		//n=next_int();
		//k=next_int();
		for(i=0;i<n;i++)
		scanf("%lf",&a[i]);
		
		//a[i]=next_int();
		for(i=0;i<n;i++)
	    scanf("%lf",&b[i]);
	      //b[i]=next_int();
		
		for(i=0;i<n;i++)
		a[i]=k/(long long int)a[i];
	//	printf("%lf\n",a[0]);
			/*for(i=0;i<n;i++)
		{
			if((a[i]>=10000||b[i]>=10000)&&(k>a[i]||k>b[i]))
			flag=1;
		}
		
		if(flag)
		{ 
		for(i=0;i<n;i++)
		{	a[i]=a[i]/10000;
			b[i]=b[i]/10000;
		//printf("%f %f\n",c[i],d[i]);
		}
		ans=a[0]*b[0];
		
		for(i=0;i<n;i++)
		{
			if(a[i]*b[i]>ans)
			ans=a[i]*b[i];
		}
		ans=ans*100000000;
	}*/
    // else{
     
		ans=a[0]*b[0];
		for(i=0;i<n;i++)
		{
			if(a[i]*b[i]>ans)
			ans=a[i]*b[i];
		}
	//}
		printf("%lld\n",ans);
		
	}
	return 0;
}
