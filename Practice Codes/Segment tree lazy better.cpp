#include <iostream>
#include <cmath>
#include <vector>
#include <string>
 
using namespace std;
 
struct Node
{
	int updates;
	int l, r, mid;
	int counts[10];
	Node()
	{
		updates = 0;
		for (int i = 0; i < 10; ++i)
		{
			counts[i] = 0;
		}
	}
} *A;
 
void constructTree(int l, int r, int index)
{
 
	A[index].l = l;
	A[index].r = r;
	int mid = (l + r) / 2;
	A[index].mid = mid;
	if(l == r)
	{
		A[index].counts[0] = 1;
		return;
	}
	constructTree(l, mid, 2*index + 1);
	constructTree(mid+1, r, 2*index + 2);
	for(int i = 0; i < 10; i++)
	{
		A[index].counts[i] = A[2*index+1].counts[i] + A[2*index+2].counts[i];
	}
}
 
void updateTree(int l, int r, int index)
{
	if(l == A[index].l && r == A[index].r)
	{
		A[index].updates++;
		int B[10];
		for(int j = 0; j < 10; j++)
			B[j] = A[index].counts[j];
		for(int i = 0; i < 10; i++)
		{
			A[index].counts[(i + 1)%10] = B[i];
		}
	}
	else if(l > A[index].mid)
	{
		updateTree(l, r, 2*index+2);
		for(int i = 0; i < 10; i++)
		{
			A[index].counts[(i + A[index].updates)%10] = A[2*index+1].counts[i] + A[2*index+2].counts[i];
		}
	}
 
	else if(r <= A[index].mid)
	{
		updateTree(l, r, 2*index+1);
		for(int i = 0; i < 10; i++)
		{
			A[index].counts[(i + A[index].updates)%10] = A[2*index+1].counts[i] + A[2*index+2].counts[i];
		}
	}
	else 
	{
		updateTree(l, A[index].mid, 2*index+1);
		updateTree(A[index].mid+1, r, 2*index+2);
		for(int i = 0; i < 10; i++)
		{
			A[index].counts[(i + A[index].updates)%10] = A[2*index+1].counts[i] + A[2*index+2].counts[i];
		}
	}
}
 
int* getCounts(int l, int r, int index)
{
	if(l == A[index].l && r == A[index].r)
	{
		return A[index].counts;
	}
	else if(l > A[index].mid)
	{
		int *P = getCounts(l, r, 2*index+2);
		int *R = new int[10];
		for(int i = 0; i < 10; i++)
		{
			R[(i+A[index].updates) % 10] = P[i];
		}
		return R;
	}
 
	else if(r <= A[index].mid)
	{
		int *P = getCounts(l, r, 2*index+1);
		int *R = new int[10];
		for(int i = 0; i < 10; i++)
		{
			R[(i+A[index].updates) % 10] = P[i];
		}
		return R;
	}
	else 
	{
		int* P = getCounts(l, A[index].mid, 2*index+1);
		int* Q = getCounts(A[index].mid+1, r, 2*index+2);
		int* R = new int[10];
		for(int i = 0; i < 10; i++)
		{
			R[(i+A[index].updates) % 10] = P[i] + Q[i];
		}
		return R;
	}
}
 
void createTree(int n)
{
	int height  = (int) ceil(log2(n + 1));
	int sz = (int)pow(2, height + 1) - 1;
	A = new Node[sz];
	constructTree(0, n, 0);
}
 
int main()
{
	ios::sync_with_stdio(false);
	int N, Q, type, L, R;
	cin>>N>>Q;
	N--;
	createTree(N);
	for(int i = 0; i < Q; i++)
	{
		cin>>type>>L>>R;
		L--;
		R--;
		if(type == 1)
			updateTree(L, R, 0);
		else
		{
			int ans = 0;
			int *res = getCounts(L, R, 0);
			for(int i = 0; i < 10; i++)
			{
				ans+= i*res[i];
			}
			//delete [] res;
			cout<<ans<<endl;
		}
	}
 
	return 0;
} 
 
