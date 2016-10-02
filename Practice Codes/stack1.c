#include<stdio.h>
#define max 20

int s[max];
int top=0;

void push(int);
int pop();
void display(); 

int main(){
	int a,b,c=1,d;
	while(c)
	{
		printf("1.push\n2.pop\n3.display\n4.quit\n");
		scanf("%d",&a);
		
		switch(a){
	
	case 1:   printf("Enter the element to be pushed: ");
	scanf("%d",&b);
	push(b);
	if(top<20)
	printf("Element pushed to stack\n");
	break;
	case 2: d=pop();
	if(d==-1)
	printf("Stack underflow\n");
	else  
	printf("The element popped is %d\n",d);
	break;	
	case 3: display();
	break;
	case 4: c=0; 	
		break;
		default : printf("...Invalid Entry....\n\n"); 	
		break;	
	}
		
	}
	return 0;
}

void push(int x){
	if(top==20)
	{
	printf("Stack overflow\n");
	return;
	}
	else
	s[top++]=x;
}

 int pop(){
 	if(top==-1)
 	return -1;
 	else
 	return s[--top];
  }
 
 void display()
 { int i;
 	for(i=0;i<top;i++)
 	printf("%d\t",s[i]);
 	
 	printf("\n");
 }
