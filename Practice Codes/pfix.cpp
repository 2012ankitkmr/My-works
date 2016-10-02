#include<stdio.h>
#include<string.h>

struct A
{
	char s[20];
	int top;
};

typedef struct A stack;
stack s1;

void pushc(char);
char popc();
void pfix();

void strrev(char *s[])
{
	int i;
	char temp[20];
	for(i=0;i<s1.top;i++)
	temp[i]=*s[i];
	
	for(i=0;i<s1.top;i++)
	*s[s1.top-i-1]=temp[i];
	
	return;
	}

int main()
{
	pfix();
	return 0;
} 

void pfix()
{
	char infix[20],ch[2],a,prefix[20];
	int i,len;
	printf("Enter the prefix expression : ");
	scanf("%s",prefix);
	len=strlen(prefix);
	infix[0]='\0';
	for(i=len-1;i>=0;i--)
	{
		ch[0]=prefix[i];
		ch[1]='\0';
		switch(ch[0])
		{
			case '{':a=popc();
		              while(a!='}')
					  {
					  	  ch[0]=a;
						  strcat(infix,ch);
					    a=popc();
					  }
					  break;
			case '[':a=popc();
		              while(a!=']')
					  {
					  	  ch[0]=a;
						  strcat(infix,ch);
					    a=popc();
					  }
					  break;
			case '(':
				         a=popc();
		              while(a!=')')
					  {
					  	  ch[0]=a;
						  strcat(infix,ch);
					    a=popc();
					  }
					  break;		
			case ']':
			case '}':
			case ')':
			case '+':
			case '-':
			case '*':
			case '/':
			case '$': pushc(ch[0]);
			          break;
			default: strcat(infix,ch);    
			          break;
		}
	}
	ch[0]=popc();
	strcat(infix,ch);
	strrev(infix);
	
	printf("The infix Expression is : %s",infix);
}

void pushc(char temp)
{
	s1.s[s1.top++]=temp;
}
char popc()
{
	return s1.s[--s1.top];
}

