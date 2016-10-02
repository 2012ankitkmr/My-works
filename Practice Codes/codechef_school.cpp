#include<stdio.h>
#include<stdlib.h>
int main()
{ long long int*ptr;
	long long int a,i,x,j;
	scanf("%lld", &a);
	ptr=(long long int*)calloc(a,sizeof(long long int));
	for(i=0;i<a;i++)
		{
		scanf("%lld", ptr+i);
	}
	x=(*ptr+0)&(*ptr+1);
	for(i=0;i<a;i++)
	{
		for(j=0;j<a-1,j!=i;j++)
		{
			if((*(ptr+i) & *(ptr+j))>x)
				x = *(ptr+i) & *(ptr+j);
		}
	}
	printf("%lld",x);
	return 0;
} 
