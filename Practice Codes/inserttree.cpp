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

void insert(struct btnode* node,int data)
{
	if(node==NULL)
	return;
queue<struct btnode*>q;
   q.push(node);
   	struct btnode* temp;
 
   while(!q.empty())
   {
    	temp=q.front();
    	q.pop();
    	if(temp->left)
    	q.push(temp->left);
    	else
    	{
    		temp->left=newnode(data);
    		return;
    	}
   	     
   	     if(temp->right)
   	     q.push(temp->right);
   	     else
   	     {
   	     	temp->right=newnode(data);
   	     	return;
   	     }
   } 

}

int main()
{
	struct btnode*root=newnode(1);
       root->left=newnode(2);
	   root->right=newnode(3);
	   root->left->left=newnode(4);
	   root->left->right=newnode(5); 
	
	insert(root,6);
	insert(root,7);
	
	printf("Preorder traversal of the tree : ");
	preorder(root);
	
	return 0;
}
