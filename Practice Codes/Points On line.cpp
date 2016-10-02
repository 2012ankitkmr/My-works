#include<bits/stdc++.h>
using namespace std;

int a[100005];

int main()
{
	int d , n;
	scanf("%d%d",&n,&d);
	for(int i = 0 ; i < n ; i++ )
	scanf("%d",&a[i]);
	if(n<=2)
	{
	printf("0\n");
	return 0;
}
	
	long long ans = 0,k;
	int first_pointer = 0 ,second_pointer = 2 ;
	while(1)
	{
		
		
		if(a[second_pointer]-a[first_pointer]<=d)
		{
			k = (long long)second_pointer-(long long)first_pointer;
			k=k*(k-1);
			if(second_pointer-first_pointer>=2)
			ans+=(k/2);
			second_pointer++;
	
		}
		else
		first_pointer++;
				
		if(second_pointer==n)
		break;
	}
	cout<<ans;
	return 0;
}
