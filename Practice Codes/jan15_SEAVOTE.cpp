#include<stdio.h>

int main(){
int t,flag;
int a[10005];
long int sum,sumt,n,i,d;	
	for(scanf("%d",&t);t--;)
	{
		scanf("%ld",&n);
		
	for(i=0;i<n;i++)
	scanf("%ld",&a[i]);
	flag=0;
	sum=0;
	sumt=0;
for(i=0;i<n;i++)
	{
		if(sum>100)
		{ flag=1;
		break;
	    }
	    if(sum+a[i]>100)
	    {
	    	flag=1;
	    	break;
	    }
	    
	    
	 sumt=sumt+a[i];
	 if(a[i]>0)
		sum=sum+a[i]-1;
	}
	
if(flag==0&&sumt>=100)
   printf("YES\n");
   else
   printf("NO\n");

}
return 0;		
}

