#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long long lli;
typedef pair <int,int> pii;
typedef vector <int> vi;

#define rep(i, n) for(int i = 0; i < (n); ++i)
#define forn(i, a, b) for(int i = (a); i < (b); ++i)
#define ford(i, a, b) for(int i = (a); i >= (b); --i)
#define fore(i, a, b) forn(i, a, b + 1)

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(c) c.begin(), c.end()
#define mset(a, v) memset(a, v, sizeof(a))
#define sz(a) ((int)a.size())

#define gi(x) scanf("%d", &x)
#define pis(x) printf("%d ", x)
#define pin(x) printf("%d\n", x)
#define pnl printf("\n")
#define dbn cerr << "\n"
#define dbg(x) cerr << #x << " : " << (x) << " "
#define dbs(x) cerr << (x) << " "

#define foreach(c, it) for(__typeof(c.begin()) it = c.begin(); it != c.end(); ++it)

#define dbg(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class T> void dbs(string str, T t) {
    cerr << str << " : " << t << "\n";
}
template <class T, class... S> void dbs(string str, T t, S... s) {
    int idx = str.find(',');
    cerr << str.substr(0, idx) << " : " << t << ",";
    dbs(str.substr(idx + 1), s...);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
