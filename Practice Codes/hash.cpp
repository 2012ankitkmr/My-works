#include<bits/stdc++.h>
using namespace std;
#define LOAD_FACTOR 20

struct listnode
{
	int key;
	int data;
	struct listnode*next;
};
struct hashtablenode{
	int bcount;
	struct listnode*next;
};

struct hashtable{
	int tsize;
	int count;
	struct hashtablenode**table;
	
};
struct hashtable*createhashtable(int size){
	struct hashtable*h;
h=(struct hashtable*)malloc(sizeof(struct hashtable));
if(!h)
return NULL;
h->tsize=size/LOAD_FACTOR;
h->count=0;
h->table=(struct hashtablenode**)malloc(sizeof(struct hashtablende*)*h->size);
if(!h->table)
printf("memory error");
return NULL;
for(int i=0;i<h->tsize;i++)
{
	h->table[i]->next=NULL;
	h->table[i]->bcount=0;
}	
return h;
}
int hashsearch(struct hashtable*h,int data)
{
	struct listnode*temp;
	temp=h->table[hash(data,h->tsize)]->next;
	while(temp){
		if(temp->data==data)
		return 1;
		temp=temp->next;
	}
	return 0;
}
int hashinsert(struct hashtable*h,int data)
{
	int index;
	struct listnode*temp,*newnode;
	if(hashsearch(h,data))
	return 0;
	index=hash(data,h->tsize);
	temp=h->table[index]->next;
	newnode=(struct listnode*)malloc(sizeof(struct listnode));
	if(newnode)
	{
		printf("Out Of Space");
		return -1;
	}
	newnode->key=index;
	newnode->data=data;
	newnode->next=h->table[index]->next;
	h->table[index]->next=newnode;
	h->table[index]->bcount++;
	h->count++;
	if(h->count/h->tsize>LOAD_FACTOR)
	rehash(h);
}
int main()
{
	
	return 0;
}
