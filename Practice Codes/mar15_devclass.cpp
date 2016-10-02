#include<stdio.h>
#include<string.h>
long long int pow(long long int a,long long int b){
	
	if(b==0)
	return 1;
	if(b==1||b==2)
	return a;
	
}

char s[100006],ch[100006];
void swap(long long int a,long long int b)
{
	char temp=s[a];
s[a]=s[b];
s[b]=temp;
	
}
 
void swapc(long long int a,long long int b)
{
	char temp=ch[a];
ch[a]=ch[b];
ch[b]=temp;
	
}
 
int main()
{
	long long int t,i,x,y,v,j;
	long long int ans,sum;
	long long int key,bo,gi;
	long long int b[100006],g[100006];
	for(scanf("%lld",&t);t--;)
	{
	scanf("%lld",&key);
	x=0;
	y=0;
	scanf("%s",s);
	if(key==0)
	{
		for(i=0;s[i]!='\0';)
	{
	if(s[i]=='B')
	b[x++]=i;
	i++;
	if(s[i]!='\0')
    {
    if(s[i]=='G')
	g[y++]=i;
    }
    else break;
	i++;
	}
	//printf("%ld%ld\n",x,y);
	ans=0;
	if(x!=y)
	ans=-1;
	else{
	
	for(i=0;i<x;i++)
	{
	
	v=b[i]-g[i];
	if(v<0)
	v=-v;
	if(key==0)
	v=1;
	if(key==2)
	{
		j=v/2;
		v=4*j+1;
	}
	ans=ans+v;	
    }
    
}
x=0;
y=0;
    	for(i=0;s[i]!='\0';)
	{
	if(s[i]=='G')
	b[x++]=i;
	
	i++;
	if(s[i]!='\0')
    {
    if(s[i]=='B')
	g[y++]=i;
    }
    else break;
	i++;
	}
  //  printf("%ld%ld\n",x,y);
    sum=0;
    if(x!=y)
    sum=-1;    
    
    else
    { 
	for(i=0;i<x;i++)
	{
	
	v=b[i]-g[i];
	if(v<0)
	v=-v;
	if(key==0)
	v=1;
	if(key==2)
	{
		j=v/2;
		v=4*j+1;
	}
	sum=sum+v;	
    }
}
if(ans<0)
ans=sum;
else{
 
    if(sum>=0&&sum<ans)
            ans=sum;
}
//	printf("%s\n",s);
printf("%lld\n",ans);		

	}
		
	else
	{
	strcpy(ch,s);

	for(i=0;s[i]!='\0';i++)
	{
	if(s[i]=='B')
	b[x++]=i;
	else
	g[y++]=i;
	}
	bo=x;
	gi=y;
	ans=0;
	if(bo==(gi+1))
	{x=0;
		y=0;
	for(i=0;i<gi+bo;i+=2)
	{
		//	printf("ans=%lld\n",ans);
		if(s[i]=='G')
		{
		ans=ans+pow(b[x++]-i,key);	
		swap(b[x-1],i);
	}
		else
		x++;
			
		if(s[i+1]!='\0'&&s[i+1]=='B')
		{
			ans=ans+pow(g[y++]-(i+1),key);
		swap(g[y-1],i+1);
		}
		else
		y++;
    }
	}
	
	if(gi==(bo+1))
	{   x=0;
		y=0;
		
	for(i=0;i<gi+bo;i+=2)
	{
		//printf("ans=%lld\n",ans);
		if(s[i]=='B')
		{
		ans=ans+pow(g[y++]-i,key);	
		swap(g[y-1],i);
		}
		else
		y++;	
		if(s[i+1]!='\0'&&s[i+1]=='G')
		{
			ans=ans+pow(b[x++]-(i+1),key);
		swap(b[x-1],i+1);
		}
		else
		x++;
		
    }
    
	}
	if(bo>=gi+2)
	ans=-1;
	if(gi>=bo+2)
	ans=-1;
	
	if(gi==bo)
	{   x=0;
		y=0;
	for(i=0;i<bo+gi;i+=2)
	{
		if(s[i]=='B')
		{
		ans=ans+pow(g[y++]-i,key);	
		swap(g[y-1],i);
		}
		else
		y++;	
		if(s[i+1]!='\0'&&s[i+1]=='G')
		{
			ans=ans+pow(b[x++]-(i+1),key);
		swap(b[x-1],i+1);
		}
		else
		x++;
    }
    x=0;
		y=0;
		sum=0;
	for(i=0;i<bo+gi;i+=2)
	{
		if(ch[i]=='G')
		{
		sum=sum+pow(b[x++]-i,key);	
		swapc(b[x-1],i);
		}
		else
		x++;	
		if(ch[i+1]!='\0'&&ch[i+1]=='B')
		{
			sum=sum+pow(g[y++]-(i+1),key);
		    swapc(g[y-1],i+1);
		}
		else
		y++;
    }
    if(sum<ans)
    ans=sum;
	}
//	printf("%s\n",s);
printf("%lld\n",ans);		
}
	}
	return 0;
} 
