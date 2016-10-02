#include<bits/stdc++.h>
using namespace std;
 char lcs1[102];
void lcs( char X[], char Y[], int m, int n )
{
   int L[102][102];
 
  
   for (int i=0; i<=m; i++)
   {
     for (int j=0; j<=n; j++)
     {
       if (i == 0 || j == 0)
         L[i][j] = 0;
       else if (X[i-1] == Y[j-1])
         L[i][j] = L[i-1][j-1] + 1;
       else
         L[i][j] = max(L[i-1][j], L[i][j-1]);
     }
   }
 
   int index = L[m][n];
 
   lcs1[index] = '\0'; 
   int i = m, j = n;
   while (i > 0 && j > 0)
   {
   
      if (X[i-1] == Y[j-1])
      {
          lcs1[index-1] = X[i-1]; 
          i--; j--; index--;     
      }
      else if (L[i-1][j] > L[i][j-1])
         i--;
      else
         j--;
   }
 
}
 
int hash1[126]; 
int main()
{
	char x[102],y[102];
	int k,i,m,n,len,t;
for(scanf("%d",&t);t--;)
{
	scanf("%s",x);
	scanf("%*c");
	scanf("%s",y);
	m=strlen(x);
	n=strlen(y);
	scanf("%d",&k);
lcs(x,y,m,n);
	len=strlen(lcs1);
	//printf("lcs1=%s\n",lcs1);
	if(len<k)
	{
		printf("0\n");
		continue;
	}
	for(int i=0;lcs1[i]!='\0';i++)
	hash1[i]=(int)(lcs1[i]);
	int sum=0;
	for(int i=0;i<k;i++)
	sum+=hash1[i];
	int ans=sum;
	int start=0;
	for(int i=k;i<len;start++,i++)
	{
	sum-=hash1[start];
	sum+=hash1[i];
	if(ans<sum)
	ans=sum;
}
printf("%d\n",ans);
}

  //char X[] = "AGGTAB";
  //char Y[] = "GXTXAYB";
  //int m = strlen(X);
  //int n = strlen(Y);
  //lcs(X, Y, m, n);
  return 0;
}
