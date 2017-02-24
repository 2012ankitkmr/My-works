#include<bits/stdc++.h>

using namespace std;

#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
#define eps 1e-9
#define sqr(x) ((x)*(x))
#define SET(a,b) memset((a),(b),sizeof((a)))
#define pw(x) (1ll<<(x))
#define buli(x) __builtin_popcountll(x)
#define endl "\n"

const int MOD = 1e9+7;

typedef long long ll;
typedef vector<int> vi;
typedef map<int,int> mii;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

inline bool EQ(double a,double b) { return fabs(a - b) < 1e-9; }
inline void set_bit(int & n, int b) { n |= pw(b); }
inline void unset_bit(int & n, int b) { n &= ~pw(b); }

inline void check(ll &x) {
	if(x>=MOD)
		x%=MOD;
}
ll ar[25];
int main() {
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		vector<ll> v;
		for(int i=0;i<n;i++) cin>>ar[i];
		if(n%2==1) {
			if(n==1) {
				if(ar[0]==1) {
					v.pb(1);
					v.pb(1);
				}
				else {
					v.pb(1);
					v.pb(1);
					v.pb(ar[0]-1);
				}
			}
			else {
				for(int i=0;i<n-2;i++) v.pb(ar[i]);
				if(ar[n-2]==1) {
					v[sz(v)-1]++;
					v.pb(1);
					v.pb(ar[n-1]-1);
					if(v.back()==0) v.pop_back();
				}
				else {
					v.pb(ar[n-2]-1);
					v.pb(1);
					v.pb(1);
					v.pb(ar[n-1]-1);
					if(v.back()==0) v.pop_back();
				}
			}
		}
		else {
			if(n==2) {
				v.pb(1);
				v.pb(ar[1]+1);
				v.pb(ar[0]-1);
				if(v.back()==0) v.pop_back();
			}
			else {
				for(int i=0;i<n-3;i++) v.pb(ar[i]);
				if(ar[n-3]==1) v[sz(v)-1]++;
				else v.pb(ar[n-3]-1),v.pb(1);
				if(ar[n-2]==1) {
					v.pb(1+ar[n-1]);
				}
				else {
					v.pb(1+ar[n-1]);
					v.pb(ar[n-2]-1);
				}
			}
		}
		cout<<sz(v)<<endl;
		for(int i=0;i<sz(v);i++) cout<<v[i]<<" ";
		cout<<endl;
	}
	return 0;
}
