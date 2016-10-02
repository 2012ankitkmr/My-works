#include<stdio.h>

/*
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
*/

int main()
{  
	long int t,n,i,j,q,a[100005],l,r,e,c;
	scanf("%ld",&t);
	//t=next_int();
	while(t--)
	{  scanf("%ld%ld",&n,&q);
		//n=next_int();
		//q=next_int();
				
		for(i=1;i<=n;i++)
		//a[i]=next_int();
		scanf("%ld",&a[i]);
		
		for(i=0;i<q;i++)
		{  scanf("%ld%ld",&l,&r);
		//l=next_int();
		//r=next_int();
		e=a[1];
		if(l==1)
		e=a[r+1];
		
		for(j=2;j<l;j++)
		
		{  
		     while(a[j]!=0){
              c = e % a[j];
              e = a[j];
              a[j] = c;
              }
		
			if(e==1)
			break;
		}
		for(j=r+1;j<=n;j++)
		{   
		
		     while(a[j]!=0){
              c = e % a[j];
              e = a[j];
              a[j] = c;
              }
		   if(e==1)
		   break;
		}	
			
		printf("%ld\n",e);	
		}
	}
	return 0;
}


