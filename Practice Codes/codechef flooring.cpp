using namespace std;
#include<iostream>

int main(){
	
	long M,N,a,j,b;
	int T,i,c;
	cin>>T;
	
for(i=0;i<T;i++)
{
	cin>>N;
	cout<<" ";
	cin>>M;
	b=0;
	for(j=1;j<=N;j++)
	{
		c=N/j;
		
	b=b+(j*j*j*j*c);	
		
	}
	b=b%M;
	
	
	cout<<b;
}
	
	return 0;	
}

