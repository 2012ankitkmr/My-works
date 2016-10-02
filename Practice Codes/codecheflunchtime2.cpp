using namespace std;
#include<iostream>
#include<algorithm>
#include<iomanip>
int main(){
	short int i,t;
	cin>>t;
	long unsigned int b,j;
	double c=0;
	for(i=0;i<t;i++){
		cin>>b;
		long unsigned int a[b];
		for(j=0;j<b;j++){
			cin>>a[j];
		}
		sort(a,a+b);
c=0;
if(b%2==0){
		for(j=1;j<b;j+=2){
               c=c+a[j];
    }            }
else{
        for(j=0;j<b;j+=2)
        {
            c=c+a[j];
        }
        }

		cout<<setprecision(10)<<c;
}
return 0;
}
