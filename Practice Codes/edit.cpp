#include<stdio.h>
#include<string.h>
#define MAXN 1003
char string1[MAXN],string2[MAXN];
int dp[MAXN][MAXN],len;
char capital(char a)
{
	if(a>=65&&a<=91)
	return a=a+32;
	else
	return a;
}
char small(char a)
{
	if(a>=97&&a<=123)
	return a=a-32;
	else
	return a;
}

int generate_sequence(bool b)
{
	int i;
	if(b)
	{
	for(i=0;string1[i]!='\0';i++)
	{
		if(i%2)
		string2[i]=capital(string1[i]);
	    else
	    string2[i]=small(string1[i]);
	}
	}
     else
     {
	for(i=0;string1[i]!='\0';i++)
	{
		if(i%2)
		string2[i]=small(string1[i]);
	    else
	    string2[i]=capital(string1[i]);
	}

    }
    return 1;
}
int min(int a,int b)
{return a<b?a:b;
}
int edit_distance(int len,int a)
{
	int i,j,m;
	for(i=0;i<=len;i++)
	dp[i][0]=i;
     for(i=0;i<=len;i++)
     dp[0][i]=i;

for(i=1;i<=len;i++)
{
	for(j=1;j<=len;j++)
	{
	m=min(dp[i-1][j],dp[i][j-1])+1;	
	dp[i][j]=min(m,dp[i-1][j-1]+(string1[i-1]==string2[j-1]?0:1));	
	}
}
//printf("here\n");
return dp[len][len];
}
int main()
{
	while(scanf("%s",string1)!=EOF)
	{
		len=strlen(string1);
	   printf("%d\n",min(edit_distance(len,generate_sequence(1)),edit_distance(len,generate_sequence(0))));		
	}
	return 0;
}
