#include<bits/stdc++.h>

struct btnode
{
	int info;
	struct btnode*left;
	struct btnode*right;
	
};
struct btnode* newnode(int data)
{
	struct btnode* node=(struct btnode* )malloc(sizeof(struct btnode));
node->info=data;
node->left=NULL;
node->right=NULL;
return node;
}

struct btnode* LCA(struct btnode* node,struct btnode*a,struct btnode*b)
{
	if(node==NULL)
	return node;
	if(node==a||node==b)
	return node;
	struct btnode*left,*right;
	left=LCA(node->left,a,b);
	right=LCA(node->right,a,b);
	if(left&&right)
	return node;
	else
	return left?left:right;
}

int main()
{
	struct btnode*root=newnode(1);
	root->left=newnode(2);
	root->right=newnode(3);
	root->left->left=newnode(4);
	root->left->right=newnode(5);
	root->right->left=newnode(6);
	root->right->right=newnode(7);

struct btnode* node=LCA(root,root->right->right,root->right->left);
printf("number is %d",node->info);
	return 0;
}
