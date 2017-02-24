#include <bits/stdc++.h>
using namespace std;
#define ll long long 

long long ans,N;
int a[20],b[20];
int k,M;
ll A[100005];

int compute(ll n,int cnt,map<ll,int>mm)
{
	if(cnt==M+1)
	{
		int v=0;
		for (auto kv : mm) {
        A[kv.second]=kv.first;
        if(kv.second!=0)
        v++;
     }
     for(int i = 1;i<=v;i++)
     printf("%lld ",A[i]);
//	printf("here\n");
		return 1;
	
	}
	int ans = 0;
	for(int i = 0;i<k;i++)
	{
		ll c = n/a[i];
		if(n%a[i]==0)
		{
		if((c!=0)&&(!mm[c])&&(N%c==0)&&(!ans))
		{
//		    printf("%lld ",c);
		mm[c] = cnt;
		  ans = ans|compute(c,cnt+1,mm);
		   mm[c] = 0;
		
		}
	   }
	}
	for(int i = 0;i<k;i++)
	{
		ll c = n*a[i];
		if(c<N)
		{
		if((!mm[c])&&(N%c==0)&&(!ans))
		{
//		    		    printf("%lld ",c);
			mm[c]=cnt;
		  ans=ans|compute(c,cnt+1,mm);
		    mm[c] = 0;
		}
	   }
	}
	return ans;
}

int main()
{

cin>>k;
M=1,N=1;
for(int i = 0;i<k;i++)
{
cin>>a[i]>>b[i];
    M=(b[i]+1)*M;
    N = N*(pow(a[i],b[i]));
}
map<ll,int>mm;
mm[N]=1;
printf("%lld\n",N);
int ret=compute(N,2,mm);
if(!ret)
printf("No\n");

return 0;
}

