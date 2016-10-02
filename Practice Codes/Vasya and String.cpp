#include<bits/stdc++.h>
using namespace std;


char s[100005];
int main()
{
	
	int n,k;
	scanf("%d%d",&n,&k);
	scanf(" %s",s);
	int leftpointer = 0,rightpointer=0,x,maxval= INT_MIN,cnta=0,cntb=0;
	
	int flag = 0;
while(rightpointer < n)
{
	if(!flag)
	{
	
	if(s[rightpointer]=='a')
	cnta++;
	else
	cntb++;
  }
	x = min(cnta,cntb);
	if(x<=k)
	{
		rightpointer++;
		
		//update
		maxval=max(maxval,cnta+cntb);
		flag  = 0;
	}
	else
	{
		if(s[leftpointer]=='a')
		cnta--;
		else
		cntb--;
		leftpointer++;
		flag =1;
		
	}
//	printf("%d %d\n",cnta,cntb);
	
}
printf("%d\n",maxval);
	return 0;
}
