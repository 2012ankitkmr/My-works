#include<stdio.h>

int main(){
	int n,i,j,p=0;
	scanf("%d",&n);
	int a[n][n];
	
for(i=0;i<n;i++){
	
for(j=0;j<n;j++){
	scanf("%d",&a[i][j]);
}
}
	
	p=0;
for(i=0;i<n;i++)
{
if(p%2==0)
{
for(j=0;j<n;j++)
{printf("%d ",a[j][i]);

}
}
else
for(j=n-1;j>=0;j--)
{printf("%d ",a[j][i]);

}
printf("\n");
p++;
}
	
return 0;
	
}
