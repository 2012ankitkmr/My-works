#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	struct node*next;
};

struct node*head=NULL;

struct node*insert(struct node*root,int data)
{
	if(!root)
	{
		root=(struct node*)malloc(sizeof (struct node));
		root->data=data;
		root->next=NULL;
		printf("Root node created #%d\n",root->data);
		return root;
	}
struct node*temp=root,*temp2;
while(temp->next!=NULL)
temp=temp->next;
temp2=(struct node*)malloc(sizeof(struct node));
temp2->next=NULL;
temp2->data=data;
temp->next=temp2;
printf("Node created #%d\n",temp2->data);
return temp2;
}
bool checksize(struct node*lis,int k)
{
	int i=1;
	struct node*li=lis;
	while(li)
	{
		li=li->next;
		i++;
	}
	return i>=k;
}

void reversekblocks(int k)
{
	struct node*temp=head,*temp2,*temp3,*temp4,*store;
bool check=checksize(temp,k);
int ta=0;
	while(check)
	{
		temp3=temp;
//	printf("temp3 %d\n",temp3->data);
        for(int i=0;i<k;i++)
		{
			temp=temp->next;	
			//printf("here\n");	
		}
		temp2=temp;
		//system("pause");
///	printf("temp2 data %d\n",temp2->data);
	
	for(int i=0;i<k-1;i++)
	{
	temp4=temp3->next;	
	temp3->next=temp2;
	temp2=temp3;
     temp3=temp4;
	}
	temp3->next=temp2;
	
	if(!ta)
	head=temp3;
	else
	{
		store=head;
		for(int j=0;j<ta*k-1;j++)
		store=store->next;
		//printf("store data %d\n",store->data);
		store->next=temp3;	
	}
	
	
	for(struct node*t=head;t;t=t->next)
	printf("%d ",t->data);
	printf("\n");
		bool check=checksize(temp,k);
//	printf("check=%d\n",check);
	ta++;
	}
	
}
int main()
{
	head=(struct node*)malloc(sizeof(struct node));
	head->data=1;
	head->next=NULL;
	for(int i=2;i<=10;i++)
     struct node*nod=insert(head,i);
struct node*lis=head;
while(lis->next!=NULL)
{
	printf("%d ",lis->data);
	lis=lis->next;
}
int k;
printf("\n");
printf("Enter the value of K : ");
scanf("%d",&k);
reversekblocks(k);
	return 0;
}
