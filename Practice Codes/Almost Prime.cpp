#include<bits/stdc++.h>
using namespace std;



int cnt[3003];
int main()
{
	int n;
	
	cin>>n;
	
	int i = 2,num,j;
	while(i<=n)
	{
	    if(!cnt[i])
	    {
	    
		j = 1;
		
		while((num=(j*i))<=n)
		{
			cnt[num]++;
			
			j++;
		}
		
	    } 
	    i++;
	}
	
	int ans=0;
	for(int i =1;i<=n;i++)
	{
		if(cnt[i]==2)
		ans++;
	}
	cout<<ans;
	
	return  0;
}
