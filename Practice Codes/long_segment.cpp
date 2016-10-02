#include<iostream>
#include<cmath>
int main()
{
	std::ios::sync_with_stdio(false);
	long int j,y,t,i,n,l;
	long long int k;
	double d,e;
	std::cin>>t;
	for(i=0;i<t;i++)
	{
		std::cin>>n>>k;
		d=(long long int)n;
		l=0;
		y=0;
		while(1)
		{
			if(k>=pow(2,l)&&k<pow(2,l+1))
			break;
			else
			l++;
			
			y++;
		}
		for(j=0;j<=y;j++)
		{
			d=d/2;
		}
		e=d;
		l=k-pow(2,y);
		while(l>1)
		{
			e=e+2*d;
			l--;
		}
		std::cout<<e<<"\n";
		
	}
	return 0;
}
