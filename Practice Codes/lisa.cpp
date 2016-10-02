#include<stdio.h>
#include<string.h>
char s[101];
int number[101];
char operators[101];
long int dp[101][101];


long int findmax(long int i,long int j)
{
	if(dp[i][j]!=-1)
	return dp[i][j];
	
	if(i==j)
	return 0;
	long int temp,k,max; 
	max=dp[i][j];
	for(k=i;k<j;k++)
	{
		if(operators[k]=='+')
		temp=findmax(i,k)+findmax(k+1,j);
		else 
		temp=findmax(i,k)*findmax(k+1,j);
		
		if(max==-1||temp>max)
		max=temp;
	}
	
	return dp[i][j]=max;
}

int main()
{
	
	long int t,x,y,len,i;
	for(scanf("%ld",&t);t--;)
	{
	scanf("%s",s);	
	x=0;
	y=0;
	len=0;
	for(i=0;s[i]!='\0';i++)
	{
		len++;
		if(i%2==0)
        number[x++]=s[i]-'0';
		else
		operators[y++]=s[i];		
	}	
	
	memset(dp,-1,sizeof dp);
	printf("%ld",findmax(0,len-1));	
		
	}
	return 0;
}

