#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

struct treenode
{
int info;
treenode*next;
treenode*prev;	
};
struct treenode*newnode(int data)
{
struct treenode*newnode=(struct treenode*)malloc(sizeof(struct treenode));
newnode->info=data;
newnode->next=NULL;
newnode->prev=NULL;
return newnode;
	
}
//typedef struct treenode node;
struct treenode*buildtree(int arr[],int low,int high)
{
	if(low>high)
	return NULL;
	
	int mid=(low+high)/2;
struct treenode*node=newnode(arr[mid]);
	
		node->prev=buildtree(arr,low,mid-1);
		node->next=buildtree(arr,mid+1,high);
				return node;
}
int a;
struct treenode* deletelargest(struct treenode*node,int data)
{
	if(!node)
	return NULL;

	if(node->next==NULL&&data<node->info)
	{
		a=1;	/////node=NULL;
	free(node);
    }	
	node->next=deletelargest(node->next,data);

	return node;
}

struct treenode* insert(struct treenode*root,int data)
{
	if(root==NULL)
	{
		root=(struct treenode*)malloc(sizeof(struct treenode));
		root->next=NULL;
		root->prev=NULL;
		root->info=data;
	}
if(root->info>data)
root->prev=insert(root->prev,data);
if(root->info<data)
root->next=insert(root->next,data);
	return root;
}

void inorder(struct treenode*root)
{
	if(!root)
	return;
	inorder(root->prev);
	printf("in=%d ",root->info);
	inorder(root->next);
}
int main()
{
	int arr[]={4,65,44,5,11,99,14,66,1,23,17,199,222};
	int k=5;
	int n=sizeof(arr)/sizeof(arr[0]);
	sort(arr,arr+k);
	struct treenode*root=buildtree(arr,0,k-1);\
	struct treenode*node1;
	//printf("ooo%d",root->next->next->info);
   for(int i=k;i<n;i++)
{
	a=0;
	node1=deletelargest(root,arr[i]);
 inorder(root);
	printf("arr=%d,a=%d\n",arr[i],a);
	if(a)
	node1=insert(root,arr[i]); 
}
	 inorder(root);
for(int i=0;i<n;i++)
printf("%d ",arr[i]);
	return 0;
}
