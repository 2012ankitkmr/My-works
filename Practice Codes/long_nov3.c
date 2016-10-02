#include<iostream>
 
int main(){
	std::ios::sync_with_stdio(false);
	long int t,i,n,a,b,u,j,flag,f,z;
	int x[300][300];
	int y[300];
	std::cin>>t;
	for(i=0;i<t;i++)
	{
	std::cin>>n;
	
	for(a=0;a<n;a++)
	{
		for(b=0;b<n-1;b++)
		{
			std::cin>>x[a][b];
		}
	}
	j=0;
for(a=0;a<n;a++)
{
u=a; 
flag=0;
 
	for(b=1;b<n;b++)
	{ y[b]=x[a][b-1]+1;
			if(flag==0)
		{
			if(a+1==n)
			a=-1;
			
			y[b-1]=x[a+1][b-1];
			flag=1;
			a=u;
		}
}
 
	for(b=0;b<n;b++)
	{ f=0;
	
		for(z=0;z<n-1;z++)
		{     if(a+1==n)
		        a=-1;
		        if(b!=u&&b!=a+1){
				if(x[b][z]==y[z])
		           f++;
		           else
		            break;
					}
		}
		
		if(f==n-1)	
	{j=1;
		break;
	}
}
	if(j)	
		break;
 
a=u;
}	
	
if(j==1)
{
for(a=0;a<n-1;a++)
std::cout<<y[a]);	
}
std::cout<<y[n-1]<<"\n";
}
	return 0;
} 
