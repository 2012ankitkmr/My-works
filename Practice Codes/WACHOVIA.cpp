#include<stdio.h>
long int weight[10005],value[1005];

long int max( long int a,long int b)
{
	return a>b?a:b;
}

int knapsack(int W, int n){
   int i, w;
   int k[n+1][W+1];
   for (i = 0; i <= n; i++){
       for (w = 0; w <= W; w++){
           if (i==0 || w==0)
               k[i][w] = 0;
           else if (weight[i-1] <= w)
                 k[i][w] = max(value[i-1] + k[i-1][w-weight[i-1]],  k[i-1][w]);
           else
                 k[i][w] = k[i-1][w];
       }
   }

   return k[n][W];
}
int main()
{
	long int m,t,i,total;
	for(scanf("%ld",&t);t--;)
	{
		scanf("%ld%ld",&total,&m);
		
		for(i=0;i<m;i++)
		{
			scanf("%ld%ld",&weight[i],&value[i]);
		}
		
		printf("Hey stupid robber, you can get %ld\n",m==1?value[0]:knapsack(total,m));
		}
	
	return 0;
}
