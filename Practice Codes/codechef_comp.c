#include<stdio.h>

int main(){
	int a,i,j,flag;
	long int b;
	flag=0;
	scanf("%d",&a);
	scanf("%d",&b);
	long int c[100][100];
	for(i=0;i<a;i++){
		for(j=0;j<a;j++)
		{scanf("%d",&c[i][j]);	
		}
	}
	
	for(i=0;i<a;i++){
		for(j=0;j<a;j++){
			if(b==c[i][j])
			{flag=1;
				break;
			}
			if(c[i][j]>b)
			break;
	}
		if(flag==1){
			break;
		}
	}
	if(flag==0)
	printf("NO");
	else 
	printf("YES");
	return 0;
}
