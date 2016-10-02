#include<bits/stdc++.h>

int a[500];
int max(int a,int b)
{
	return a>b?a:b;
	}
int min(int a,int b)
{
	return a>b?b:a;
}	
int game(int i,int j)
{
	if((j-i)==1)
	return a[i]>a[j]?a[i]:a[j];
return max(min(game(i+1,j-1),game(i+2,j))+a[i],min(game(i,j-2),game(i+1,j-1))+a[j]);	
	
}
int main()
{
	int n;
	scanf("%d",&n);
	if(!n%2)
	{
	printf("Invalid no.\nEnter an even number\n");
scanf("%d",&n);
}
int i;
for(i=0;i<n;i++)
scanf("%d",&a[i]);

printf("ans=%d\n",game(1,n));
	return 0;	
}

