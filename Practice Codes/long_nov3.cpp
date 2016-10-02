#include<iostream>
using namespace std;
int main(){
	
	long int t,i,n,a,b,u,j,flag,f,z;
	long int x[300][300];
	long int y[300];
	
	cin>>t;
	for(i=0;i<t;i++)
	{
	cin>>n;
	
	for(a=0;a<n;a++)
	{
		for(b=0;b<n-1;b++)
		{
			cin>>x[a][b];
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
		        if(b!=u){
				if(x[b][z]==y[z])
		           f++;
		           else 
		           break;
		 			}
                   else
		            break;
		}
		if(f==n-1)	
	{j=1;
		break;
	}
	a=u;
}
	if(j)	
		break;
 
a=u;
}	
	
if(j==1)
{
for(a=0;a<n-1;a++)
cout<<y[a]<<" ";	
}
cout<<y[n-1]<<"\n";
}
	return 0;
} 
