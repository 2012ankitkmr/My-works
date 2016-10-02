#include<stdio.h>
#include<stdlib.h>


void create();
void display();


struct node
{
	int info;
	struct node*next;
	
};

struct node*first=NULL;

int main(){
	
	create();
	printf("linklist is\n");
display();
	return 0;
}

void create()
{
int ch,n;
struct node*p,*q;
printf("Enter Node to be created\t");
scanf("%d",&ch);
while(ch>0)
{
	printf("Enter the info :");
	scanf("%d",&n);
	p=(struct node*)malloc(sizeof(struct node));
	p->info=n;
	p->next=NULL;
	if(first==NULL)
	first=p;
	else
	{q=(struct node*)malloc(sizeof(struct node));
		q=first;
	while(q->next!=NULL)
	q=q->next;
	q->next=p;
}
ch--;
	}
}	
	
void display()
{
	
	struct node*p;
	p=first;
	while(p!=NULL)
	{
		
		printf("%d\n",p->info);
		p=p->next;
	}
}	
	

