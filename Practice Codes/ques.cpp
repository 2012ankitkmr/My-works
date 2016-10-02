#include<stdio.h>
#define MAX 20

int q[MAX];
int f=-1;
int r=-1;

void enqueue(int item);
void dequeue();
void display();

int main()
{
	
	int i,item,a=1;
	while(a)
	{
		printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
		scanf("%d",&i);
		switch(i)
		{	case 1:	printf("Enter item\n");
		            scanf("%d",&item);
                    enqueue(item);
			break;
			case 2:dequeue();
			break;
			case 3: display();
			break;
			case 4:i=0;
			break;
		}
		
	}
	return 0;
}

void enqueue(int item)
{
	if(r>MAX)
	printf("size full\n");
else
   if(r==-1)
   {
   	f=0;
   	r++;
   }

	else
	r++;
	q[r]=item;
}	
	
void dequeue()
{
	if(f>r)
	printf("queue empty\n");
	else
	f++;
}
void display()
{
	int i;
	for(i=f;i<=r;i++)
	printf("%d\t",q[i]);
	printf("\n");
	
	
}
