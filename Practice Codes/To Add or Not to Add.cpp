#include<bits/stdc++.h>
using namespace std;

vector<long long > a ;
vector<long long> prefixsum(100005 , 0);

long long binarysearch(long long low , long long  high ,long long   k ,long long  reference , long long  ind)
{
	long long mid = ( high + low)>>1;
	if(high >= low)
	{
		
		long long sumk = (ind - mid) * reference - (prefixsum[mid] - prefixsum[ind]);
		if(sumk<=k)
		{
		//	printf("sum = %d\n",sumk);
			if(mid>0)
			{
					long long sumk_1 = (ind - (mid-1)) * reference - (prefixsum[mid-1] - prefixsum[ind]);
					if( sumk_1 > k)
					return mid;
					else if( sumk_1 == k )
					{
						return binarysearch(low , mid-1 , k, reference ,ind);
					}
				
			}
			else
			return mid;
			
		}
	    if(sumk < k)
		return binarysearch(low , mid , k ,reference , ind);
		
		else if(sumk > k)
		return binarysearch(mid+1 , high , k ,reference , ind);
	}	
	return 0;
}



int main()
{
//	freopen("in.txt","r",stdin);
	long long n , k , cnt , min_num , max_cnt = -1111111111 , min_left_pointer ,temp;
	cin >> n >> k;
	
	
	for(int i = 0 ; i < n ; i++ )
	{
		cin>>temp;
		a.push_back(temp);
	}
	
	sort(a.begin(),a.end());
	
	for(int i = n - 1 ; i >= 0 ; i--)
	{
		prefixsum[i] = a[i] + prefixsum[i + 1];
	}
	
	for(int i = n-1 ; i >= 0 ; i--)
	{
	min_left_pointer = binarysearch(0 , i , k , a[i] , i );
	//printf("left = %d\n",min_left_pointer);


    if( max_cnt <= (i - min_left_pointer + 1) )	
	{
		min_num = a[i];
		max_cnt = i - min_left_pointer + 1;
	}	
	}
	
	cout<<max_cnt<<" "<<min_num<<endl;
	//printf("%d %d\n", max_cnt,min_num);
	return 0;
}
