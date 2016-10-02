#include<bits/stdc++.h>
using namespace std;
int weight[5000],value[5000];

int n;
int knapsack(int W)
{
   int i, w,j;
   int K[n+1][W+1];

   
   for (i = 0; i <= n; i++)
   {
       for (w = 0; w <= W; w++)
       {
           if (i==0 || w==0)
               K[i][w] = 0;
           else if (weight[i-1] <= w)
                 K[i][w] = max(value[i-1] + K[i-1][w-weight[i-1]],K[i-1][w]);
           else
                 K[i][w] = K[i-1][w];
       }
   }

for( i=0;i<=n;i++)
{
	for( j=0;j<=W;i++)
	{
	printf("%d ",K[i][j]);	
		
	}
	printf("\n");
}

   return K[n][W];
}


int main()
{int t,i,total;
freopen("in.txt","r",stdin);
for(scanf("%d",&t);t--;)
{
	scanf("%d%d",&n,&total);
	for(i=0;i<n;i++)
	scanf("%d%d",&weight[i],&value[i]);
	printf("ans=%d\n",knapsack(total));
}
	return 0;
}
