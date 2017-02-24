#include<bits/stdc++.h>
using namespace std;

long long  n,m,cnt1[6],cnt2[6];

int main()
{
cin>>n>>m;
cnt1[0]=n/5;	
cnt1[1]=n/5;	
cnt1[2]=n/5;	
cnt1[3]=n/5;	
cnt1[4]=n/5;	

n=n %5;
for(int i = 1 ; i<=n;i++)
{
	cnt1[i]++;
}

cnt2[0]=m/5;	
cnt2[1]=m/5;	
cnt2[2]=m/5;	
cnt2[3]=m/5;	
cnt2[4]=m/5;	

	
m = m%5;
for(int i = 1 ; i<=m;i++)
{
	cnt2[i]++;
}

long long ans = 0;
for(int i=0;i<5;i++)
{
	ans+=(cnt1[i]*cnt2[(5-i)%5]);
}
cout<<ans;
return 0;

}
