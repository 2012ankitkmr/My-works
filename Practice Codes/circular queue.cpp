#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int q[MAX];

void enqueue(int);
void dequeue(int);
void display();

int top=0;
int main()
{
	int i,item;
	printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
	while(1)
	{
		printf("Enter your choice : ");
		scanf("%d",&i);
		switch(i)
		{
			case 1: printf("Enter the element : ");
			scanf("%d",&item);
			enqueue(item);
			break;
			case 2: printf("Which element must be dequeued : ");
			scanf("%d",&item);
             dequeue(item);
			break;
			case 3: display();
			break;
			case 4 : exit(0);
			break;
			default: printf("Invalid entry\n");
			break;
		}
	}
return 0;
}
void enqueue(int x)
{
	q[++top]=x;
}

void dequeue(int y)
{ 
	int i;
	if(y>top)
	y=y%top;
	
for(i=y+1;i<=top;i++)
q[i-1]=q[i];
	top--;
}

void display()
{ int i;
	for(i=1;i<=top;i++)
	printf("%d\t",q[i]);
	
	printf("\n");
}

