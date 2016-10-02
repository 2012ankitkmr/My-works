#include<bits/stdc++.h>

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
printf("Max is %d ",findmax(root)->info);
	return 0;
}
