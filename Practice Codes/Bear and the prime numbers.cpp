#include<bits/stdc++.h>
using namespace std;
#define MAXN 10000000


bool sieve[MAXN+5];
int f[MAXN+5];
long long cumulativef[MAXN+5];
int a[MAXN+6];
int main()
{
	//freopen("in.txt","r",stdin);

	int i=2,tempsqr,secondnum,j,num,temp,cnt;
	
	while(i<=3165)
	{
		if(!sieve[i])
		{
		 j=2,num=i*j;
			while(num<=MAXN+1)
			{
				sieve[num]=1;		
				j++;				
				num=i*j;	
			}
			
		}
		i++;
	}	
		vector<int>vec;
	for(i=2;i<=MAXN+1;i++)
	{
		if(!sieve[i])
		vec.push_back(i);		
	}
	int n;
scanf("%d",&n);	
	for(i=0;i<n;i++)
	{
	scanf("%d",&temp);
	a[temp]++;
    }
    for(i=0;i<vec.size();i++)
    {
    	j=1;
    	cnt=0;
    	while((num=vec[i]*j)<=MAXN)
    	{
		cnt+=a[num];
    		j++;
    	}
    	f[vec[i]]=cnt;
    }
	
cumulativef[0]=f[0];
	for(i=1;i<=MAXN;i++)
	{
		cumulativef[i]=cumulativef[i-1]+f[i];
	}
	int m,l,r;
	scanf("%d",&m);
	while(m--)
	{
		scanf("%d%d",&l,&r);
		if(l>MAXN)
		printf("0\n");
		else if(l<MAXN&&r>MAXN)
		cout<<cumulativef[MAXN]-cumulativef[l-1]<<"\n";
		else
		cout<<cumulativef[r]-cumulativef[l-1]<<"\n";
				
	}
	
	return 0;
}
