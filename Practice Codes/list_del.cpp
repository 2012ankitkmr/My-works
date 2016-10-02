#include<stdio.h>
#include<stdlib.h>

void create();
void display();
void delete_at_end();
void delete_at_beg();
void delete_at_pos();

struct node
{
	int info;
	struct node*next;
};

struct node*first=NULL;

int main()
{
	int i,e=1;
	create();
	while(e)
	{
		printf("1.Display\n2.Delete at the beginning\n3.Delete at end\n4.Delete at position\n5.Exit\n");
		
		scanf("%d",&i);
		switch(i)
		{
			case 1:printf("The list is\n");
			display();
			       break;
			 case 2:delete_at_beg();
			 break;
			 case 3:delete_at_end();
			 break;
			 case 4:delete_at_pos();
			 break;
			 case 5:e=0;
			 break;
		}		
	}
	return 0;
}

void create()
{
	struct node*p,*temp;
	int inf,n;
	printf("Enter the no. of nodes to be created: ");
	scanf("%d",&n);
	while(n--)
	{
	printf("Enter the info: ");
	scanf("%d",&inf);
	p=(struct node*)malloc(sizeof(struct node));
	p->info=inf;
	p->next=NULL;
	if(first==NULL)
	first=p;
	else
	{temp=(struct node*)malloc(sizeof(struct node));
	temp=first;
	
	while(temp->next!=NULL)
	temp=temp->next;
	
	temp->next=p;
		
		
	}
	}
}



void display()
{
	struct node*temp;
	temp=first;
	while(temp!=NULL)
	{
		printf("%d\n",temp->info);
		temp=temp->next;
	}
}

void delete_at_beg()
{
	struct node*temp;
	if(first==NULL)
	printf("List is empty\n");
	else{
	
	temp=first->next;
	
free(first);
	first=temp;
}	
}
void delete_at_end()
{
	struct node*temp,*temp1;
	temp=first;
	while(temp->next->next!=NULL)
	temp=temp->next;
	if(temp==NULL)
	printf("list is empty\n");
	else{
		temp1=temp;
	temp=temp->next ;
	free(temp);
		temp1->next=NULL;
	}
}

void delete_at_pos()
{
	struct node*temp,*temp1;
	int n,i;
	printf("Enter the node to be deleted : "); 
	scanf("%d",&n);
	n--;
	temp=first;
	for(i=0;i<n-1;i++)
	{
		temp=temp->next;		
	}
	if(temp==NULL)
	printf("Invalid deletion\n");
	
	else{
		
		temp1=temp->next;
		temp->next=temp->next->next;
		free(temp1);
	}
	
	
}
