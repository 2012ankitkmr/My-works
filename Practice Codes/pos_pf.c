#include<stdio.h>
#include<string.h>

void pof_pf();
void pushc(char);
char popc();

struct A
{
	char s[20];
	int top;
};

typedef struct A stack1;
stack1 s1;

int main()
{
	pof_pf();
	return 0;
}

void pof_pf()
{
char postfix[20],prefix[20],ch[2],temp1[2],temp2[2];	
int i,len;	
	printf("Enter the postfix expression: ");
	scanf("%s",postfix);
	len=strlen(postfix);
	for(i=0;i<len;i++)
	{
	
		ch[0]=postfix[i];
		ch[1]='\0';
		switch(ch[0])
		{
			case '+':
			case '-':
			case '*':
			case '/':
			case '$':
				      temp1[0]=popc();
				      temp2[0]=popc();
				      temp1[1]='\0';
				      temp2[1]='\0';
				    strcpy(prefix,ch);
				    printf("%s",prefix);
					strcpy(prefix,temp2);
					strcpy(prefix,temp1);  
				    break;
			default:
			      pushc(ch[0]);
			      break;
		}
	}
	printf("The prefix expression is : %s",prefix);
	
}

char popc()
{
	if(s1.top>0)
	return s1.s[s1.top--];
	else 
	return -1;
}
void pushp(char temp)
{
	s1.s[++s1.top]=temp;
}
