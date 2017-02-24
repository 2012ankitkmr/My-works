#include<bits/stdc++.h>
using namespace std;

int main()
{
	int w;
	scanf("%d",&w);
	if(w==2)
	w++;
	if(w&1)
	printf("NO");
	else
	printf("YES");
	
	return 0;
}
