#include<bits/stdc++.h>
using namespace std;

int b[100005];
int main()
{
	freopen("coding_contest_creation.txt","r",stdin);
	freopen("out.txt","w+",stdout);
	int t,n,i,stack_size,diff,ans;
	scanf("%d",&t);
	for(int test=1;test<=t;test++)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		scanf("%d",&b[i]);
		i=1;
		stack_size=1;
		ans=0;
	while(i<n)
	{
		
		if(b[i-1]>=b[i])
		{
			ans+=(4-stack_size);
			stack_size=1;
		}
		else
		{
			diff=b[i]-b[i-1];
			diff-=1;
			diff/=10;
			if(diff>=(4-stack_size))
			{
				ans+=(4-stack_size);
				stack_size=1;
			}
			else
			{
			ans+=diff;
			stack_size+=diff;
			stack_size++;					
			if(stack_size==4)
			{
			if(i==n-1)
			break;
			stack_size=1;
			i++;
		    }
			}
		}	
		if(i==n-1&&stack_size!=4)
		{
			ans+=(4-stack_size);
			break;
		}
		i++;
	}		
	printf("Case #%d: %d\n",test,ans);	
	}
	
	return 0;
}
