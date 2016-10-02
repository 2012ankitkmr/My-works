#include<iostream>
int main(){
	
	std::ios::sync_with_stdio(false);
	long int n,i,l,r,f,e,d,y;
	long int a[100000],b[2][100000];
	std::cin>>n;
	long long int c[100000],sum=0;
	for(i=0;i<n;i++)
	std::cin>>a[i];
	
	for(i=0;i<n;i++)
	{sum=0;
	std::cin>>b[0][i]>>b[1][i];
	for(d=b[0][i]-1;d<b[1][i];d++)
	sum=sum+a[d];
	
	c[i]=sum;
	}
	std::cin>>r;

for(i=0;i<r;i++)
{
	std::cin>>l>>f>>e;
	if(l==1)
	{ y=e-a[f-1];
	a[f-1]=e;
	for(d=0;d<n;d++)
	{
if(b[0][d]<=f&&b[1][d]>=f)
	c[d]=c[d]+y;
	}
}

if(l==2)
{         sum=0;
	for(d=f-1;d<e;d++)
		sum=sum+c[d];
		
	std::cout<<sum<<"\n";
}	
}
return 0;	
}
