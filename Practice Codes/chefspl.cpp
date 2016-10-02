#include<bits/stdc++.h>
using namespace std;

char s[1000006],a[1000006],b[1000006];

bool check(char s[],int la,int ra,int lb,int rb)
{
	for(int i=la;i<=ra;i++)
	{
		if(s[i]!=s[lb+i])
		return false;		
	}	
	return true;
}
int has[40];
int main()
{
	int test,len,odds,flag,diff,mid;
	for(scanf("%d",&test);test--;)
	{
		scanf(" %s",s);
		len=strlen(s);
		if(!(len&1))
		{
			if(check(s,0,len/2-1,len/2,len-1))
			printf("YES\n");
			else
			printf("NO\n");
		}
		else
		{
			memset(has,0,sizeof has);
			for(int i=0;s[i];i++)		
			has[(int)(s[i]-'a')]++;
			odds=0;
			for(int i=0;i<30;i++)
			{
				if(has[i]&1)
				{
				odds++;	
		     	}
			}		
			if(odds>1)
			printf("NO\n");
			else
			{
				mid=len/2;
					
				flag=0;
				diff=0;
				// Case 1 len1<len2
				for(int i=0,j=len/2;i<len/2&&j<len;)
				{
					if(s[i]!=s[j])
					{
						j++;
						diff++;
					}
					else
					{
						i++,j++;
					}
					
				}
				if(diff<=1)
				flag=1;
			// Case 2 len1>len2
			diff=0;
				for(int i=0,j=len/2+1;i<=len/2&&j<len;)
				{
					if(s[i]!=s[j])
					{
						i++;
						diff++;
					}
					else
					{
						i++,j++;
					}
					
				}	
			if(diff<=1)
			flag=1;
			if(flag)
			printf("YES\n");
			else
			printf("NO\n");
				
			}	
		}
		
	}
	
	return 0;
}
