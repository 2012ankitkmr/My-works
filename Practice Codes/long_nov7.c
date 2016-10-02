#include<stdio.h>
#include<math.h>
int main()
{
	long int q,p,i,g,h,j,w,l,ri,r,b,s=1;
	char qu[3];
	long long int y;
	scanf("%d",&q);
	for(i=0;i<q;i++)
	{
w=1;
for(j=0;j<w;j++)
	{
	scanf("%s",qu);
	if(qu[1]=='i')
	{
	w++;
	s++;
	}
	else
	scanf("%d%d",&l,&ri);
}
		
r=0;
b=0;
j=1;
p=0;
g=l;
h=ri;
while(1){
h=h/2;
g=g/2;
if(g==1)
{p=j;
}
if(h==1)
break;
	
j++;
}
 
if(j%2==0)
b++;
else
r++;
 
if(p%2==0)
b++;
else
r++;
 y=1;
 for(g=0;g<p;g++)
 y=y*2;
 
while(1)
{
if(ri>=2*y)
{
ri=ri/2;
if(ri!=l)
{
if(j%2==0)
r++;
else
b++;
}
}
	else
	{
		ri=ri/2;
		l=l/2;	
		if(j%2==0)
		r++;
		else
		b++;
		
		if(ri!=l)
		{
		if(p%2==0)
		r++;
		else 
		b++;
	}
	p--;
	}
j--;
 
if(l==ri)
break;	
}
 
if(s%2==0)
{
p=b;
b=r;
r=p;
}
if(qu[1]=='r')
printf("%d\n",r);
else if(qu[1]=='b')
printf("%d\n",b);	
	}
	return 0;
}
