#include<iostream>
using namespace std;

int main(){
	long unsigned int a,i,b,j,g;
	int k=0;
	cin>>a;
	for(i=0;i<a;i++){
		cin>>b;
		while(b!=1){
		
		
		for(j=b/2;j>0;j++){
		if(b%j==0){
			g=j;
			break;
		}
			}
		b=b-g;
		k++;
		}
		if(j==0||j%2==0)
		cout<<"ALICE";
		
		else if(j==1||j%2!=0)
		cout<<"BOB";
}
return 0;
}
