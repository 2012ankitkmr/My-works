#include<bits/stdc++.h>
using namespace std;
struct bstnode
{
	int info;
	struct bstnode*left;
	struct bstnode*right;
	
};


struct bstnode* newnode(int data)
{
struct bstnode* node=(struct bstnode* )malloc(sizeof(struct bstnode));
node->info=data;
node->left=NULL;
node->right=NULL;
return node;

}
struct bstnode* findmin(struct bstnode* node)
{
	if(node==NULL)
	return NULL;
	else if(node->left==NULL)
	return node;
	else
	
return findmin(node->left);
	
}

struct bstnode* findmax(struct bstnode* node)
{
	if(node==NULL)
     return NULL;
     else if(node->right==NULL)
     return node;
     else
     return findmax(node->right);
     
}

struct bstnode* insert(struct bstnode*node,int data)
{

	if(node==NULL)
	{
			//printf("here\n");
	      node=newnode(data);
	}
	else
	{
		if(data>node->info)
		node->right=insert(node->right,data);
		else if(data<node->info)
		node->left=insert(node->left,data);
	}
	return node;
}

void inorder(struct bstnode* node)
{
	if(node==NULL)
	return;
	inorder(node->left);
	printf("%d ",node->info);
	inorder(node->right);
}

struct bstnode* del(struct bstnode* node,int data)
{
	struct bstnode*temp;
	if(node==NULL)
	printf("Element not in the tree\n");
	
	else if(data<node->info)
	node->left=del(node->left,data);
	else if(data>node->info)
	node->right=del(node->right,data);
	else
	{
		if(node->left&&node->right)
		{
			temp=findmax(node->left);
			node->info=temp->info;
			node->left=del(node->left,node->info);
		}
		else if(!node->left&&!node->right)
		{
			return NULL;
		}
		else
		{
			temp=node;
		if(node->left==NULL)
			node=node->right;
			
		if(node->right==NULL)
		node=node->left;
			
			free(temp);
		}
	}
	return node;
}


int main()
{
	struct bstnode*root=newnode(10);
	root->left=newnode(6);
	root->right=newnode(16);
	root->left->left=newnode(4);
	root->left->right=newnode(9);
	root->right->left=newnode(13);
	root->left->right->left=newnode(7);

printf("Min is %d ",findmin(root)->info);
printf("\nMax is %d ",findmax(root)->info);

struct bstnode* temp;
temp=insert(root,3);
temp=insert(root,33);
temp=insert(root,10);
temp=del(root,33);
inorder(root);
printf("\nMin is %d ",findmin(root)->info);
printf("\nMax is %d ",findmax(root)->info);

	return 0;
}
