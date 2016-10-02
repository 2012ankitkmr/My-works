#include<bits/stdc++.h>
using namespace std;

long long sum[100005],b[100005],summation[100005];
int main()
{
//	freopen("the_price_is_correct.txt","r",stdin);
//	freopen("out.txt","w+",stdout);
	int t,n,first_pointer,second_pointer,flag;
	long long p,tempsum,ans,prev_second_pointer;
	summation[0]=0;
	for(int i=1;i<=100000;i++)
	{
		summation[i]=summation[i-1]+i;	
	}
/*	for(int i=1;i<=10;i++)
	printf("%d ",summation[i]);
	printf("\n");*/
	scanf("%d",&t);
	for(int test=1;test<=t;test++)
	{
		scanf("%d%lld",&n,&p);
		memset(sum,0,sizeof sum);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&b[i]);
		}
		//sort(b+1,b+n+1);

		sum[0]=0;
		for(int i=1;i<=n;i++)
		{
			sum[i]=sum[i-1]+b[i];			
		}
/*	for(int i=1;i<=n;i++)
	printf("%lld ",sum[i]);
	printf("\n");*/
		tempsum=0;
		flag=1;
		ans=0;
		first_pointer=0;second_pointer=0,prev_second_pointer=0;;
		while(second_pointer<=n)
		{
			tempsum=sum[second_pointer]-sum[first_pointer];
			if(tempsum>p)
			{
				if(flag)
				{
				///	printf("%d %d\n",first_pointer,second_pointer);
				ans+=summation[second_pointer-1-first_pointer];
			    
			    if(prev_second_pointer>first_pointer)
				ans-=summation[prev_second_pointer-first_pointer];
				prev_second_pointer=second_pointer-1;
				}
				first_pointer++;
				flag=0;
			}
			else
			{
				second_pointer++;
				flag=1;
			}
			
		}
		
		if(flag)
		{//printf("%d %d\n",first_pointer,second_pointer);
		ans+=summation[second_pointer-1-first_pointer];
		 if(prev_second_pointer>first_pointer)
				ans-=summation[prev_second_pointer-first_pointer];
	}
		printf("Case #%d: %lld\n",test,ans);
	}
	
	
	return 0;
}
