#include <bits/stdc++.h>
 
using namespace std;
#define ll long long int
#define MAX (1+(1<<10))
#define M 1000000007
 
int type;
  char flag[MAX];
 
	int tree[MAX];
    int lazy1[MAX];
    int lazy2[MAX];
  //  int res;
 void build_tree(int node, int a, int b, int arr[]) {
   	if(a > b) return; 
  	if(a == b) { // Leaf node
    		tree[node] = arr[a]; // Init value    		
		return;
	}
 
	build_tree(node*2, a, (a+b)/2, arr); // Init left child
	build_tree(node*2+1, 1+(a+b)/2, b, arr); // Init right child
 
	tree[node] = (tree[node*2] + tree[node*2+1])%M; // Init root value
}
/**
 * Increment elements within range [i, j] with value value
 */
void update_tree(int node, int a, int b, int i, int j, int value) {
 
 
	  		if((lazy1[node] != 0 || lazy2[node] != 1) && flag[node] == '0') { // This node needs to be updated
	   		tree[node] = ((tree[node]*lazy2[node])%M + (((b-a+1)*lazy1[node])%M))%M; // Update it
 
			if(a != b) {
				lazy1[node*2] = (lazy1[node*2] +lazy1[node])%M; // Mark child as lazy
	    			lazy1[node*2+1] = (lazy1[node*2+1] +lazy1[node])%M; // Mark child as lazy
	    			lazy2[node*2] = (lazy2[node*2] *lazy2[node])%M; // Mark child as lazy
	    			lazy2[node*2+1] = (lazy2[node*2+1] *lazy2[node])%M;
			}
 
	   		lazy1[node] = 0; // Reset it
	   		lazy2[node] = 1;
	  	}
	  	else if(lazy1[node] != 0 && flag[node] == '1')
	  	{
	  		tree[node] = lazy1[node];
	  		if(a != b) {
				lazy1[node*2] = lazy1[node*2+1] = lazy1[node]; // Mark child as lazy	    			
	    		lazy2[node*2] = lazy2[node*2+1] = 1; // Mark child as lazy
	    		flag[node*2] = flag[node*2+1] = '1';
			}
	 		flag[node] = '0';
	  		lazy1[node] = 0; // Reset it
	   		lazy2[node] = 1;
	  	}
 
		if(a > b || a > j || b < i) // Current segment is not within range [i, j]
			return;
 
	  	if(a >= i && b <= j) { // Segment is fully within range
	  		if(type == 1)
	  		{
		  			tree[node] = (tree[node] +((b-a+1)*value)%M)%M;
 
				if(a != b) { // Not leaf node
					lazy1[node*2] = (lazy1[node*2] +value)%M;
					lazy1[node*2+1] = (lazy1[node*2+1] +value)%M;
				}
	  		}
	    	if(type == 2)
	    	{
	    		tree[node] = (tree[node] *value)%M;
 
				if(a != b) { // Not leaf node
					lazy1[node*2] = (lazy1[node*2] *value)%M;
					lazy1[node*2+1] = (lazy1[node*2+1] *value)%M;
					lazy2[node*2] = (lazy2[node*2] *value)%M;
					lazy2[node*2+1] = (lazy2[node*2+1] *value)%M;
				}
	    	}	
	 		if(type == 3)
	 		{
	 			tree[node] = value;
	 			if(a!=b)
	 			{
	 				lazy1[node*2] = lazy1[node*2+1] = value;
	 				lazy2[node*2] = lazy2[node*2+1] = 1;
	 				flag[node*2] = flag[node*2 +1] = '1';
	 			}
	 		}
  	}
  	if(a!=b)
  	{
  		update_tree(node*2, a, (a+b)/2, i, j, value); // Updating left child
	update_tree(1+node*2, 1+(a+b)/2, b, i, j, value); // Updating right child 
	tree[node] = (tree[node*2] + tree[node*2+1])%M; // Updating root with max value
 
  	}
}
 
/**
 * Query tree to get max element value within range [i, j]
 */
int query_tree(int node, int a, int b, int i, int j) 
{
	if(a > b || a > j || b < i)
		return 0;
	if((lazy1[node] != 0 || lazy2[node] != 1) && flag[node] == '0') { // This node needs to be updated
	   		tree[node] = ((tree[node]*lazy2[node])%M + ((b-a+1)*lazy1[node])%M)%M; // Update it
 
			if(a != b) {
				lazy1[node*2] = (lazy1[node*2] +lazy1[node])%M; // Mark child as lazy
	    			lazy1[node*2+1] = (lazy1[node*2+1] +lazy1[node])%M; // Mark child as lazy
	    			lazy2[node*2] = (lazy2[node*2] *lazy2[node])%M; // Mark child as lazy
	    			lazy2[node*2+1] = (lazy2[node*2+1] *lazy2[node])%M;
			}
 
	   		lazy1[node] = 0; // Reset it
	   		lazy2[node] = 1;
	  	}
	  	else if(lazy1[node] != 0 && flag[node] == '1')
	  	{
	  		tree[node] = lazy1[node];
	  		if(a != b) {
				lazy1[node*2] = lazy1[node*2+1] = lazy1[node]; // Mark child as lazy	    			
	    		lazy2[node*2] = lazy2[node*2+1] = 1; // Mark child as lazy
	    		flag[node*2] = flag[node*2+1] = '1';
			}
	 		flag[node] = '0';
	  		lazy1[node] = 0; // Reset it
	   		lazy2[node] = 1;
	  	}
 
	if(a >= i && b <= j) // Current segment is totally within range [i, j]
	{
		 return tree[node];
 
	}
 
 	if(a!=b)
 	{
 		int q1 = query_tree(node*2, a, (a+b)/2, i, j); // Query left child
	int q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j); // Query right child
 
	int res = (q1+ q2)%M; // Return final result
	return res;
 	}
	else
		return tree[node];
 
}
int main()
{
	ios::sync_with_stdio(false);
	int N,v,Q,i,x,y;
	cin>>N>>Q;
	int arr[N];  
	for(i=0;i<N;i++)
	{
		cin>>arr[i];
	}
	memset(lazy1, 0, sizeof(lazy1));
	memset(lazy2, 1, sizeof(lazy2));
	memset(flag, '0', sizeof(flag));
	memset(tree, 0, sizeof(tree));
	build_tree(1, 0, N-1, arr); 
 
	while(Q--)
	{			
		cin>>type>>x>>y>>v;
		if(type!=4)
			update_tree(1, 0, N-1, x-1, y-1, v);
 
		else
		{
			cout<<query_tree(1, 0, N-1, x-1, y-1)<<"\n";
 
		}
 
	}
	for(int k=1;k<10;k++)
		cout<<tree[k]<<"\n";
	return 0;
}
