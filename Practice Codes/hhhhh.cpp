#include<iostream>
#include<cmath>
int main(){
	
	long int t,x,i;
	int flag=0;
	long long unsigned int a,k,j,l;
	double d,e;
	std::ios::sync_with_stdio(false);
	std::cin>>t;
	for(i=0;i<t;i++)
	{
		std::cin>>x>>k;
		d=(long int)x;
l=0;
e=d/2;
while(k>1)
{ 
d=d/2;
e=d;
a=1;
flag=0;
//cout<<"d="<<d<<" e="<<e<<endl;
	while(a<=pow(2,l)&&k>1)
	{ 	e=e+2*d;
	 	//cout<<"d="<<d<<" e="<<e<<endl;
		k--;
		a++;
		flag=1;
	}
	if(e>x)
	{
	e=e-x;
	e=e/2;
}
l++;
 
	if(flag!=1)
	k--;
}
	std::cout<<e<<"\n";
		
	}
	return 0;
} 
