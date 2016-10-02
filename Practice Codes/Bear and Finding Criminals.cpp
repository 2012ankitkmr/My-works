#include<bits/stdc++.h>
using namespace std;

int a[105];
int main()
{
	int n,loc,b1,b2,ans =0,pos,flag,dist;
	scanf("%d%d",&n,&pos);
	for(int i = 1 ; i<=n;i++)
	scanf("%d",&a[i]);
	
	int p = max(abs(n-pos),pos-1);
	
	if(a[pos])
	ans++;

	 dist = 1;
//printf("%d\n",p);
	while(p>=1)
	{
		
	flag = 0;
	if(pos+dist<=n)
	b1 = a[pos+dist];
	else if(pos+dist>n)
	{	
	flag =1;
	b1 = 1;
    }
	if(pos-dist>=1)
	b2 = a[pos-dist];
	else if(pos-dist<=0)
 	{
    flag =1;	
	b2 = 1;
    }
    //	printf("%d %d\n",b1,b2);
	if(b1&b2)
	{
		if(!flag)
		ans+=2;	
		else
		ans++;	
	}
		
	
	dist++;	
	p--;	
	}
	printf("%d\n",ans);
	return 0;
}
