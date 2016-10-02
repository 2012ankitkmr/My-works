#include<stdio.h>

int main()
{
	long int t,n,temp,i,counter,flag,min;
	for(scanf("%ld",&t);t--;){
	scanf("%ld",&n);
	flag=0;
	counter=0;
	min=100001;	
	for(i=0;i<n;i++)
	{
		
		scanf("%ld",&temp);
		
		if(min>temp)
		min=temp;
		
		if(temp<2)
		flag=1;
	counter+=temp;
	}	
	if(!flag)
	printf("%ld\n",counter-min+2);
	else
	printf("-1\n");	
	}
	
	return 0;
}
