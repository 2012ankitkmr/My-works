#include<bits/stdc++.h>
using namespace std;
int arr[1005];
char s[1005][1005];
int m,n,x,y;

int compute ( int bar, int streak , int type )
{
	
	if(bar == m)
	return 0;
	
	
	int a = INT_MAX , b = INT_MAX;
	if(streak <= x)
	 {
	 	
	 	if(type)
     	 a = n - arr[bar] + compute( bar + 1 , streak + 1 , type );
     	 else
     	 b = arr[bar] + compute( bar + 1 , streak + 1 , type );	
     	 
     }
	 else if(streak >= y )
    {
    	
	  if(type)
	  b = arr[bar] + compute( bar + 1 , 1 , 1 - type );
	  else
	  a = n - arr[bar] + compute( bar + 1 , 1 ,1 - type );
	  
    }
	 else
	 {  
	 
	    if(type)
	   	{
	 	 a = n - arr[bar] + compute( bar + 1 , streak + 1 , type);
	 	 b = arr[bar] + compute( bar + 1 , 1 , 1 - type );
	     }
	     else
	     {
	     a = n - arr[bar] + compute( bar + 1 , 1 , 1 - type );
	 	 b = arr[bar] + compute ( bar + 1 , streak + 1 , type );
	     }
	 }

	return min(a,b);
	
}


int main()
{
//	freopen("in.txt","r",stdin);
	
	scanf("%d%d%d%d", &n , &m , &x , &y );
	
	
	for(int i = 0 ; i < n; i++ )
	scanf(" %s",s[i]);
	
	for(int i = 0 ; i < n ; i++ )
	{
		for( int j = 0 ; j < m; j++ )
		if( s[i][j] == '#')
		 arr[j]++;	
	}
	
	int a = compute(0,0,0) , b = compute(0,0,1) ;
	int ans = min(a,b);

	//printf("%d  %d\n",a,b);
	//for(int i = 0;i < m; i++ )
    //printf("%d ",arr[i]);
    //printf("\n");

	printf("%d\n",ans);
	return  0;
}
