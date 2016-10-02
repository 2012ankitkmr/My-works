#include<bits/stdc++.h>

using namespace std;
int a[100005];
char s[100005];
int sum[100005][2];
void count_sum()
{
	for(int it=0;s[it];it++)
	{
		sum[it][0]=sum[it-1][0]+a[it];
		
		sum[it][1]=sum[it-1][1]+(a[it]*(int)(s[it]-'0'));
	}
	
}

int main()
{
	int n,cnt1(0),pos,pos_r,pos_k;
	
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
	scanf("%s",s);
	count_sum();
	for(int i=0;s[i];i++)
	if(s[i]=='1')
	cnt1++;
	int ans=0;
	int sumf=0;
	if(cnt1==0)
	printf("0\n");
	else if(cnt1==1)
	{
		if(s[0]=='1')
		printf("%d\n",a[0]);
		else
		{
			for(int i=0;i<n;i++)
			if(s[i]=='1')
		    printf("%d\n",max(a[i],sum[i-1][0]));
		}
	}
	else
	{
	pos=n;
		while(s[--pos]=='0');
		pos_r=pos;  // The sequence is like a1,a2,a3,.....ak-1,ak,.......ar-1,ar,.....an
		if(a[pos_r]==0)
		{
		printf("%d\n",sum[pos_r-1][0]);
		return 0;
	    }
	    else
	    {
	    	while(1)
	    	{
	    		if(pos_r!=0)
	           ans=max(ans,sumf+sum[pos_r-1][0]);
		    ans=max(ans,sumf+sum[pos_r][1]);
	    	
			sumf+=a[pos_r];
			while(s[--pos_r]=='0');	
	    if(pos_r<=0)	
	      break; 
		    } 
			
			printf("%d\n",ans); 
	    }
	}
	
	return 0;
}
