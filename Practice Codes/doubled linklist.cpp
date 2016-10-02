#include<stdio.h>
#include<stdlib.h>
void delnode();
void insert(int);
void display();
struct node
{
	int info;
	struct node*next;
	struct node*previous;	
};

struct node*first=NULL;
struct node*last=NULL;
 int main()
 {
 	int info,n;
 	printf("1.Insert an element\n2.Delete a element\n3.Display\n4.Exit\n");
 	while(1)
	 {
	 	printf("Enter your choice : ");
	 	scanf("%d",&n);
	 	
	switch(n)
	{
	 	
 	case 1: printf("Enter the element : ");
	 scanf("%d",&info);
	 insert(info);
	 break;	
 	case 2:  delnode();
	 break;
	 case 3: display();
	 break;
	 case 4: exit(0);
	 break;
	 default: printf("Invalid Entry\n");
	 break;
 	}
   }
 	return 0;
     }   

void insert(int item)
{
	struct node*temp,*temp1;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->info=item;
	temp->next=NULL;
	if(first==NULL)
	{
	first=temp;
temp->previous=NULL;
last=first;
}
else
{    temp1=(struct node*)malloc(sizeof(struct node));
	temp1=first;
	while(temp1->next!=NULL)
	temp1=temp1->next;
	temp1->next=temp;
	temp->previous=temp1;
	last=temp;
}	
}
void delnode()
{ int i,n;
	struct node*temp,*temp1,*temp2;
printf("Enter the node to be deleted from last : ");
scanf("%d",&n);
n--;

temp1=(struct node*)malloc(sizeof(struct node));
temp2=(struct node*)malloc(sizeof(struct node));
temp=(struct node*)malloc(sizeof(struct node));
temp=last;
for(i=0;i<n-1;i++)
temp=temp->previous;
temp1=temp->previous;
temp2=temp1->previous;
temp->previous=temp2;
temp2->next=temp;

free(temp1);
}

void display()
{
	struct node*temp;
	temp=first;
	while(temp!=NULL)
	{
		printf("%d\t",temp->info);
		temp=temp->next;
	}
	printf("\n");
}
