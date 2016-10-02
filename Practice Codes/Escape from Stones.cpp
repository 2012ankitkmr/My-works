#include<bits/stdc++.h>
using namespace std;


char s[1000006];
int ans[1000006];
int main()
{
scanf(" %s",s);
int len = strlen(s);

int left = 0,right = len+1;

for(int i = 0; s[i] ; i++ )
{
	
	if(s[i] == 'l')
	{
	right--;
	ans[right] = i + 1 ;	
	}
	else
	if (s[i] == 'r')
	{
		left++;
		ans[left] = i + 1;
	}
	
}
for(int i = 1 ; i <= len; i++)
{
printf("%d\n",ans[i]);
}
 
	return 0;
}
