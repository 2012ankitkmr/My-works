#include<bits/stdc++.h>
using namespace std;

struct avltree
{
	struct avltree*left;
	int info;
	struct avltree*right;
	int height;
};

int height(struct avltree* node)
{
	if(!node)
	return -1;
	else
	return node->height;
}
int max(int a,int b)
{
	return a>b?a:b;
}
struct avltree*newnode(int data,int height)
{
	struct avltree*node=(struct avltree*)malloc(sizeof(struct avltree));
	node->info=data;
	node->height=height;
	node->left=NULL;
	node->right=NULL;
	return node;
}

struct avltree*singlerotationleft(struct avltree*X)
{
	struct avltree*W;
	X->left=W->right;
	W->right=X;
	X->height=max(height(X->left),height(X->right))+1;
	W->height=max(height(W->left),X->height)+1;
	return W;
}

struct avltree*singlerotationright(struct avltree*W)
{
	struct avltree*X;
	W->right=X->left;
	X->left=W;
	W->height=max(height(W->right),height(W->left))+1;
	X->height=max(height(X->right),W->height)+1;
	return X;
	
}

struct avltree* doublerotationwithleft(struct avltree*Z)
{
	Z->left=singlerotationright(Z->left);
	return singlerotationleft(Z);
}


struct avltree* doublerotationwithright(struct avltree*Z)
{
	Z->right=singlerotationleft(Z->right);
	return singlerotationright(Z);
}

struct avltree*insert(struct avltree* node,struct avltree*parent,int data)
{
	if(!node)
	{
		node=(struct avltree*)malloc(sizeof(struct avltree));
		node->height=0;
		node->left=node->right=NULL;
		node->info=data;
		
	}	
	else if(data<node->info)
	{
		node->left=insert(node->left,node,data);
		if((height(node->left)-height(node->right))==2)
		{
	     if(data<node->left->info)
		 node=singlerotationleft(node);
		 else node=doublerotationwithleft(node);		
		}
	}
	else if(data>node->info)
	{

		node->right=insert(node->right,node,data);
			//	printf("h=%d\n",node->height);
		if((height(node->right)-height(node->left))==2)
		{
				//printf("here\n");
			if(data<node->right->info)
			node=singlerotationright(node);
			else
			node=doublerotationwithright(node);
		}
	}
	node->height=max(height(node->left),height(node->right))+1;
			//	printf("max=%d\n",max(height(node->left),height(node->right)));
	return node;
}

void inorder(struct avltree* node)
{
	if(node==NULL)
	return ;
	inorder(node->left);
	printf("i%d,h%d ",node->info,node->height);
	inorder(node->right);
}

int main()
{
struct avltree* root=newnode(20,0);	
	root->left=newnode(12,1);
	root->right=newnode(35,1);
//	printf("root info = ",root->info);
	printf("\nInorder traversal is : ");
	inorder(root);
	//struct avltree*temp;
	root=insert(root,root,14);
	root=insert(root,root,44);
	root=insert(root,root,4);
    root=insert(root,root,17);
	root=insert(root,root,34);
	
	printf("\nInorder traversal is : ");
	inorder(root);
	return 0;
}
