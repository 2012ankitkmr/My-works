#include<stdio.h>
	char s[1000005];
	
void find_palin(char s[])	
{
	int i,flag,temp;
	flag=0;
	int len=0;
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]!='9')
		flag=1;
		len++;
	}
   if(flag==0)
   {  s[0]='1';
	for(i=1;i<len;i++)
	{
		s[i]='0';
	}
	s[len]='1';
	s[len+1]='\0';
	return; 
   }  
   flag=0;
 
	for(i=0;i<len/2;i++)
	{
		if(s[i]>s[len-i-1])
		flag=1;
		else if(s[i]<s[len-i-1])
		flag=-1;
		 s[len-i-1]=s[i];
	}

if(flag==-1||flag==0)	
{
   if(len%2==0)
  temp=len/2-1;
  else
  temp=len/2;	
while(s[temp]=='9')
{
	s[temp]='0';
	s[len-temp-1]='0';
	temp--;
}
s[temp]++;
s[len-temp-1]=s[temp];	
}
}
int main()
{

	int t;
	long int i,a,b;
	for(scanf("%d",&t);t--;)
    {
	scanf("%s",s);
     find_palin(s);
     printf("%s\n",s);

    }	
	return 0;
}
