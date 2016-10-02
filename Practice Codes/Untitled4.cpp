#include<stdio.h>
#define MAX 10004
long int a[10004],b[10004];
long int rootx,rooty;
void make_set()
{
	long int i;
	for(i=1;i<=MAX;i++)
	b[i]=i;
}

long int froot(long int r)
{
	return b[r];
	
}
void qunion(long int x,long int y)
{
b[y]=x;
}


int main()
{
	long int i,t,n,q,x,p,y;
	
for(scanf("%ld",&t);t--;)
{
scanf("%ld",&n);
for(i=1;i<=n;i++)
{
	scanf("%ld",&a[i]);	
}

scanf("%ld",&q);
make_set();
while(q--)
{
scanf("%ld",&p);

if(p==1)
{
	scanf("%ld",&x);
	
printf("%ld\n",froot(x));	
}
else
{
	scanf("%ld%ld",&x,&y);
	
	printf("frootx(%ld)=%ld,frooty(%ld)=%ld\n",x,froot(x),y,froot(y));
	if(froot(x)==froot(y))
	{
		printf("Invalid query\n");
	}
	
	else
	{
		if(a[froot(x)]>a[froot(y)])
		{
			qunion(froot(x),froot(y));
		}
		else
		{
		qunion(froot(y),froot(x));	
		}
	
}
}
	
	
}
	
}	
	return 0;
}
