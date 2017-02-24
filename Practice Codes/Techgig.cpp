#include<bits/stdc++.h>
using namespace std;

int f,k,n;
 int dp[1003][1003];
int a[1003];
 int min(int c,int b)
{
    return c>b?b:c;
}

int compute(int pos,int buckets, int sum)
{
//	printf("%d %d\n",pos,buckets);
	
 if(buckets==k)
 {
     if(sum%f==0)
     return sum;
     else
     return INT_MAX;
 }
 
 if(dp[pos][buckets]!=-1)
 return dp[pos][buckets];
 
 int ans = INT_MAX;
 int i;
 for(i = pos+1;i<=n;i++)
 {
     ans = min(ans,compute(i,buckets+1,sum+a[i]));
 }
    return dp[pos][buckets]=ans;
}


int ball_count(int input1[],int input2,int input3)
{
	
	memset(dp,-1,sizeof dp);
	k = input3;
	f = input2;
	int i ;
	for(i = 0;i<10003;i++)
	{
	if(input1[i]==0)
	break;
		a[i+1] = input1[i];
		n++;
		
	}
	//printf("si = %d\n",sizeof input1);
//	return 
	//	printf("%d %d %d\n",n,f,k);

	//Write code here
	if(k==0||f==0||n==0||k>n)
	return -1;
	int res = compute(0,0,0);
	if(res==INT_MAX)
	return -1;
	else
	return res;
	
}


int main()
{
	int s[] = {4,8,4,484,8,4,8,48,48,4844,5};
	cout<<ball_count(s,0,4);
	
	
	return  0;
}
