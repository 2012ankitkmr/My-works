#include<bits/stdc++.h>
int main()
{
long int i,t,n,max,temp1,sum,temp2,alloc;
for(scanf("%ld",&t);t--;)
{

scanf("%ld",&n);
scanf("%ld",&temp1);
sum=temp1;

max=-1;
for(i=1;i<n;i++)
{
scanf("%ld",&temp2);
if(temp2>=temp1)
sum+=(temp2-temp1);

temp1=temp2;

}
printf("%ld\n",sum);
}
 
return 0;
} 
