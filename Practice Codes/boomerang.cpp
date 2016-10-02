#include<bits/stdc++.h>
using namespace  std;

int summation[2005],x[2005],y[2006],dist,length,answer;
vector<int>segment_length;
int main()
{
	
//	freopen("boom.txt","r",stdin);
//	freopen("out.txt","w+",stdout);
	int t,n,previous,len;
	summation[0]=0;
	for(int i=1;i<=2000;i++)
	{
		summation[i]=summation[i-1]+i;
	}
/*	for(int i=0;i<=20;i++)
	{
		printf("%d ",summation[i]);
	}
	printf("\n");
*/	
	scanf("%d",&t);

	for(int test=1;test<=t;test++)
	{
		scanf("%d",&n);
		
		for(int i=0;i<n;i++)
		scanf("%d%d",&x[i],&y[i]);
		
		answer=0;
		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(i!=j)
				{
				dist=(x[j]-x[i])*(x[j]-x[i])+(y[j]-y[i])*(y[j]-y[i]);	
			    segment_length.push_back(dist);
				}				
			}	
			sort(segment_length.begin(),segment_length.end());
			length=segment_length.size();
			previous=-1;
			len=1;
			for(int j=0;j<length;j++)
			{
				if(previous==segment_length[j])
				{
				len++;
				}
				else
				{
				answer+=summation[len-1];	
					len=1;
				}
				previous=segment_length[j];
			}
						
			if(len)
			{
				answer+=summation[len-1];
			}
			
			segment_length.clear();	
		}
		
		printf("Case #%d: %d\n",test,answer);		
	}
	
	return 0;
}
