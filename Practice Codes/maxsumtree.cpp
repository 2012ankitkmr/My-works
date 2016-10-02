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
	struct btnode* node=(struct btnode*)malloc(sizeof (struct btnode));
    node->info=data;
    node->left=NULL;
    node->right=NULL;
 return node;
}

void preorder(struct btnode* node)
{
	if(node==NULL)
	return;
	printf("%d ",node->info);
	preorder(node->left);
	preorder(node->right);
}
int findsummax(struct btnode*node)
{
	if(node==NULL)
	return 0;
	int maxsum=0,currentsum=0,maxlevel=0,level=0;
	queue<struct btnode*>q;
	q.push(node);
	q.push(NULL);
	struct btnode*temp;
	while(!q.empty())
	{
		temp=q.front();
		q.pop();
		if(temp==NULL)
		{
			if(currentsum>maxsum)
			{
				maxsum=currentsum;
				maxlevel=level;
			}
			if(!q.empty())
			q.push(NULL);
			level++;
		}
		else
		{
			currentsum+=temp->info;
			if(temp->left)
			q.push(temp->left);
			if(temp->right)
			q.push(temp->right);
		}
		
		
	}
	return maxlevel;
}

int main()
{
	struct btnode*root=newnode(1);
       root->left=newnode(2);
	   root->right=newnode(3);
	   root->left->left=newnode(4);
	   root->left->right=newnode(5); 
       root->right->right=newnode(7);
	   root->right->left=newnode(6);	
printf("level=%d",findsummax(root));

	printf("\nPreorder traversal of the tree : ");
	preorder(root);
	
	return 0;
}
