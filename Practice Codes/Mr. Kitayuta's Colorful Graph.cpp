
#include<bits/stdc++.h>
#include<unistd.h>
#define REP(i,m) for(int i=0;i<(m);++i)
#define REPN(i,m,in) for(int i=(in);i<(m);++i)
#define ALL(t) (t).begin(),(t).end()
#define CLR(a) memset((a),0,sizeof(a))
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
 
using namespace std;
 
 
#ifdef DEB
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
#else
#define dump(x) ;
#define prl ;
template<class T> void debug(T a,T b){ ;}
#endif
 
template<class T> void chmin(T& a,const T& b) { if(a>b) a=b; }
template<class T> void chmax(T& a,const T& b) { if(a<b) a=b; }
 
typedef long long int lint;
typedef pair<int,int> pi;
 
namespace std{
	template<class S,class T>
	ostream &operator <<(ostream& out,const pair<S,T>& a){
		out<<'('<<a.fr<<','<<a.sc<<')';
		return out;
	}
}
 
//const int INF=5e8;
 
int n,m;
 
vector<pi> g[105];
 
int vis[105];
 
bool dfs(int v,int col,int dst){
	vis[v]=1;
	if(v==dst) return 1;
	REP(i,g[v].size()){
		pi e=g[v][i];
		if(e.sc==col && !vis[e.fr]){
			if(dfs(e.fr,col,dst)) return true;
		}
	}
	return false;
}
int  main(){
	cin>>n>>m;
	REP(i,m){
		int a,b,c;cin>>a>>b>>c;--a;--b;--c;
		g[a].pb(mp(b,c));
		g[b].pb(mp(a,c));
	}
	int q;cin>>q;
	REP(hoge,q){
		int res=0;
		int u,v;cin>>u>>v;--u;--v;
		REP(i,100){
			CLR(vis);
			if(dfs(u,i,v)) ++res;
		}
		cout<<res<<endl;
	}
 
 
	return 0;
}
