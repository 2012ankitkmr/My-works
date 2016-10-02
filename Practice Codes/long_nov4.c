#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int x,i;	
	long unsigned int c,t,j,r,n,m,q,k;
	double d,e;
	cin>>x;//test case
	for(i=0;i<x;i++){
	cin>>n>>m>>q;	
		for(j=0;j<q;j++){
			cin>>r;
			e=1;
			if(n-r>r)
			{   t=r;
			for(k=1;k<=r;k++)
			{ c=n-r+k;
			d=pow(c,c);
			e=e*d;
			while(t>0&&e>0.000001)
			{
				e=e/pow(t,t);
				t--;
			}
			
			}
			while(t>0)
			{
				e=e/pow(t,t);
				t--;
			}
			
			
		}
			else
			{ t=n-r;
				for(k=r+1;k<=n;k++)
				{d=pow(k,k);
				e=e*d;
				
				while(t>0&&e>0.000001)
			{
				e=e/pow(t,t);
				t--;
			}
				}
			while(t>0)
		{
			e=e/pow(t,t);
	t--;
	}
			
		}
			
			e=(long int)e%m;
		cout<<e<<endl;	
		}
	
		
	}
return 0;
}
