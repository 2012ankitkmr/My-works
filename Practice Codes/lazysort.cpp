#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("in.txt","r",stdin);
    freopen("out.txt","w+",stdout);
	int t,n,a[50005],flag,ind;
	scanf("%d",&t);
	for(int test=1;test<=t;test++)
	{
		vector<int>vec;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	flag=0;
	
	for(int i=1;i<=n;i++)
	{
	if(a[i]==1)
	ind=i;	
	}	
	if(a[1]<a[2])
	{	
    for(int i=ind;i<=n;i++)
    {
    	vec.push_back(a[i]);
    }	
	for(int i=1;i<ind;i++)
	{
		vec.push_back(a[i]);
	}
	for(int i=0;i<n;i++)
	if(vec[i]!=(i+1))
	flag=1;
		
   }
   else
   {
   	for(int i=ind;i>=1;i--)
    {
    	vec.push_back(a[i]);
    }	
	for(int i=n;i>ind;i--)
	{
		vec.push_back(a[i]);
	}
	for(int i=0;i<n;i++)
	if(vec[i]!=(i+1))
	flag=1;
   	
   }
   printf("Case #%d: ",test);
   if(flag)
   printf("no\n");
   else
   printf("yes\n");
   
	}
	
	
	return 0;
}
