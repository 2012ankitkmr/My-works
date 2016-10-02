#include<bits/stdc++.h>
using namespace std;

struct btreenode{
	int data;
	struct btreenode*left;
	struct btreenode*right;
};

struct btreenode* newnode(int data)
{
	struct btreenode*node = (struct btreenode*)malloc(sizeof(struct btreenode));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
	
}
struct btreenode*findLCA(struct btreenode*root,struct btreenode*a,struct btreenode*b)
{
	
	if(!root)
	return NULL;
	struct btreenode*l,*r;
	if(root==a||root==b)
	return root;
	l = findLCA(root->left,a,b);
	r = findLCA(root->right,a,b);
	if(l&&r)
	return root;
	else
	return l?l:r;
	
}

int main()
{
	struct btreenode*root;
	root = newnode(5);
	root ->left = newnode(4);
	root->left->left = newnode(8);
	root->left->right = newnode(7);
	root->left->right->left = newnode(11);
	root->left->left->right = newnode(1);
	root->right=newnode(9);
	
	printf("LCA = %d\n",(findLCA(root,	root->left->left->right,root->left->right))->data);
	
	return 0;
}
