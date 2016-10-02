#include<iostream>
#include<string.h>
using namespace std;

long int a[1000008];


long int power(long int base, long long int exp){
	long long int val;

	if(exp==0){

	a[exp]=1;

	return 1;

	}

	if(exp==1){
	a[exp]=base%10000007;
	return a[exp]; 

	}

	if(exp%2==0){

	if(exp<1000001 && a[exp]!=0) return a[exp];

	val=power(base,exp/2);

	val=((val%10000007)*(val%10000007)) % 10000007;

	if(exp<1000001)

	a[exp]=val;

	return val;

	}

	else{

	if(exp<1000001 && a[exp]!=0) return a[exp];

	val=power(base,exp/2);

	val=((base%10000007)*(val%10000007)*(val%10000007)) % 10000007;

	if(exp<1000001)

	a[exp]=val;

	return val;

	}

}




int main(){

	long int j,l,m,c,d,v1,v2;	
  long int k,i;
long long int n,q,m1,m2;
memset(a,0,4000008);
	scanf("%lld",&n);

	scanf("%ld",&m);
	scanf("%ld",&k);

	q=power(m,n);

	for(i=0;i<k;i++){

		scanf("%lld",&m1);

		scanf("%ld",&v1);
		scanf("%lld",&m2);
		scanf("%ld",&v2);

		if(m1<=1)c=1;

		else if(m1<1000001 && a[m1-1]!=0)c=a[m1-1];

		else c=power(m,m1-1);

	if(m2>=n)d=1;

		else if((n-m2)<1000001 && a[n-m2]!=0)d=a[n-m2];
		else d=power(m,n-m2);
		q=((q%10000007)+((c%10000007)*(d%10000007))%10000007)%10000007;
	}
	cout<<q;

	return 0;

}


