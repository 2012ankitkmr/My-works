#include<bits/stdc++.h>
using namespace std;



struct ll{
	int data;
	struct ll *next;
};

struct ll* find_ans(int n,int arr[])
{
	struct ll*head=NULL,*temp=NULL;
	
for(int i = 0;i<n;i++)
{
	struct ll*node = (struct ll*)malloc(sizeof(struct ll*));
	node->data=arr[i];
	node->next = NULL;
	if(!head)
	{
	head = node;
	temp =head;
     }  
	else
	{
		temp->next = node;
		temp=temp->next;
	}
}	
int has[1004];
memset(has,0,sizeof has);
temp = head;
struct ll* prev=head;
//printf("here\n");
while(temp!=NULL)
{
	if(has[temp->data])
	{
	prev->next = temp->next;
	temp->next=NULL;
	free(temp);
	temp = prev->next;	
	}
	else
	{
		has[temp->data]=1;
	
	prev =temp;
	temp = temp->next;
}
}
return head;	
}


int main()
{
	int n=8;
	int arr[]={3, 4, 3 ,2 ,6, 1, 2 ,6};
	struct ll *node,*ptr;
	node = find_ans(n,arr); 
	ptr = node;
	
	while(ptr!=NULL)
	{
	printf("%d ",ptr->data);
	ptr=ptr->next;
	}
	
	return 0;
}
