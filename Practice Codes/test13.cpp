#include<iostream>
using namespace std;
#define ank if(count0>k){count0--;break;}if(count1>k){count1--;break;}
#define kmr if(ch[y]=='0') count0++;else count1++;
	            

long int dp1[100006],dp2[100006],dp4[100006],dp5[100006];
char ch[100006];
int main() {
    long int  t;
	
	long int q,n,k,x,y,count1,count0,L,R;
	for(cin>>t;t--;)
	{
	    cin>>n>>k>>q;
	    dp1[0]=0;
	    dp2[0]=0;
	    cin>>ch;
	   		count0=count1=0;
	        for(y=0;y<n;y++)
	        {
	            kmr;
	            ank;
				        }
	    dp1[1]=y;
	    dp1[0]=0;
	    for(x=1;x<n;x++)
	    {
	        if(ch[x-1]=='0')
	          {
	              count0--;
	          }
	          else
	          {
	              count1--;
	          }
	      for(;y<n;y++)
	      {
	         kmr;   
	            ank;
	      }
	      dp1[x+1]=y-x;
	    }
 
	     dp2[0]=0;
	     for(x=1;x<=n;x++)
	    {
	        dp2[x]=dp1[x]+x-1;
	    }
	    dp5[0]=0;
	    for(x=1;x<=n;x++)
	    {
	       for(y=dp5[x-1];y<=x;y++)
	         {
	             if(dp2[y]>=x){
	                 dp5[x]=y;
	                 break;
	             }
	             
	         }
	    }
	     dp4[0]=0;
	      for(x=1;x<=n;x++)
	    {
	        dp4[x]=dp2[x]+dp4[x-1];
	      } 
	    dp1[0]=0;
	    for(x=1;x<=n;x++)
	    {
	        dp1[x]=dp1[x-1]+dp1[x];
	    }
	  
	    dp1[n+1]=dp1[n];
	    
		
		for(x=0;x<q;x++)
	    {
	        cin>>L>>R;
	        count0=0;count1=0;
	         y=max(L,dp5[R]);
	         L--;
	         count0+=(dp1[R]-dp1[L]);
	         count1=(dp4[R]-dp4[y-1]);
	         count1=count1-(R*(R-y+1));
	         count0-=count1;
	         cout<<count0<<"\n";
	    }
	}
	return 0;
}
