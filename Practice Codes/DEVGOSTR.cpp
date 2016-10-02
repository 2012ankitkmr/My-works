#include<bits/stdc++.h>
using namespace std;
int main()
{
	int test,a,k,cnt;
	char s[80];
	
	for(scanf("%d",&test);test--;)
	{
		cnt = 0;
		scanf("%d%d",&a,&k);
		scanf(" %s",s);
		if(a==1)
		{
			for(int i=0;s[i];i++)
			if(s[i]!='a')
			cnt++;
			
			if(cnt<=k&&(strlen(s)<3))
			printf("1\n");
			else
			printf("0\n");
	
		}
		else
		printf("2\n");
		
	}
	
	return  0;
}
