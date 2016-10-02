#include <iostream>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <climits>
#include <ctime>
#include <algorithm>
#include <functional>
#include <stack>
#include <queue>
#include <list>
#include <deque>
#include <sys/time.h>
#include <iomanip>
#include <cstdarg>
#include <utility> //std::pair
#include <cassert>
#define tr(c,i) for(auto i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define log2(x) (log(x)/log(2))
#define ARRAY_SIZE(arr) (1[&arr]-arr)      
#define lld long long int
#define MOD 1000000007
using namespace std;
 
 
 
 
lld expo(lld a, lld n, lld m)
{
	if(n==0)
		return 1;
	lld p=expo(a,n/2,m);
	if(n%2==0)
		return (p*p)%m;
	else
		return (((p*p)%m)*a)%m;
}
 
lld inverse_modulo(lld a, lld m)
{
	return expo(a,m-2,m);
}
 
lld combi(lld n, lld k,lld m)
{
	if(n<k)
		return 0;
	if(n-k<k)
		return combi(n,n-k,m);
	lld i,p=1,t=1;
	for(i=n-k+1;i<=n;i++)
		p=(p*i)%m;
	for(i=1;i<=k;i++)
		t=(t*i)%m;
	return (p*inverse_modulo(t,m))%m;
}
 
lld lucas(lld n, lld k, lld m)
{
	if(n<k)
		return 0;
	if(k==0 || n==k)
		return 1;
	return (lucas(n/m,k/m,m)*combi(n%m,k%m,m))%m;
}
 
 
int main()
{
	int t;
	long long n,l,r,ans,net;
	for(cin>>t;t--;)
	{
 
		cin>>n>>l>>r;
		net = (r-l+1);
		
		if(net < n)
			ans = lucas(net + n, net,1000003);
		else
			ans = lucas(net + n, n,1000003);
		ans--;
		if(ans==-1)
		ans=1000002;
		cout<<ans<<"\n";
	}
	return 0;
} 
