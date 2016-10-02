#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,a[111],b[111],fsum=0,Ssum=0,indep_cnt=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
		fsum+=a[i];
		Ssum+=b[i];
		if(((a[i]&1)&&!(b[i]&1))||(!(a[i]&1)&&(b[i]&1)))
	     indep_cnt++;	
	}
	if((fsum%2==0)&&(Ssum%2==0))
	printf("0\n");
	else if((fsum&1)&&(Ssum&1))
	{
		if(indep_cnt)
		printf("1");
		else
		printf("-1");
	}
	else
	{
		if(indep_cnt>2)
		printf("1");
		else
		printf("-1");
		
	}
	
	
return 0;
}
