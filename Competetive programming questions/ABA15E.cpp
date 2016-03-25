#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

ll transition_matrix[6][6] = { {4,0,1,0,1} , {1,0,0,0,0} , {0,0,3,2,0} , {0,0,1,0,0} , {0,0,0,0,1} }; // follow tutorial by zobayer Matrix multiplication 
ll matp[6][6], res[6][6];//matp is power the basic matrix to be multiply p times
ll tempmat[6][6]; // auxiliary matrix to store the matrix while multiplication

ll base matrix[] = {1 , 1 , 1 , 1 , 2 };
int main()
{
	int test,n;
	ll tempsum;
	for( scanf("%d",&test) ; test-- ; )
	{
	scanf("%d", &n );
	
	for(int i = 0; i < 5; i++ )
	{
		for(int j = 0; j < 5 ; j++)
		matp[i][j] = transition_matrix[i][j];
	}
	
	for(int i = 0 ; i < 5 ; i++)
	{
		for(int j = 0 ;j < 5; j++)
		if(i == j)
		res[i][j]=1;
		else
		res[i][j]=0;
	}
	
	while( n > 0 )
	{
		if( n & 1 ) 
		{
			
	     for(int i = 0 ; i < 5 ; i++)
         {
	        for(int j = 0 ; j < 5 ; j++)
        	 {
		      tempsum = 0;
		       
			   for(int k = 0 ; k < 5 ; k++)
	          tempsum = ( tempsum + ( res[i][k] * matp[k][j] ) %MOD ) %MOD;
		      tempmat[i][j] = tempsum;
          	 }
         }
        
		 for(int i = 0 ; i < 5 ; i++)
	     {
		    for(int j = 0 ;j < 5 ; j++)
	     	 res[i][j] = tempmat[i][j];
         }	
		}
		
		 for(int i = 0 ; i < 5 ; i++)
         {
	          for(int j = 0 ; j < 5 ;j++)
        	   {
		        tempsum = 0;
		        for(int k = 0 ; k < 5 ; k++ )
	            tempsum = ( tempsum + ( matp[i][k] * matp[k][j] ) %MOD ) %MOD;
		        tempmat[i][j] = tempsum;
          	   }
         }
         for(int i = 0 ; i < 5 ; i++)
	      {
		       for(int j = 0 ; j < 5; j++)
	     	   matp[i][j] = tempmat[i][j];
        	}	
        	n>>=1;
        	
	}
	
	printf("%lld\n", ( res[0][0] + res[0][1] + res[0][2] + res[0][3] + ( 2*res[0][4] ) %MOD ) %MOD );
	
}
	return 0;
}
