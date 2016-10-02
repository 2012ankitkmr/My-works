#include<stdio.h>
int min(int a,int b)
{
	return a>b?b:a;
}
 
int main() {
	int c,t,n,a,b,p,k;
	char s[100006];
	for(scanf("%d",&t);t--;){
	
		scanf("%d%d",&n,&k);
		scanf(" %s",s);
		if(k==1)
		{
	a=0;
	b=0;
			for(int i=0;i<n;i++)
			{  
				if(i%2==0)
				{
					if(s[i]=='0')
					a++;
					else
						b++;
				}
				else
				{
					if(s[i]=='1')
						a++;
					else
					b++;
			}
			}
			printf("%d\n",min(a,b));
			  for(int i=0;i<n;i++)
		    {
		    	if(b>a)
		    	{
		    		if(i%2==1)
		    		{
		    			printf("0");
		    		}
		    		else{
		    			printf("1");
		    		}
 
		    	}
		    	else{
		    			if(i%2==1)
		    		{
		    			printf("1");
		    		}
		    		else{
		    			printf("0");
		    		}
 
 
		    	}
		    }
		    printf("\n");
		}
		else{
		 c=1;
			p=0;
				for(int i=1;i<n;i++)
			{  
				if(s[i]==s[i-1]&&s[i]!=0)
				{
					c++;
				}
				else{
					c=1;
					
				}
			   if(c>k){
 
			   	p++;
			   	if(i!=n-1&&s[i]!=s[i+1])
			   	{ 
			   		if(s[i]=='1')
			   		{
			   			s[i-1]='0';
			   		}
			   		else{
			   			s[i-1]='1';
			   		}
			   	}
			   	else if(i!=n-1&&s[i]==s[i+1])
			   	{
 
			   		if(s[i]=='1')
			   		s[i]='0';
			   		else
			   		s[i]='1';
 
			   	}
			   	else{
			   	 if(s[i]=='1')
			   		s[i]='0';
			   	else
			   		s[i]='1';
			
			   	}
			  }  
			}
			printf("%d\n",p);
			printf("%s\n",s); 
		}
	}
	return 0;
}
