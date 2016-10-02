// Source : Code taken from http://s...content-available-to-author-only...t.in/2012/12/segment-trees-and-lazy-propagation.html
 
 
#include<iostream>
#include<algorithm>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<math.h>
 
#define NN 100010
#define MAXX 2*100010+1
#define inf 0x7fffffff
#define MIN(x,y) ((x)<(y)?(x):(y))
 
#define MAX(x,y) ((x)>(y)?(x):(y))
long long int prevx,prevy;
long long int arr[NN];
long long int tree[MAXX];
 
/**
 * Build and init tree
 */
void build_tree(long long int node, long long int a, long long int b) {
    if(a > b) return; // Out of range
 
  	if(a == b) { // Leaf node
    		tree[node] = arr[a]; // Init value
		return;
	}
 
	build_tree(node*2, a, (a+b)/2); // Init left child
	build_tree(node*2+1, 1+(a+b)/2, b); // Init right child
 
	tree[node] = max(tree[node*2], tree[node*2+1]); // Init root value
}
 
/**
 * Increment elements within range [i, j] with value value
 */
void update_tree(long long int node, long long int a, long long int b, long long int i, long long int j, long long int value) {
 
	if(a > b || a > j || b < i) // Current segment is not within range [i, j]
		return;
 
  	if(a == b) { // Leaf node
    		tree[node] += value;
    		return;
	}
 
	update_tree(node*2, a, (a+b)/2, i, j, value); // Updating left child
	update_tree(1+node*2, 1+(a+b)/2, b, i, j, value); // Updating right child
 
	tree[node] = max(tree[node*2], tree[node*2+1]); // Updating root with max value
}
 
/**
 * Query tree to get max element value within range [i, j]
 */
long long int query_tree(long long int node, long long int a, long long int b, long long int i, long long int j) {
 
	if(a > b || a > j || b < i) return -inf; // Out of range
 
	if(a >= i && b <= j) // Current segment is totally within range [i, j]
		return tree[node];
 
	long long int q1 = query_tree(node*2, a, (a+b)/2, i, j); // Query left child
	long long int q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j); // Query right child
 
	long long int res = max(q1, q2); // Return final result
 
	return res;
}
 
int main()
{
	long long int j,ans,max,temp,n,i,m,x[100005],y[100005];
scanf("%lld",&n);
for(i=0;i<n;i++)
{
scanf("%lld",&arr[i]);	
}
build_tree(1, 0, n-1);
scanf("%lld%lld%lld",&m,&x[0],&y[0]);
 
 
for(i=1;i<m;i++)
{
	x[i]=(x[i-1]+7)%(n-1);
    y[i]=(y[i-1]+11)%(n);
}
 
if(x[0]>y[0])
{
	temp=x[0];
	x[0]=y[0];
	y[0]=temp;
}
 
ans=0;
for(i=0;i<m;i++)
{
		if(x[i]>y[i])
		{
				temp=x[i];
	x[i]=y[i];
	y[i]=temp;
		}
		if(x[i]!=y[i])
		max=query_tree(1, 0, n-1,x[i],y[i]);
		else
		max=arr[x[i]];
 // printf("max=%ld\n",max);
//	printf("max=%ld\n",max);
	ans=ans+max;
}
printf("%lld",ans);
	return 0;
} 
