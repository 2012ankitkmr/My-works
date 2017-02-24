#include<bits/stdc++.h>
using namespace std;
#define gl(i,L,R) for (int i = L; i < R; i++) //next four are for "for loops"
#define ge(i,L,R) for (int i = L; i <= R; i++)
#define get1(a) scanf("%lld", &a) //next three are handy ways to get ints, it's also force you to use '&' sign
#define get2(a,b) scanf("%lld%lld", &a, &b)
#define get3(a,b,c) scanf("%d%d%d", &a, &b, &c)
#define pn printf("\n");
#define put1n(x) printf("%lld\n",x);
#define put1(x) printf("%lld",x);
#define put2(x,y) printf("%lld %lld",x,y);
#define put2n(x,y) printf("%lld %lld\n",x,y);
#define putss(s)   printf("%s",s);
#define putc(s)   printf("%c",s);
#define getS(x) scanf(" %s", x) //get a char* string
#define ms(a, v) memset(a, v, sizeof(a)) //set elements of array to some value
#define ll long long //data types used often, but you don't want to type them time by time
#define SZ(x) ((ll)((x).size()))
#define IOS ios_base::sync_with_stdio(0); //to synchronize the input of cin and scanf
#define INF  (long long int)1e9
//for map, pair
#define mp make_pair
#define fi first
#define se second
// for debug
namespace ank{

inline void show(ll n) { printf("%lld\n",n); }

}
#define printA(a,L,R) ge(i,L,R) cout << a[i] << (i==R?'\n':' ')
//for vectors
#define pb push_back
typedef vector<int> vec; 
typedef vector<vec> vv; 
typedef pair<int,int> ii; 
// directions
const int fx[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
const int fxx[8][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};
#define inf INT_MAX
#define mn INT_MIN
#define MOD 1000000007
#define MAXN 10000

#define D 0
#define Sm 0

ll dp[1003];
ll n,m,l;
ll a[1003],b[1003],p[1003];

ll ans;

ll compute(ll pos,ll st,ll la,ll cost)
{
	if(st>l)
	return INT_MAX;
	if(cost>m)
	{
		return  INT_MAX;
	}
	
	if((st<=l)&&(la>=l))
	{
		return cost;
	}

if(dp[pos]!=-1)
return dp[pos];
ll ret = 1e18;
for(int i= pos+1;i<=n;i++)
{
ret =min(ret,compute(i,st+a[i],la+b[i],cost+p[i]));	
}
return dp[pos]=ret;
}

int main()
{
//	freopen("in.txt","r+",stdin);
	if(!D)
	{
		if(Sm)
		freopen("D-small-attempt1.in","r+",stdin);
		else
		freopen("D-large-practice.in","r+",stdin);
	
		freopen("out.txt","w+",stdout);
	}
	int t;
	scanf("%d",&t);
	for(int test = 1;test<=t;test++)
	{
	
	scanf("%lld%lld%lld",&n,&m,&l);
	
for(int i =1;i<=n;i++)
scanf("%lld%lld%lld",&a[i],&b[i],&p[i]);
memset(dp,-1,sizeof dp);
		ans = compute(0,0,0,0);
		
		if(ans==1e18)
		printf("Case #%d: IMPOSSIBLE\n",test);
		else
		printf("Case #%d: %d\n",test,ans);
	}
		
	return  0;
}
