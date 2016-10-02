#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int pq[MAX];
int p[MAX];
int f=0,r=-1,t=-1;


void insert(int);
void prioritize(int);
void del();

void display();
void quicksort(int a[],int l,int r)
{    if(r>l){
    int i, v, t,j;
 
        v = a[r];
        i = l-1;
        j = r;
 
        for(;;)
       {
            while (a[++i] < v);
            while (a[--j] > v);
 
            if(i >= j) break;
            t = a[i]; a[i] = a[j]; a[j] = t;
 t = pq[i]; pq[i] = pq[j]; pq[j] = t;
 
       }
 
 
    t = a[i];
	a[i] = a[r];
	a[r] = t;

 t = pq[i];
	pq[i] = pq[r];
	pq[r] = t;

 
    quicksort(a, l, i - 1);
    quicksort(a, i + 1, r);
 
  }
  else
return;
 }


int main()
{
	int ch,pr,item;
	printf("1.Insert an element into queue\n2.Delete an element from queue\n3.Display\n4.Exit\n");
	while(1)
	{
		printf("Enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:	printf("Enter the element : ");
		scanf("%d",&item);
		insert(item);
		printf("Enter the priority : ");
		scanf("%d",&pr);
		prioritize(pr);
		break;	
		case 2:del();
		break;
		case 3:
		display();
		break;
		case 4: exit(0);
		break;
		default: printf("Invalid Selection\n");	
			
		}
	}
return 0;
}

void insert(int item)
{
	pq[++r]=item;
}
void prioritize(int s)
{
	p[++t]=s;
}

void del(){
quicksort(p,f,t);
f++;

}

void display()
{
	int i;
	for(i=f;i<=r;i++)
	printf("%d\t",pq[i]);
	printf("\n");
}
