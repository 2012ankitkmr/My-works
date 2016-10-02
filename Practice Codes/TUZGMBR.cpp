#include<bits/stdc++.h>
using namespace std;

int main()
{
	int test,t,n,m,parity_col,parity_row;
	scanf("%d",&test);
	for(int t=0;t<test;t++)
	{
	parity_row=0,parity_col=0;
	scanf("%d%d",&n,&m);	
	parity_row=((n+1)/3)&1;
	parity_col=(m/2)&1;
	if(parity_row^parity_col)
	printf("Tuzik\n");
	else
	printf("Vanya\n");
	}
	
	return  0;
}
