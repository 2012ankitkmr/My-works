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
	struct btnode* node=(struct btnode*)malloc(sizeof(struct btnode));
     node->info=data;
     node->left=NULL;
	node->right=NULL;
	return node;
}

void preorder (struct btnode* node)
{
	if(node==NULL)
	return;
	printf("%d ",node->info);
	preorder(node->left);
	preorder(node->right);
	
}
void inorder(struct btnode* node)
{
	if(node==NULL)
	return;
	inorder(node->left);
	printf("%d ",node->info);
	inorder(node->right);
}

void postorder(struct btnode* node)
{
	if(node==NULL)
	return;
	postorder(node->left);
	postorder(node->right);
	printf("%d ",node->info);
}

void levelorder(struct btnode* node)
{
struct btnode*temp;

queue<struct btnode*>q;

if(node==NULL)
return;

q.push(node);

while(!q.empty())
{
temp=q.front();
q.pop();

printf("%d ",temp->info);

if(temp->left)
q.push(temp->left);

if(temp->right)
q.push(temp->right);	

}
}

int main()
{
	struct btnode* root=newnode(1);
	root->left=newnode(2);
	root->right=newnode(3);
	root->left->left=newnode(4);
	root->left->right=newnode(5);
	root->right->left=newnode(6);
	root->right->right=newnode(7);

printf("The preorder traversal is : ");
	 preorder(root);
	 
printf("\nThe inorder traversal is : ");
    inorder(root);
  
printf("\nThe postorder traversal is : ");
   	 postorder(root);

printf("\nThe level order traversal is : ");
levelorder(root);

	return 0;
}
