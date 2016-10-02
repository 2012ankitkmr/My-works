#include<stdio.h>
#include<string.h>

char popc();
void pushc(char);

struct A
{
	char s[20];
	int top;
};
typedef struct A stack;
stack s1;
void pf_pof();

int main()
{
	pf_pof();
	return 0;
}

void pf_pof()
{
	char prefix[20],postfix[20],temp1[2],temp2[2],op,ch[2];
	int i,len;
	printf("Enter the expression : ");
	scanf("%s",prefix);
	len=strlen(prefix);
	postfix[0]='\0';
	for(i=len-1;i>=0;i--)
	{
		ch[0]=prefix[i];
		ch[1]='\0';
		switch(ch[0])
		{
			case '+':
			case '-':
			case '*':
			case '/':
			case '$':	
			          temp1[0]=popc();//k
			          temp2[0]=popc();//j
			          temp1[1]='\0';
			          temp2[1]='\0';
			        strcat(postfix,temp1);
					strcat(postfix,temp2);
					strcat(postfix,ch);
					break;  
			default: pushc(ch[0]);
			break;
		}
			
	}
	
	printf("The postfix expression is : %s",postfix);
}

void pushc(char temp)
{
	s1.s[++s1.top]=temp;
}

char popc()
{
	return s1.s[s1.top--];
}
