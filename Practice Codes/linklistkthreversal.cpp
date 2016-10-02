#include<bits/stdc++.h>
using namespace std;


struct ll{
	int data;
	struct ll*next;	
};

struct ll* newnode(int data)
{
	struct ll *node = (struct ll*)malloc(sizeof(struct ll));
	node ->data = data;
	node->next = NULL;
	return node;	
}

void printll(struct ll*root)
{
	struct ll*ptr=root;
	while(ptr)
	{
		printf("%d ",ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
	
}

int findlengthll(struct ll*root)
{
	struct ll*ptr = root;
	int len=0;
	while(ptr)
	{
		ptr=ptr->next;
		len++;
	}
	return len;
}

struct ll*Kreverselist(struct ll*root,int k)
{
	if(root==NULL)
	{
		printf("Root Empty!" );
		return NULL;
	}
	int length= findlengthll(root);
	
	struct ll*firstptr,*sectionhead=root,*sectionlast=NULL,*temp,*nextnode;
	for(int i = k;i<=length;i+=k)
	{
		firstptr = sectionhead;
		temp = NULL;
		for(int j = 0;j < k ; j++ )
		{
			nextnode = sectionhead->next;
			sectionhead->next = temp;
			temp = sectionhead;
			sectionhead = nextnode;
			
		}
		sectionhead = temp;
		
		
		if(sectionlast)
		sectionlast->next = sectionhead;
		else
		root = sectionhead;
		
		sectionlast = firstptr;
		sectionhead = nextnode;	
	}
	if(length%k!=0)
	{
	
    	if(sectionlast)
		sectionlast->next = sectionhead;
		else
		root = sectionhead;
	}
			return root;
}


int main()
{
	struct ll*root=NULL,*crawl=NULL;
	printf("Enter no. of nodes : ");
	int n,info;
	scanf("%d",&n);
	printf("Enter Values: ");
	n--;
		scanf("%d",&info);	
	root=newnode(info);
	crawl = root;
	while(n--)
	{
		scanf("%d",&info);	
		crawl->next = newnode(info);	
		crawl = crawl->next;
	}

	root = Kreverselist(root,3);
	
	printll(root);
	
	
	
	return 0;
}
