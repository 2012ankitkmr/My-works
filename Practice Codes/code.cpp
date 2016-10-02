#include<stdio.h>
#include <string.h>
int main()
{
int t,flag;
long int i,len,len1;
char s[50005],c[50005];
int b[50005],cb[50005];
for(scanf("%d",&t);t--;)
{
	memset(s,0,50005);
	memset(c,0,50005);
	
scanf("%s",s);
scanf("%s",c);
for(i=0;s[i]!='\0';i++)
{b[s[i]-'a']++;
//printf("b[i]=%d\n",b[s[i]-'a']);
}
 
for(i=0;c[i]!='\0';i++)
{cb[c[i]-'a']++;
//printf("cb[i]=%d\n",cb[c[i]-'a']);
}
flag=0;
for(i=0;i<26;i++)
{
if(cb[i]!=b[i])
{flag=1;
break;
}
}
len=strlen(s);
len1=strlen(c);
 printf("len=%d,len1=%d\n",len,len1);
 if(len!=len1)
 flag=1;
 
if(flag==1)
printf("NO\n");
else
printf("YES\n");
 
}
return 0;
}

