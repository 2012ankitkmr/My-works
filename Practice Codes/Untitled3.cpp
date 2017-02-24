#include<bits/stdc++.h>
using namespace std;

int findmax(int arr[],int n)
{
int has[3003];
memset(has,0,sizeof has);
int dup=-1;
for(int i = 0;i<n;i++)
{
if(!has[arr[i]])
has[arr[i]]=1;
else
dup = arr[i];
}

if(dup!=-1)
{
for(int i = dup;i<=3001;i++)
{
	if(!has[i])
	{
	has[i]=1;
	break;
    }  
}
}
int sum = 0;
for(int i =1;i<=3000;i++)
if(has[i])
sum+=i;

return sum;
}

int main()
{
	int n=3;
	int a[]={1,2,2};
	printf("%d\n",findmax(a,n));
	return  0;
}
