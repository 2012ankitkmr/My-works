#include<stdio.h>
#include<math.h>
int main()
{
	long long int q,p,g,h,i,j,w,l,ri,r,b,y,s=1;
	char qu[3];
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
j=0;
y=0;
r=0;
b=0;
while(1){
if(ri>=pow(2,y)&&ri<=pow(2,y+1)-1)
break;

else
y++;
/*{
	if(l>=pow(2,y)&&l<=pow(2,y+1)-1)
{p=j;
printf("here also\n");
}

}*/
printf("here\n");
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

printf("r=%d,b=%d,p=%d,j=%d",r,b,p,j);
y=p;
while(1)
{
if(ri>=2*pow(2,y))
{
ri=ri/2;
if(ri!=l)//
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
y--;
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
