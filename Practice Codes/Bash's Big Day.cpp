#include<bits/stdc++.h>
using namespace std;
#define pb push_back
vector<int>pr,a;
bool sieve[100005];
int cnt[100005],nu[100005];

int main()
{
	int i =2,n,x;
	
	while(i<=100000)
	{
		if(!sieve[i])
		{
			int j =2,num;
			while((num=i*j)<=100000)
			{
				sieve[num]=1;
				j++;
			}

			
		}
		i++;
	}

for(int i =2;i<=100000;i++)
{
	if(!sieve[i])
		pr.pb(i);
}

cin>>n;
for(int i = 0 ; i < n ; i++)
{
	scanf("%d",&x);
if(!nu[x])
a.pb(x);
nu[x]++;
}
for(int j = 0 ; j < a.size() ; j++)
{
	for(int i = 0 ; i < pr.size() ; i++)
	{
		if( a[j] < pr[i])
		 break;
	
	if(a[j]%pr[i]==0)
	cnt[pr[i]] += nu[a[j]];
    
	}
}

int ans = INT_MIN;
	for(int i =2;i<=100000;i++)
	{
		ans = max(ans,cnt[i]);
	}
	if(ans==0)
	ans =1;
	cout<<ans<<endl;
	return 0;
}
