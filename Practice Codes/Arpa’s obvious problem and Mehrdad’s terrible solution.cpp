#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long 

ll a,cnt[200005];

int main(){
	ll n, x; cin >> n >> x;
	ll ans = 0;
	for (int i = 0;i < n;i++){
		 cin >> a;
		ans += cnt[x ^ a];

		cnt[a] ++;
	}

	cout << ans ;
return 0;
}
