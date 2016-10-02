#include<bits/stdc++.h>
using namespace std;


int cnt[4],a[100005];

int main()
{
	int n,req_amount,net_amount,flag;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
	scanf("%d",&a[i]);
	a[i]/=25;
    }
    cnt[1]=0;
    cnt[2]=0;
    flag=0;
    for(int i=0;i<n;i++)
    {
    	req_amount=a[i]-1;
    	net_amount=cnt[1]*1+cnt[2]*2;//available amount that can be retuned
    	if(req_amount==0)
    	{
    	cnt[1]++;
    	continue;
	    }
	    
		if(net_amount<req_amount)
    	{
    		flag=1;
    		break;
    	}
    	
    	else
    	{
    		if(!cnt[1])
    		{
			flag=1;
    		break;
    		}
    		else
    		{
    			if(req_amount==3)
    			{
    				if(cnt[2])
    				{
    					cnt[2]--,cnt[1]--;
    				}
    				else
    				{
    					cnt[1]-=3;
    				}
    			}
    			else
    			{
    				cnt[2]++;
    				cnt[1]--;	
    			}
    			
    			
    		}
    		
    	}
    	
    }
if(flag)
printf("NO\n");
else
printf("YES\n");
	
	return 0;
}
