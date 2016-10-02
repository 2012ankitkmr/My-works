#include<bits/stdc++.h>
using namespace std;
#define MAXN 40

int mat[MAXN][MAXN],matp[MAXN][MAXN],tempmat[MAXN][MAXN],res[MAXN][MAXN];

int main()
{
	freopen("in.txt","r",stdin);
	int d,n;// d is the dimension of matrix
	printf("Enter the order of matrix : ");
	scanf("%d",&d);
	printf("Enter the matrix :\n");
	for(int i=0;i<d;i++)
	{
		for(int j=0;j<d;j++)
		scanf("%d",&mat[i][j]);
	}
	printf("The matrix entered is : \n");
	
	for(int i=0;i<d;i++)
	{
		for(int j=0;j<d;j++)
		printf("%d ",mat[i][j]);
		printf("\n");
	}
	
	printf("Enter the power of matrix : ");
	scanf("%d",&n);// n is power of the matrix to be found
	for(int i=0;i<d;i++)
	{
		for(int j=0;j<d;j++)
		matp[i][j]=mat[i][j];
	}
	
	for(int i=0;i<d;i++)
	{
		for(int j=0;j<d;j++)
		if(i==j)
		res[i][j]=1;
		else
		res[i][j]=0;
	}
	

	int pow=n;
	int tempsum;
	while(n>0)
	{
		if(n&1)
		{
			//multiply matp by mat and store it in matp 
	     for(int i=0;i<d;i++)
         {
	        for(int j=0;j<d;j++)
        	 {
		      tempsum=0;
		      for(int k=0;k<d;k++)
	          tempsum+=(res[i][k]*matp[k][j]);
		      tempmat[i][j]=tempsum;
          	 }
         }
        
		 for(int i=0;i<d;i++)
	     {
		    for(int j=0;j<d;j++)
	     	 res[i][j]=tempmat[i][j];
         }	

		n--;// decrement n by 1
		cout<<"here1\n";
		}
		
			//multiply matp by matp and store it in matp
		 for(int i=0;i<d;i++)
         {
	          for(int j=0;j<d;j++)
        	   {
		        tempsum=0;
		        for(int k=0;k<d;k++)
	            tempsum+=(matp[i][k]*matp[k][j]);
		        tempmat[i][j]=tempsum;
          	   }
         }
         for(int i=0;i<d;i++)
	      {
		       for(int j=0;j<d;j++)
	     	   matp[i][j]=tempmat[i][j];
        	}
			
		n>>=1;//divide n by 2
		cout<<"here2\n";
		
	}
		printf("The %dth power of matrix 1 is : \n",pow);
		
		for(int i=0;i<d;i++)
	{
		for(int j=0;j<d;j++)
		printf("%7d ",res[i][j]);
		printf("\n");
	}
		
	
	return 0;
}
