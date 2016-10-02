#include<stdio.h>
#include<string.h>

long int max(long int a,long int b)
{return a>b?a:b;
} 
int main()
{
	char string1[250005],string2[250005];
long int count,l;
	long int len1,len2,i,j,temp;
scanf("%s",string1);
scanf("%s",string2);
		len1=strlen(string1);
		len2=strlen(string2);
	 count=0;

	for(i=0;i<len1;i++)
	{
		for(j=0;j<len2;j++)
		{
				temp=0;
		if(string1[i]==string2[j])
			{   l=i;
				while(string1[l]==string2[j])
				{
				temp++;	
				j++;
				l++;
				}
				count=max(count,temp);
			}
			
		}
	}
	printf("%ld",count);
	
	return 0;
}
