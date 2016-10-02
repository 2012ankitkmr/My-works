#include<bits/stdc++.h>
using namespace std;

struct heap
{
	int *arr;
	int heapsize;
	int count;
};
struct heap*root;
void construct_minheap(int size)
{
root=(struct heap*)malloc(sizeof(struct heap));
root->heapsize=size<<1+2;
root->count=0;
root->arr=(int*)malloc(root->heapsize*sizeof (int));	
}
void insert(struct heap*root,int data)
{
	if(root->count==0)
	{
		root->arr[0]=data;
		root->count++;
		return;
	}
	int i=root->count;
	root->count++;
	while(i>0&&data<root->arr[(i-1)/2])
	{
		root->arr[i]=root->arr[(i-1)/2];
		i=(i-1)/2;
	}
	root->arr[i]=data;
	//printf("arr[0]=%d,arr[1]=%d,arr[2]=%d\n",root->arr[0],root->arr[1],root->arr[2]);
}
int minheap_element(struct heap*root)
{
	if(root->count==0)
	return -1;
	return root->arr[0];
}
void replace(struct heap*root,int data)
{
	root->arr[0]=data;
}
int leftchild(struct heap*root,int node)
{
	int left =2*node+1;
	if(left>=root->count)
	return-1;
	return left;
}
int rightchild(struct heap*root,int node)
{
	int right =2*node+2;
	if(right>=root->count)
	return-1;
	return right;
}

void heapify(struct heap*root,int node)
{
	int left=leftchild(root,node);
int right=rightchild(root,node);
	int mini;
	//printf("count=%d\n",root->count);
	if(left!=-1&&root->arr[left]<root->arr[node])
	mini=left;
	if(right!=-1&&root->arr[right]<root->arr[mini])
	mini=right;
	if(right==-1&&left==-1||(mini==node))
	return;
	if(mini!=node)
	{
		int temp=root->arr[mini];
		root->arr[mini]=root->arr[node];
		root->arr[node]=temp;
	}
	heapify(root,mini);
}
void findkthlargest(int k)
{
	int x;
	int heapcount=0;
	construct_minheap(k);
	while(1)
	{
		printf("Enter the next element to the stream : ");
		cin>>x;
		int kthlargest=minheap_element(root);
			heapcount++;
		if(heapcount<=k)
		{
			insert(root,x);
			//heapify(root,0);
			if(heapcount==k)
			{
				printf("kth largest element is : %d\n",kthlargest);
			}
		}
		
		else
		{
		 if(kthlargest>=x)
	printf("kth largest element is : %d\n",kthlargest);
		else
		{
			replace(root,x);
			heapify(root,0);//percolate down
			kthlargest=minheap_element(root);
			printf("kth largest element is : %d\n",kthlargest);
//				printf("arr[0]=%d,arr[1]=%d,arr[2]=%d\n",root->arr[0],root->arr[1],root->arr[2]);

		}
}
	}
	
}

int main()
{
	int k=3;
	findkthlargest(k);
	return 0;
}
