#include "bits/stdc++.h"
using namespace std;

struct avlnode{
struct avlnode*left;
struct avlnode*right;
int data;
int height;
};

int getHeight(struct avlnode*node)
{
  if(!node)
  return -1;
  else return node->height;
}

struct avlnode*Singleleftrotate(struct avlnode*X)
{
  printf("In Single left Rotate at %d\n",X->data);
  struct avlnode*W = X->left;
  X->left = W->right;
  W->right=X;
  X->height = max(getHeight(X->left),getHeight(X->right))+1;
  W->height = max(getHeight(W->left),getHeight(W->right))+1;
return W;
}

struct avlnode*Singlerightrotate(struct avlnode*W)
{
  printf("In Single right Rotate at %d\n",W->data);

struct avlnode*X = W->right;
W->right = X->left;
X->left = W;
W->height = max(getHeight(W->left),getHeight(W->right))+1;
X->height = max(getHeight(X->left),getHeight(X->right))+1;
return X;
}

struct avlnode*Doubleleftrotate(struct avlnode*Z)
{
  printf("In Double left Rotate at %d\n",Z->data);

  Z->left= Singlerightrotate(Z->left);
  return Singleleftrotate(Z);
}

struct avlnode*Doublerightrotate(struct avlnode*X)
{
  printf("In Double Right Rotate at %d\n",X->data);

  X->right= Singleleftrotate(X->right);
  return Singlerightrotate(X);
}

struct avlnode*insert(struct avlnode*root,int data)
{

if(!root)
{

//  printf("Here at %d\n",data);
root = (struct avlnode*)malloc(sizeof(struct avlnode));
root->left = root->right = NULL;
root->data = data;
}
else if(data<root->data)
{
root->left = insert(root->left,data);
if((getHeight(root->left)-getHeight(root->right))==2)
{
if(data<root->left->data)
root = Singleleftrotate(root);
else
root = Doubleleftrotate(root);
}

}
else if(data>root->data)
{
  root->right = insert(root->right,data);
  if((getHeight(root->right)-getHeight(root->left))==2)
  {
  if(data>root->right->data)
  root = Singlerightrotate(root);
  else
  root = Doublerightrotate(root);
  }
}

root->height = max(getHeight(root->left),getHeight(root->right))+1;
return root;
}

int main()
{
struct avlnode*root = NULL;

int a[]  = {2,32,7,11,21,13,16,4,56};
int n = sizeof(a)/sizeof(int);


for(int i = 0; i < n;i++)
{printf("Inserting %d\n",a[i]);
  root = insert(root,a[i]) ;
}
  return 0;
}
