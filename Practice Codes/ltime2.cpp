#include<stdio.h>

char ch[100006];
int main() {
	
	int t,a,b,c,r;
	long int i;
	long long int count;
	for(scanf("%d",&t);t--;)
	{
		scanf("%s",ch);
		r=0;
		while(ch[r]!='r')
		++r;
		a=0;
		if(r==0)
			count=0;
		else
		count+=(r-1);
		for(i=0;ch[i]!='\0';i++)
		{
		 	if(ch[i]=='r')
		 	{
		 		if(i>a)
		 		{
		 		  ++a;
		 		  count=count+i-a;
		 		}
		 	}
 
		}
		c=a;
		for(i=0;ch[i]!='\0';i++)
		{
		 	if(ch[i]=='g')
		 	{
		 		if(i>a)
		 		{
		 		  ++c;
		 		  count=count+i-c;
		 		}
		 		else if(i<a)
		 		{
		 			++c;
		 			count=count+c-i;
		 		}
		 	}
 
		}
		b=c;
		for(i=0;ch[i]!='\0';i++)
		{
		 	if(ch[i]=='b')
		 	{
		 		if(i>b)
		 		{
		 		  ++b;
		 		  count=count+i-b;
		 		}
		 		else if(i<a)
		 		{
		 			++b;
		 		count=count+b-i;
		 		}
		 	}
 
		}
 
		printf("%d\n",count);
	}
	return 0;
}
