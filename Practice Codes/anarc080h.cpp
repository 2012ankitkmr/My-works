#include<bits/stdc++.h>
using namespace std;

int main()
{
long int n,k,ans,i;
while(1)
{
scanf("%ld%ld",&n,&k);
if(n==0&&n==k)
break;
ans=0;
for(i=2;i<=n;i++)//iterative version
{
ans=(ans+k)%i;
}
++ans;
printf("%ld %ld %ld\n",n,k,ans);//direct formula for k=2

}//	printf("The chosen place is %d",ans);
	
	return 0;
}
