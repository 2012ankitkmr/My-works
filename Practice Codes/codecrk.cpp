#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	double n,i,k,s,a,b;
	double temp1,ak,temp2;

	cin>>i>>k>>s;
	cin>>a>>b;
 
	if(i>k)
	{
	temp2=(i-k);
	if((ll)temp2%2!=0)
	{
	
	temp2++;
ak=a;
	a=(sqrt(2)*(a+b)-sqrt(6)*(a-b));
	
	b=(sqrt(2)*(ak-b)+sqrt(6)*(ak+b));
    }

temp1=(a+b);
temp1/=pow(2,2*temp2+s); 
	}
	else if(k>i)
	{
	    temp2=(k-i);
	if((ll)temp2%2!=0)
	{
	ak=a;
	temp2--;
		a=sqrt(2)*(a+b)-sqrt(6)*(a-b);	
	b=sqrt(2)*(ak-b)+sqrt(6)*(ak+b);
	
	}
	
	temp1=(a+b);
	temp1*=pow(2,2*temp2-s);
	}
	else
	{
		temp1=(a+b)/pow(2,s);
	}
	printf("%lf",temp1);
 
	return 0;
} 
