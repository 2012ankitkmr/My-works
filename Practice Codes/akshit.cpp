using namespace std;
#include<iostream>
#include<string.h>

long int c[1000008];

int main()
{
  long int j,z,y,d,n,l,r,a,k,b,x;
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>n>>l>>r;z=0;
		d=0;
		a=r-l;
		b=0;
		x=0;
		y=0;
	//	memset(c,0,1000000);
		
		for(j=1;j<=n;j++)
		{
			k=0;
			if(j==2)
			{
				while(a>0)
				{
					d+=a;
					c[x]=a;
					a--;x++;
				}
			}
			if(j==1)
			{
				z=n*(r-l+1);
			}
			if(j>2)
			{
				while((j-2)*d>b)
				{
					b+=c[k];
					c[k]=(j-2)*d-b;
					y+=c[k];
					k++;
					
				}
				
			}//end of this if loop
		}
		cout<<y+z+d%(1000000+3);
	}
	
	return 0;
	
	
}
