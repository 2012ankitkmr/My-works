#include<stdio.h>
#include<stdlib.h>
#define MAX 6
int s1[MAX],s2[MAX];
int top=-1;
void enqueue(int);
void dequeue();
void display();

int main()
{
	int i,item;
	printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
	while(1)
    {
      printf("Enter your choice\n");
      scanf("%d",&i);
      switch(i)
      {
        case 1:printf("Enter the element : ");
		scanf("%d",&item);
		enqueue(item);
		break;
		case 2:
		dequeue();
		break;
		case 3:
	    display();
	    break;
		case 4:
		exit(0);
		break;		
	    default: printf("Invalid Entry\n");
		break;
	}
	}
	return 0;
}

void enqueue(int item)
{
	s1[++top]=item;
	
}
void display()
{int i;

for(i=0;i<=top;i++)
printf("%d\t",s1[i]);
	printf("\n");	
}

void dequeue()
{ int i;
	for(i=0;i<=top;i++)
	s2[i]=s1[top-i];
	top--;
	
	for(i=0;i<=top;i++)
	s1[i]=s2[top-i];
}
