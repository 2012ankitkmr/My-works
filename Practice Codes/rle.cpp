#include<bits/stdc++.h>
using namespace std;

int main()
{
	char s[100005];
	char p[100005];
	char a;
	stack<int>mystack;
	long int y;
	while(scanf("%s",s)!=EOF)
	{
	long int count=1;
	a=s[0];
	y=0;
	//printf("%s",s);
		for(long int i=1;s[i]!='\0';i++)
		{
			//printf("%c\n",a);
		if(a==s[i])
		{count++;
		
		}
		else
		{
		//printf("%c,%c,%d\n",a,s[i],count);	
			if(count>3)
			{
			while(count)
				{
				int ps=count%10;
				mystack.push(ps);
				count/=10;
				}
				while(!mystack.empty())
				{
				int ps=mystack.top();
				mystack.pop();
				p[y++]=(char)(ps+'0');
				}
				p[y++]='!';
				p[y++]=a;
			}
			else
			{
				while(count--)
				{
					p[y++]=a;
				}
			}
			count=1;
		}	
		a=s[i];	
		}
		if(count>3)
			{
				while(count)
				{
				int ps=count%10;
				mystack.push(ps);
				count/=10;
				}
				while(!mystack.empty())
				{
				int ps=mystack.top();
				mystack.pop();
				p[y++]=(char)(ps+'0');
				}
				p[y++]='!';
				p[y++]=a;
			}
			else
			{
				while(count--)
				{
					p[y++]=a;
				}
			}
		p[y]='\0';
		printf("%s\n",p);
	}
	return 0;
}
