#include<bits/stdc++.h>
using namespace std;


int getv(int k)
{
	
	if(k>=50)
	return 1;
	
int temp = 50/k;
//printf("%d\n",k);
if(50%k==0)
return temp;
else
return temp+1;
	
}

int has[102];
int main()
{
	
//	freopen("lazy_loading.txt","r+",stdin);
//	freopen("out.txt","w+",stdout);
	int t,a[102],ans,cnt,p,n,fl;
scanf("%d",&t);
	for(int test = 1;test<=t;test++)
	{
	scanf("%d",&n);
	for(int i = 0;i<n;i++)
	scanf("%d",&a[i]);	
	
	sort(a , a + n);
	ans = 0;
	memset(has,0,sizeof has);
	p = 0;
	for(int i = n-1;i>=0;i--)
	{
		if(!has[i])
		{
			
			fl=1;
			has[i]=1;
			cnt = getv(a[i]);
//			printf("%d\n",a[i]);
			for(int j=p;j<p+cnt-1;j++)
			{
				if(!has[j])
				has[j] = 1;
				else
			    fl=0;		
			}
			p=p+cnt-1;
			if(fl)
			ans++;
			else
			break;
			

		}
		
	}
	printf("Case #%d: %d\n",test,ans);	
	}
	
	return 0;
}
