#include<stdio.h>
void fact(short int);
void print(void);
short int a[79],len;

int main(){
	int t,i,b;
	scanf("%d",&t);
	for(i=0;i<t;i++){
		scanf("%d",&b);
		fact(b);
		print();	
	}
	return 0;	
}

void fact(short int n){
	short int j,m,temp=0,x;
	for(j=1;j<99;j++)
	a[j]=0;
	
	a[0]=1;
	len=1;
	for(j=2;j<=n;j++){
		m=0;
	while(m<len){
		x=temp+a[m]*j;
		a[m]=x%100;
		temp=x/100;
		m++;
		}
		while(temp>0){
			a[m]=temp%100;
			temp/=100;
		m++;
        len++;
		}
		}
	}
void print(void)
{short int k;

printf("%d",a[len-1]);

for(k=len-2;k>=0;k--){
	if(a[k]>9)
	printf("%d",a[k]);
	else
	printf("0%d",a[k]);
}
printf("\n");	
}
