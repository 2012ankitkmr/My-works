using namespace std;
#include<iostream>
#include<math.h>

int main(){
	
	long long unsigned int N,j,c,b;
	int T,i;
	long int M;
	cin>>T;
	
for(i=0;i<T;i++)
{
	cin>>N;
	cin>>M;
	b=0;
	for(j=1;j<=N;j++){
		c=N/j;
	b=b+(pow(j,4))*c;	
	}
	b=b%M;
	cout<<b<<endl;;
}
return 0;
}

