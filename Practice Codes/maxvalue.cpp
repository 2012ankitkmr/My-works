#include<bits/stdc++.h>
#include<queue>
using namespace std;

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

int maxtree(struct btnode* node)
{
	queue<struct btnode*>q;
	q.push(node);
	int max=0;
	struct btnode*temp;
	while(!q.empty())
	{
	temp=q.front();
	q.pop();
	if(max<temp->info)
	max=temp->info;
	if(temp->left)
	q.push(temp->left);
	if(temp->right)
	q.push(temp->right);
	}
	return max;
}
int main()
{
	struct btnode*root=newnode(5);
	root->left=newnode(7);
	root->right=newnode(2);
	root->left->left=newnode(9);
	root->right->left=newnode(8);
	root->left->right=newnode(10);
	root->right->right=newnode(6);
	int max=maxtree(root);
	printf("max=%d",max);
	return 0;
}

