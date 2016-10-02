#include<bits/stdc++.h>
using namespace std;

int main()
{
	int arr[] = { 1,2,3,4,5,6};
	
	do{
		for(int i = 0; i < 6;i++)
		printf("%d ",arr[i]);
		printf("\n");
		if(arr[0]==4)
		break;
	}while(next_permutation(arr,arr+6));
	
	return 0;
}
