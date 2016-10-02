#include<bits/stdc++.h>
using namespace std;
int Cb=0,Cs=0,Cc=0,nb,ns,nc,ps,pb,pc;
long long binary_search(long long int lo,long long int hi,long long int r)
{
	long long int mid=(hi+lo)/2;
long long int val_mid=max(0LL,Cb*mid-nb)*pb+max(0LL,Cs*mid-ns)*ps+max(0LL,Cc*mid-nc)*pc;
long long int val_midn=max(0LL,Cb*(mid+1)-nb)*pb+max(0LL,Cs*(mid+1)-ns)*ps+max(0LL,Cc*(mid+1)-nc)*pc;

if(val_mid<=r&&val_midn>r)
{
	return mid;
}
else if(val_mid>=r)
{
	return binary_search(lo,mid,r);
}	
else
{
	return binary_search(mid+1,hi,r);
}
}

int main()
{
	char s[105];
	long long r;
	scanf("%s",s);
	for(int i=0;s[i];i++)
	{
	if(s[i]=='B')
	Cb++;
	else if (s[i]=='S')
	Cs++;
	else
	Cc++;
	}
	
	scanf("%d%d%d",&nb,&ns,&nc);
	scanf("%d%d%d",&pb,&ps,&pc);
	cin>>r;
	long long fx=binary_search(0,10e12+1,r);
	cout<<fx;
	return 0;
}
