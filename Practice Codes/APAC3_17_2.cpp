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

#define D 0
#define Sm 0


int min(int a, int b, int c) {
	int temp;
	temp = a;
	if(b < a) {
		temp = b;
	}
	if(c < temp) {
		temp = c;
	}
	return temp;
}


int m,n,k;
int a[3003][3003], dp[3003][3003];
ll r,c;
int main()
{

	if(!D)
	{
		if(Sm)
		freopen("B-small-attempt0.in","r+",stdin);
		else
		freopen("B-large.in","r+",stdin);
		freopen("out.txt","w+",stdout);
	}
	else
	freopen("in.txt","r+",stdin);
	int t;
	
	scanf("%d",&t);
	for(int test = 1;test<=t;test++)
	{
		
		scanf("%d %d %d", &m, &n,&k);
	gl(i,0,m)gl(j,0,n)a[i][j]=1;
	gl(i,0,k){
	get2(r,c);
	a[r][c]=0;
}
		
		for(int i = 0; i < m; i++) {
			for(int j = 0; j < n; j++) {
				if(i == 0 || j == 0) {
					dp[i][j] = a[i][j];
				}
			}
		}
		for(int i = 1; i < m; i++) {
			for(int j = 1; j < n; j++) {
				if(a[i][j] == 1) {
					
					dp[i][j] = min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1;
				}
				else {
					dp[i][j] = 0;
				}
				
			}
		}
		int sum=0;
		for(int i = 0; i < m; i++) {
			for(int j = 0; j < n; j++) {
//				printf("%d ",dp[i][j]);
	sum+=dp[i][j];
			}
//		printf("\n");
		}
		printf("Case #%d: %d\n",test,sum);
	}
		
	return  0;
}
