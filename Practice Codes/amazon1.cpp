#include<bits/stdc++.h>
using namespace std;

int main()
{
	int arr[]={8,7,6,7, 6, 5, 4 ,3, 2, 3, 4, 3};
	int k=3,n=12;
	
	int ans_index=0;
	for(int i=0;i<n;)
	{
		if(arr[i]==k)
		{
		ans_index=i;	
			break;
		}
		i+=abs(arr[i]-k);//expected_index
		
	}
	printf("%d\n",ans_index);
	return  0;
}
