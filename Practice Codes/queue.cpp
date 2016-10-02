#include<bits/stdc++.h>
using namespace std;
struct listnode{
	int data;
	struct listnode*next;
};

struct queu{
	struct listnode*front;
	struct listnode*rear;
	
};
struct queu*createqueue()
{
	struct queu *q;
	struct listnode*temp;
	q=(struct queu*)malloc(sizeof(struct queu));
	if(!q)
	return NULL;
	temp=(struct listnode*)malloc(sizeof(struct listnode));
	q->front=q->rear=NULL;
	return q;
	
}

int isemptyqueue(struct queu*q)
{return (q->front==NULL);
}
void enqueue(struct queu*q,int data)
{
	struct listnode*newnode;
	newnode=(struct listnode*)malloc(sizeof(struct listnode));
	if(!newnode)
	return;
	newnode->data=data;
	newnode->next=NULL;
	if(q->rear)
	q->rear->next=newnode;
	q->rear=newnode;
	if(q->front==NULL)
	q->front=q->rear;
}
int dequeue(struct queu*q)
{
int data=0;
struct listnode*temp;
if(isemptyqueue(q))
{
	printf("Queue is empty\n");
	return 0;
}
else
{
	temp=q->front;
	data=q->front->data;
	q->front=q->front->next;
	free(temp);
}
return data;
}
int main()
{
	
	//struct queu*que;
struct queu*q=createqueue();

enqueue(q,5);
//printf("here\n");
enqueue(q,7);
enqueue(q,9);
enqueue(q,11);
enqueue(q,13);
enqueue(q,15);
dequeue(q);
	printf("%d\n",dequeue(q));
	return 0;
}
