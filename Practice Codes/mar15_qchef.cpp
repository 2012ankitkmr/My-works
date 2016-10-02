#include<stdio.h>
#include<string.h>
int main()
{
	long int j,i,n,k,q,a[100006],b[100006],l,r,ans;
	
	memset(b,0,400024);
		scanf("%ld%ld%ld",&n,&k,&q);
		a[0]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%ld",&a[i]);			
		}

		while(q--)
		{
		ans=0;
		scanf("%ld%ld",&l,&r);
		for(i=l;i<=r;i++)
		{
			//printf("%ld,a[i]=%d\n",b[a[i]],a[i]);
		
			if(b[a[i]]>0)
			{
				if(ans<(i-b[a[i]]))
			    ans=i-b[a[i]];	
			}
			if(b[a[i]]==0)
				b[a[i]]=i;
		}
		memset(b,0,400024);	
		printf("%ld\n",ans);	
		}
	return 0;
}
