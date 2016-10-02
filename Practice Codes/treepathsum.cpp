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

bool haspathsum(struct btnode* node,int sum)
{
	if(node==NULL)
	return sum==0;
	else
	{
		int remainingsum=sum-node->info;
		if((node->left&&node->right)||(!node->left&&!node->right))
		return haspathsum(node->left,remainingsum)||haspathsum(node->right,remainingsum);
		
		else if(node->left)
		haspathsum(node->left,remainingsum);
		else
		haspathsum(node->right,remainingsum);
	}
	
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
if(haspathsum(root,10))
printf("YES\n");
else
printf("NO\n");

	return 0;
}
