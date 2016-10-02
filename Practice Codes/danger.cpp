#include<bits/stdc++.h>
using namespace std;

int main()
{
long int n,i,c;
char s[10];
long int ans;

while(1)
{
scanf("%s",s);
if(s[0]==0&&s[1]==0)
break;
n=(int)(s[0]-'0')*10+(int)(s[1]-'0');
for(i=0;i<(int)(s[3]-'0');i++)
n=n*10;
c=1;
//printf("%ld\n",n);
while(c<=n)
c<<=1;
ans=((n-(c>>1))<<1)+1;
printf("%ld\n",ans);
}
	return 0;
}
