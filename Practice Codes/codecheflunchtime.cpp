using namespace std;
#include<iostream>
#include<algorithm>

int main(){
	short t,i;
	cin>>t;
	long unsigned int b,j,c;
	for(i=0;i<t;i++){
		cin>>b;
		long unsigned int a[b];
		for(j=0;j<b;j++){
			cin>>a[j];
		}
		sort(a,a+b);
		
		c=0;
		for(j=b;j>=0;j--){
			c=c+a[j];
		}
		
		cout<<c;
	}
	return 0;
}

