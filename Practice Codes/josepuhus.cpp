#include<bits/stdc++.h>
using namespace std;
namespace ank{
long int josephus(long int n,long int k)//recursive version
{
if(n==1)
return 1;
else 	
return (josephus(n-1,k)+k-1)%n+1;
}

}
int main()
{
long int n=10;
long int k=2;
long int i,ans=0;
for(i=2;i<=n;i++)//iterative version
{
ans=(ans+k)%i;
}
++ans;

int c=1;
while(c<=n)
c<<=1;
ans=((n-(c>>1))<<1)+1;
printf("%ld\n",ans);//direct formula for k=2
	printf("The chosen place is %d",ans);
	
	return 0;
}
