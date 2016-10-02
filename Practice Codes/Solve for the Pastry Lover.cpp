#include<bits/stdc++.h>
using namespace std;


int has[1000005];
char ch[1000005];
int main()
{
	
	int n,t,temp,min_dist,temp_dist;
	for(scanf("%d",&t);t--;)
{
memset(has,0,sizeof has);
	scanf("%d",&n);
	min_dist=1111111;
	scanf(" %s",ch);
	for(int i=1;i<=n;i++)
	{
	temp=(int)(ch[i-1]-'0');
    if(has[temp])
    {
    	temp_dist=i-has[temp];
    min_dist=min(min_dist,temp_dist);
    }
    
    
	has[temp]=i;

    }
    if(min_dist==1111111)
    printf("-1\n");
    else
    
    printf("%d\n",min_dist);	
}
	return 0;
}
