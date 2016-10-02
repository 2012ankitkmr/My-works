#include<bits/stdc++.h>
using namespace std;
int compute(int a,int b,int c,int cnt)
{
	if(a<=0&&b<=0&&c<=0)
	{
	return cnt;
}

	int ans=144444444;
	//printf("%d %d %d\n",a,b,c);
	for(int i=1;i<=9;i*=3)
	{
		for(int j=1;j<=9;j*=3)
		{
		for(int k=1;k<=9;k*=3)
		if(i!=j&&i!=k&&j!=k)
		{
		///	printf("%d%d%d\n",i,j,k);
		ans=min(ans,compute(a-i,b-j,c-k,cnt+1));
		//printf("%d\n",ans);
	}
	}
	}
	return ans;
}

int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	printf("%d\n",compute(a,b,c,0));
	
	return 0;
}
