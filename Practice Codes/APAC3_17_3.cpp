#include<bits/stdc++.h>
using namespace std;
#define gl(i,L,R) for (int i = L; i < R; i++) //next four are for "for loops"
#define ge(i,L,R) for (int i = L; i <= R; i++)
#define get1(a) scanf("%lld", &a) //next three are handy ways to get ints, it's also force you to use '&' sign
#define get2(a,b) scanf("%lld%lld", &a, &b)
#define get3(a,b,c) scanf("%lld%lld%lld", &a, &b, &c)
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

#define D 1
#define Sm 1
map<string> variable;
int main()
{
	if(!D)
	{
		if(Sm)
		freopen("C-small-attempt0.in","r+",stdin);
		else
		freopen("C-large-attempt0.in","r+",stdin);
		freopen("out.txt","w+",stdout);
	}
	int t;
	scanf("%d",&t);
	
	ll n;
	string s;
	for(int test = 1;test<=t;test++)
	{
		get1(n);
		getchar();
		gl(i,0,n)
		{
			cin>>s;
		}
	
		
		
		
		
		printf("Case #%d: ",test);
	}
		
	return  0;
}
