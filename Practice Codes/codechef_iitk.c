#include<stdio.h>
#include<math.h>
int main(){
	
	int t,i;
	scanf("%d",&t);
	long long unsigned int x,m,n,a;
	for(i=0;i<t;i++){
		scanf("%llu%llu%llu",&x,&m,&n);
		printf("%d\n",x);
		a=pow(x,m+1);
		printf("%llu\n%llu\n",a,m);
		a=a-1;
		a=a/(x-1);
		a=a%n;
		printf("%llu\n",a);
		
	}
	return 0;
}
