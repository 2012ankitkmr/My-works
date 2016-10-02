#include<bits/stdc++.h>
using namespace std;
long int weight[505],value[505];
 long long int K[2][2000001]={0};
 int n;
int main()
{
long long int i,total;
//for(scanf("%d",&t);t--;)

	scanf("%i%i",&total,&n);
	for(i=0;i<n;i++)
	scanf("%i%i",&value[i],&weight[i]);
    long int  w,W=total;
  

   
   for (i = 0; i <= n; ++i)
   {
   	w=0;
   	if(i%2)
   	{
   	
       while (++w<=W)
       {
        
            if (weight[i] <= w)
                 K[1][w] = max(value[i] + K[0][w-weight[i]],K[0][w]);
           else
                 K[1][w] = K[0][w];
       }
   }
   else
   	{
   	
       while(++w<=W)
       {
       
           if (weight[i] <= w)
                 K[0][w] = max(value[i] + K[1][w-weight[i]],K[1][w]);
           else
                 K[0][w] = K[1][w];
       }
   }
   
}
if(i&1)
	printf("%i\n",K[1][W]);
	else
	printf("%i\n",K[0][W]);
	return 0;
	
}
