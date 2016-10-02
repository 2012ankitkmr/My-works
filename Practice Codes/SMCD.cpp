#include<stdio.h>
#include<string.h>
int main()
{ 
char s[10006],t[10006];
	int test,i,j;
	for(scanf("%d",&test);test--;)
{
	scanf("%s",s);
memset(t,' ',sizeof t);
j=0;	
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]=='1'||s[i]=='0')
		{
		t[j]=' ';
	}
		if(s[i]=='2')
		{
			t[j]='a';
		
		while(s[i]!='\0'&&s[i+1]=='2')
		{
		t[j]++;
		i++;
		}
	}
			if(s[i]=='3')
		{
				t[j]='d';
			
		while(s[i]!='\0'&&s[i+1]=='3')
		{
		t[j]++;
		i++;
	//	printf("here");
		}
		}
			if(s[i]=='4')
		{
				t[j]='g';
		while(s[i]!='\0'&&s[i+1]=='4')
		{
		t[j]++;
		i++;
		}
		}
			if(s[i]=='5')
		{
				t[j]='j';
		while(s[i]!='\0'&&s[i+1]=='5')
		{
		t[j]++;
		i++;
		}
		}
			if(s[i]=='6')
		{
				t[j]='m';
		while(s[i]!='\0'&&s[i+1]=='6')
		{
		t[j]++;
		i++;
		}
		}
			if(s[i]=='7')
		{
			t[j]='p';
		while(s[i]!='\0'&&s[i+1]=='7')
		{
		t[j]++;
		i++;
		}
		}
			if(s[i]=='8')
		{
				t[j]='t';
		while(s[i]!='\0'&&s[i+1]=='8')
		{
		t[j]++;
		i++;
		}
		}
			if(s[i]=='9')
		{
			t[j]='w';
		while(s[i]!='\0'&&s[i+1]=='9')
		{
		t[j]++;
		i++;
		}
		}
			j++;
	}
	t[j+1]='\0';
	printf("%s\n",t);
	
}
return 0;
}
