#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int t,a[26],i,len,flag;
	char s[56];
	for(scanf("%d",&t);t--;)
{
	
	 memset(a,0,sizeof(a));
	scanf("%s",s);
	len=strlen(s);
	for(i=0;i<len;i++)
	{
		a[s[i]-'a']++;
	}
	flag=0;
    for(i=0;i<26;i++)
    {
       if(a[i]==len-a[i])
       {flag=1;
       break;}
 
    }
    if(flag==1)
    printf("YES\n");
    else
    printf("NO\n");


}	
	return 0;
}
