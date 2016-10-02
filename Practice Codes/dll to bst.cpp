#include<bits/stdc++.h>
using namespace std;

struct binarytreenode
{
	int data;
  struct binarytreenode*left;
  struct binarytreenode*right;
};


typedef struct binarytreenode treenode;


treenode*newnode(treenode*node,int data)
{
	treenode*new_node=(treenode*)malloc(sizeof (treenode));
	new_node->data=data;
	new_node->left=NULL;
	new_node->right=NULL;
	return new_node;
}



struct dll
{
	int data;
	struct dll*next;
	struct dll*prev;
};


struct dll*listparent=NULL;


struct dll*insert(struct dll*root,int data)
{
	if(!root)
	{
		root=(struct dll*)malloc(sizeof (struct dll));
		root->data=data;
		root->next=NULL;
		root->prev=NULL;
		printf("Root node created\n");
		return root;
	}
struct dll*newdll=(struct dll*)malloc(sizeof(struct dll));
newdll->data=data;
newdll->next=root->next;
root->next=newdll;
newdll->prev=root;
printf("New node created\n");
printf("Newlist is : \n");
struct dll*temp;
temp=listparent;
while(temp)
{
	printf("%d ",temp->data);
	temp=temp->next;
}
printf("\n");
return newdll;
}



struct dll*finddllmid(struct dll*parentnode)
{
	struct dll*slow;
	struct dll*fast;
slow=parentnode;
fast=parentnode;
while(fast)
{
	slow=slow->next;
	fast=fast->next->next;
}	
	return slow;
}


struct dll*getmid(struct dll*first,struct dll*second)
{
	struct dll*temp=first;
	int n=0;
	while(temp!=second)
	{
		temp=temp->next;
		n++;
	}
	temp=first;
	n/=2;
	while(n--)
	{
		temp=temp->next;
	}
	return temp;
}



treenode*createbstutil(treenode*root,struct dll*liststart,struct dll*listend)
{
	if(!root)
	{
		 root=(treenode*)malloc(sizeof(treenode));
		root->data=listend->data;
		root->left=NULL;
		root->right=NULL;
		system("pause");
		printf("Root is null\nRoot is created.\n");
	}
	root->data=listend->data;
	root->left=createbstutil(root,liststart,getmid(liststart,listend));
	root->right=createbstutil(root,getmid(liststart,listend)->next,listend);
	return root;
}




treenode*createbst(treenode*root,struct dll*parentnode)
{
 printf("Finding middle node......\n");
	struct dll*midnode=finddllmid(parentnode);
	system("pause");
printf("Middle node found =  : %d  \n",midnode->data);
	root->data=midnode->data;

	printf("Root node created\n");
	system("pause");
	printf("creating left subtree node......\n");
	root->left=createbstutil(root,listparent,midnode->prev);
	system("pause");
	printf("Finding last node......\n");
	struct dll*lastnode=listparent;
	while(lastnode->next)
	{
		lastnode=lastnode->next;
	}
	system("pause");
	printf("last node found = :  %d \n",lastnode->data);
	system("pause");
	printf("Creating right subtree......\n");
	root->right=createbstutil(root,midnode->next,lastnode);
	printf("Tree created.\nReturning to main........");
	system("pause");
	return root;
}




void inorder(treenode*root)
{
	if(!root)
	return;
	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);
}




int main()
{
	int info,a,t;
	printf("Enter the size of dll : ");
	scanf("%d",&t);
printf("Enter the 1st element : ");
	scanf("%d",&info);
listparent=insert(listparent,info);
struct dll*dangler=listparent;
t--;
a=1;
while(t--)
{
	a++;
printf("Enter the %d element : ",a);
	scanf("%d",&info);	
	dangler=insert(dangler,info);
}	
		printf("Creating Binary search tree......\n");
		system("pause");
	treenode*root=createbst(root,listparent);
	printf("The inorder traversal is :\n");
	inorder(root);	
	printf("\n");
	return 0;
}
