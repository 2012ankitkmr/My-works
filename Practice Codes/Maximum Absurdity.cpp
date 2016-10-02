#include<bits/stdc++.h>
using namespace std;
#define ll long long 


int n,k;
int a[200005];
ll wa[200005],wb[200005];

struct pref{
	ll val,ind;
	
}prefmax[200005];

int main()
{
	scanf("%d%d",&n,&k);
	
	for(int i = 0;i<n;i++)
	scanf("%d",&a[i]);
	ll temp=0;
	for(int i =0 ;i<k;i++)
	{
		temp+=a[i];
	}
	wa[0]=temp;
	
	for(int i =1;i<=n-2*k;i++)
	{
		wa[i]=wa[i-1]-a[i-1];
		wa[i]+=a[i+k-1];
	
	}
	
	temp=0;
	for(int i =k ;i<2*k;i++)
	{
		temp+=a[i];
	}
	wb[k]=temp;
	for(int i =k+1;i<=n-k;i++)
	{
		wb[i]=wb[i-1]-a[i-1];
		wb[i]+=a[i+k-1];	
	}
	
	prefmax[n-k].val = -1;
	prefmax[n-k].ind = n-k; 
	for(int i = n-k;i>=k;i--)
	{
		
		if(prefmax[i+1].val<=wb[i])
		{
			prefmax[i].val = wb[i];
			prefmax[i].ind = i;
		}	
		else
		{
		
		prefmax[i].val = prefmax[i+1].val;	
		prefmax[i].ind = prefmax[i+1].ind;
	}
	}

	ll ans =-1;
	int i_a = -1,i_b=-1;
	for(int i = 0 ; i<=n-2*k ;i++)
	{
		
		if((wa[i]+prefmax[i+k].val)>ans)
		{
			ans = wa[i]+prefmax[i+k].val;
			i_a = i;
			i_b = prefmax[i+k].ind;
		}
		
	}
	
	printf("%d %d\n",i_a+1,i_b+1);
	return 0;
}
