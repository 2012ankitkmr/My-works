#include<bits/stdc++.h>
using namespace std;

char s[1003];
char alpha[27];
int main()
{
	int n , p , flag , j , setvalue = 0 ;
	
	for(int i = 0 ; i < 26 ; i++ )
	alpha[i] = 'a' + i;
	
	scanf("%d%d",&n,&p);
	scanf("%s",s);
	int index = -1;
	for(int i = n - 1 ; i >= 0 ; i-- )
	{
		if( (int)s[i] - (int)'a' + 1 >= p )
		continue;
		else
		{
			j = 1;
			while(s[i] - 'a' + j < p)
			{
			
			flag = 0;
			if(i-1>=0)
			if((s[i] + j == s [i - 1]))
			flag = 1;
			if(i-2>=0)
			if((s[i] + j == s [i - 2]))
			flag = 1;
			
			
			if(!flag)
			{
				index = i;
				setvalue = j;
				break;
				
			}
			j++;
		   }
		}
		if(index!=-1)
		break;
	}
	
	if(index == -1)
	printf("NO\n");
	else
	{
     	
     	s[index] += setvalue;
     
     	j = 0;
     	
     		index++;
		 while(index<n)
		 {
		 	
		 	
		if((index-2>=0)&&(s[index-2]==alpha[j]))
		{
			
		
    	}
     	else if(s[index-1] == alpha[j])
		{
			
		}
	    else 
		{
		s[index] = alpha[j];
		index++;
		j = -1;
	}
		
		 if(j<p-1)
		 j++;
		 else
		 j=0;
		 
	
		 }
	printf("%s\n",s);	
	}

	
	
	return 0;
}
