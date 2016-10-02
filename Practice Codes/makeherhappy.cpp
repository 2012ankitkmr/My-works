#include<stdio.h>
#include<string.h>
#define MAX 10000 
 char s[56]; 
 int dp[60][60];
bool div_seven(int i,int j)
{
	int k,power=0;
	long int counter=0;
for(k=j;k>=i;k--)
{

	if(s[k]=='1')
	counter=counter+1<<power;

power++;	
}

if(counter%7==0)
return true;
else
return false;
	

}

int countmin(int i,int j)
{
	if(i==j)
	return 0;
	if(dp[i][j]!=-1)
	return dp[i][j];
	if(div_seven(i,j))
	return 1;
	 
	
	int k,min=MAX,temp,x,y;
	for(k=i;k<j;k++)
	{
		x=countmin(i,k);
		y=countmin(k+1,j);
		if(x>0&&y>0)
		{
		temp=countmin(i,k)+countmin(k+1,j);
	if(temp<min)
	min=temp;

}
	}
	return dp[i][j]=min;
	
}


int main()
{
    int t,len,ans;
   
    for(scanf("%ld",&t);t--;)
    {
    	scanf("%s",s);
    len=strlen(s);
    memset(dp,-1,sizeof dp);
ans=countmin(0,len-1)
if(div_seven(0,len-1))
    printf("1\n");
else if(ans==MAX)
	printf("-1\n");
	else
	printf("%d\n",ans);
    	
    }
    return 0;
}
