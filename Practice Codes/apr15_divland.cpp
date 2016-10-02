#include<stdio.h>
long a[1000006],b[1000006],c[1000006];
int main()
{
	long int i,n,m;
	scanf("%ld%ld",&n,&m);
	for(i=0;i<m;i++)
	scanf("%ld%ld%ld",&a[i],&b[i],&c[i]);
	for(i=n/2-1;i>=1;i--)
	printf("%ld ",i+1);
	printf("%ld",1);
	return 0;
}
