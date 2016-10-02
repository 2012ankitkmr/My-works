#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
 
long int next_int()
{
       long int n = 0;
        char c = getchar_unlocked();
        while (!('0' <= c && c <= '9'))
        {
                c = getchar_unlocked();
        }
        while ('0' <= c && c <= '9')
        {
                n = (n<<3)+(n<<1) + c - '0';
                c = getchar_unlocked();
        }
        return n;
}
 
      
int main(){
	int m,p;
	char a[10005],t[10005],ans[10005];
    long int b[105],sum,mod,i,j,s,len,n;
long long int g;
	for(scanf("%d",&m);m--;)
{
 
	scanf("%s",&a);
	n=next_int();
 
	for(i=0;i<n;i++)
	{
		b[i]=next_int();
}
s=1000005;
 strcpy(ans,a);
len=strlen(a);

p=25;
 if(len<12)
{
 
do
{
 
sum=0;
 
	for(i=0;i<n;i++)
	{
	g=(long long int)a;
		/*for(j=0;j<len;j++)
		{
			t[j]=a[j];
			t[j+1]='\0';
			g=t[j]-'0';
 
			mod=(mod*10+g)%b[i];
 
}*/
mod=g%b[i];
	sum=sum+mod;
	}
if(s>sum)
strcpy(ans,a);
if(sum==0)
break;
}
while(next_permutation(a,a+len));
}
 else if(len>11&&len<=1000)
{
 
do
{
 
sum=0;
 
	for(i=0;i<n;i++)
	{
		for(j=0;j<len;j++)
		{
			t[j]=a[j];
			t[j+1]='\0';
			g=t[j]-'0';
 
			mod=(mod*10+g)%b[i];
 
}
	sum=sum+mod;
	}
if(s>sum)
strcpy(ans,a);
if(sum==0)
break;
}
while(next_permutation(a,a+len)&&(p--));
}


printf("%s\n",ans);
 
}
	return 0;
}
