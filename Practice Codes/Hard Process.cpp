#include<bits/stdc++.h>
using namespace std;


int  a[300005];
int main()
{
	
	int k,n;
	scanf("%d%d",&n,&k);
	for(int i = 1; i <=n ; i++)
	scanf("%d",&a[i]);

int lp=1,rp=1;
int cnt = 0;
int ans = INT_MIN,left,right;
while(rp<=n)
{
	
	if(a[rp]==0)
	{
	cnt++;
    }
    if(cnt>k)
    {
    	while(a[lp++]!=0);
    	cnt--;
    }
    
//    printf("%d %d %d\n",ans,lp,rp);
//    ans = max(ans,rp-lp+1);
if(ans<(rp-lp+1))
{
	ans = rp-lp+1;
	left =lp;
	right = rp;
}
	    
	rp++;     
}
printf("%d\n",ans);
for(int i = left;i<=right;i++)
a[i]=1;

for(int i = 1;i<=n;i++)
printf("%d ",a[i]);
	
	return  0;
}
