#include<bits/stdc++.h>
using namespace std;

struct heap
{
	int *array;
	int count;
	int capacity;
	int heap_type;
};

struct heap*createheap(int capacity,int heap_type)
{
	struct heap*h=(struct heap*)malloc(sizeof (struct heap));
	h->count=0;
	h->heap_type=heap_type;
	h->capacity=capacity;
	h->array=(int*)malloc(sizeof (int)*h->capacity);
	return h;
}
int parent(struct heap*h,int i)
{
	if(i<=0||i>=h->count)
	return -1;
	return (i-1)/2;
}
int leftchild(struct heap*h,int i)
{
	int left=2*i+1;
	if(left>=h->count)
	return -1;
	return  left;
}
int rightchild(struct heap*h,int i)
{
	
	int right=2*i+2;
	if(right>=h->count)
	return -1;
	return right;
}


int getmaximum(heap*h)
{
	if(h->count==0)
	return -1;
	return h->array[0];
}

void percolatedown(struct heap*h,int i)
{
	int max,temp;
	int l=leftchild(h,i);
	int r=rightchild(h,i);
	//printf("here\n");
	if(l!=-1&&h->array[l]>h->array[i])
	max=l;
	else
	max=i;
	if(r!=-1&&h->array[r]>h->array[max])
	max=r;
	if((l==-1&&r==-1)||(max==i))
	return;
	
	if(max!=i)
	{
		temp=h->array[i];
	h->array[i]=h->array[max];
	h->array[max]=temp;
	}
	percolatedown(h,max);
}

int deletemax(struct heap*h)
{
	int data;
	if(h->count==0)
	return -1;
	data=h->array[0];
	h->array[0]=h->array[h->count-1];
	h->count--;
	percolatedown(h,0);
}

void resizeheap(struct heap*h)
{
	int *arr=h->array;

h->array=(int*)malloc(sizeof(int)*h->capacity*2);
h->capacity=h->capacity*2;
for(int i=0;i<h->count;i++)
{
	h->array[i]=arr[i];
}
free(arr);
}
int insert(struct heap*h,int data)
{
	int i;
	if(h->count==h->capacity)
	resizeheap(h);
	h->count++;
i=h->count-1;
	
	while(i>0&&data>h->array[(i-1)/2])
	{
		h->array[i]=h->array[(i-1)/2];
		i=(i-1)/2;
	}
	h->array[i]=data;
}

void buildheap(struct heap*h,int a[],int n)
{
	if(h==NULL)
	return;
	while(h->capacity<n)
	resizeheap(h);
	printf("here\n");
	for(int i=0;i<n;i++)
	h->array[i]=a[i];
	h->count=n;
	for(int i=(n-1)/2;i>=0;i--)
	percolatedown(h,i);
}
int main()
{
struct heap*hp=createheap(13,1);

int a[15]={31,1,21,5,10,12,18,3,2,8,7};

buildheap(hp,a,11);
//printf("here\n");
    for(int i=0;i<11;i++)
	printf("%d ",hp->array[i]);
	insert(hp,54);
	printf("\n");
	    for(int i=0;i<12;i++)
	printf("%d ",hp->array[i]);
	return 0;
}
