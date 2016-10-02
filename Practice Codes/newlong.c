#include<stdio.h>
#include<math.h>
int main(){
	
	long int t,x,i;
	int flag=0;
	long long unsigned int a,k,j,l;
	double d,e;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d%d",&x,&k);
		d=(long int)x;

l=0;
e=d/2;
while(k>1)
{ 
d=d/2;
e=d;
a=1;
printf("here");
flag=0;
	while(a<=pow(2,l)&&k>1)
	{ 	e=e+2*d;
	 	k--;
		a++;
		flag=1;
	}
	if(e>x)
	{
	e=e-x;
	e=e/2;
}
l++;

	if(flag!=1)
	k--;
}
printf("%.7f\n",e);		
	}
	return 0;
}
