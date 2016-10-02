#include<bits/stdc++.h>
#include<climits>
using namespace std;
int a[5000];

int rodcutting(int n)
{
	if(n<=0)
	return 0;
	int i,max_val=INT_MIN;
	//printf("INT_MIN=%d\n",INT_MIN);
	for(i=0;i<n;i++)
	max_val=max(max_val,a[i]+rodcutting(n-i-1));
	return max_val;	
}

 int main()
 {
 	int n,i;
 	scanf("%d",&n);
 	for(i=0;i<n;i++)
 	scanf("%d",&a[i]);
 	printf("max=%d\n",rodcutting(n));
 	return 0;
 }
