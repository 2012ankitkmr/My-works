#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < n; i++)
#define rp(i,a,n) for(int i=a;i<=int(n);i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define sc(x) scanf("%d", &x)
#define F first
#define S second
#define fill(a,b) memset(a,b,sizeof a)
#define N 105
using namespace std;

int n,m,k,ans=1e9+1,storage[1234567],x;
vector<pair<int,int> > v[1234567];
int main()
{
    cin >> n >> m >> k;
    rep(i,m)
    {
        int a,b,d;
        cin >> a >> b >> d;
        v[a].pb(mp(b,d));
        v[b].pb(mp(a,d));
    }
    rep(i,k) { cin >> x; storage[ x ] = 1; }
    rp(i,1,n) if(storage[i]) {
        rep(j,v[i].size()) {
            if(!storage[ v[i][j].F ]) ans=min(ans,v[i][j].S);
        }
    }
    if(ans==1e9+1) cout << -1 << endl;
    else cout << ans << endl;
}
