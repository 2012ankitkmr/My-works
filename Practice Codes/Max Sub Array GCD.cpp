#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<N;i++)
#define fori(i,a,b) for(int i=a,_b=b;i<=_b;i++)
#define ford(i,a,b) for(int i=a,_b=b;i>=_b;i--)
#define foreach(it,a) for(__typeof(a.begin()) it=a.begin(); it!=a.end(); ++it)
#define outarray(a,n) REP(i,n) cout << a[i] << ' '
#define outarray(a,x,y) fori(i,x,y) cout << a[i]
#define openread(s) freopen(s,"r",stdin)
#define openwrite(s) freopen(s,"w",stdout)
#define pb push_back
#define sqr(a) (a)*(a)
#define mp(x,y) make_pair(x,y)
#define pb push_back
#define fi first
#define	se second
#define endl "\n"
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;
const double eps=1e-8;
const ll lloo=1e18;
const int oo=1e9;
 
 
const int MAXN=5e5+100;
const int MAXP=1048576+100;
 
int rmq[MAXN][19];
int lg2[MAXP];
int a[MAXN];
int n,k;
 
void init() {
    rep(j,n) rmq[j][0]=a[j];
    fori(i,1,18) {
        if ((1<<i)>n) break;
        rep(j,n-(1<<i)+1) {
            rmq[j][i]=__gcd(rmq[j][i-1],rmq[j+(1<<(i-1))][i-1]);
        }
    }
}
 
int get(int l, int r) {
    int x=lg2[r-l+1];
    return __gcd(rmq[l][x],rmq[r-(1<<x)+1][x]);
}
 
int main(){
//    openread("test.inp");
    ios_base::sync_with_stdio(0);
    fori(i,0,19) {
        fori(j,(1<<i),(1<<(i+1))-1) lg2[j]=i;
    }
    cin >> n >> k;
//n=5e5;
    rep(i,n) {
        cin >> a[i];
//        a[i]=1e6;
    }
    init();
    int r=0;
    int res=0;
    rep(l,n) {
        while (r<n) {
            if (get(l,r)>=k) r++;
            else break;
        }
        res=max(res,r-l);
    }
    cout << res << endl;
}
