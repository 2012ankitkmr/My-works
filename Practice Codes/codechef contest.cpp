#include<stdio.h>
#include<string.h>
int main()
{
	int t,i,len,len1,sum;
	char s[2002],c[2002];
	int b[2009],cb[2009];
	for(scanf("%d",&t);t--;)
	{
		scanf("%s",s);
		scanf("%s",c);
		memset(b,0,2009);
		memset(cb,0,2009);
		for(i=0;s[i]!='\0';i++)
		{
			b[s[i]-'A']++;
		
		}
		for(i=0;c[i]!='\0';i++)
		{
			cb[c[i]-'A']++;
		
		}
		sum=0;
		len=strlen(s);
		len1=strlen(c);
		if((len-len1)>0)
		sum+=(len-len1);
		if((len1-len)>0)
		sum+=(len1-len);
	
		for(i=0;i<26;i++)
		{
			if((cb[i]-b[i])>0)
			sum+=(cb[i]-b[i]);
			
		}
		
		printf("%d\n",sum);
		
	}
	
	return 0;
}
