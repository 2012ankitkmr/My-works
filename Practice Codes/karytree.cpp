#include<bits/stdc++.h>
using namespace std;

struct karynode
{
	char data;
struct karynode*child[];
	
};
int ind=0;

struct karynode* buildtree(char a[],int n,int k)
{
	int i;
	if(n<=0)
	return NULL;
	struct karynode* newnode=(struct karynode*)malloc(sizeof(struct karynode));
	
	newnode->child=(struct karynode*)malloc(k*sizeof(karynode));
	
	newnode->data=a[ind];
	for(i=0;i<k;i++)
	{
		if(k*ind+i<n)
		{
			ind++;
			newnode->child[i]=buildtree(a,n,k);
		}
		else newnode->child[i]=NULL;
	}
	return newnode;
}
int main()
{   char a[45],p;
	int i;
	p='A';
	for(i=0;i<10;i++)
	{
		a[i]='p';
		p++;
	}
	struct karynode*root=buildtree(a,10,3);
	printf("char=%c",root->data);
	return 0;
}
