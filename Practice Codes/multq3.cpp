#include<bits/stdc++.h>
using namespace std;
#define bit(x,i) (x&(1<<i))  //select the bit of position i of x
#define lowbit(x) ((x)&((x)^((x)-1))) //get the lowest bit of x
#define hBit(msb,n) asm("bsrl %1,%0" : "=r"(msb) : "r"(n)) //get the highest bit of x, maybe the fastest
#define max(a,b) (a<b?b:a)
#define IN(i,l,r) (l<i&&i<r) //the next for are for checking bound
#define LINR(i,l,r) (l<=i&&i<=r)
#define LIN(i,l,r) (l<=i&&i<r)
#define INR(i,l,r) (l<i&&i<=r)
#define gl(i,L,R) for (int i = L; i < R; i++) //next four are for "for loops"
#define ge(i,L,R) for (int i = L; i <= R; i++)
#define grl(i,L,R) for (int i = L; i > R; i--)
#define gre(i,L,R) for (int i = L; i >= R; i--)
#define get1(a) scanf("%ld", &a) //next three are handy ways to get ints, it's also force you to use '&' sign
#define get2(a,b) scanf("%ld%ld", &a, &b)
#define get3(a,b,c) scanf("%ld%ld%ld", &a, &b, &c)
#define wez(n) int (n); scanf("%d",&(n)); //handy if the input is right after the definition of a variable
#define wez2(n,m) int (n),(m); scanf("%d %d",&(n),&(m))
#define wez3(n,m,k) int (n),(m),(k); scanf("%d %d %d",&(n),&(m),&(k))
#define tests wez(testow)while(testow--) //for multilple cases problems
#define pn printf("\n");
#define put1n(x) printf("%ld\n",x);
#define put1(x) printf("%ld",x);
#define put2(x,y) printf("%ld %ld",x,y);
#define put2n(x,y) printf("%ld %ld\n",x,y);
#define putS(s)   printf("%s",s);
#define putc(s)   printf("%c",s);
#define whileZ int T; getI(T); while(T--) // the same as above
#define getS(x) scanf("%s", x) //get a char* string
#define ms(a, v) memset(a, v, sizeof(a)) //set elements of array to some value
#define ch2Int(c) (c-'0')
#define lastEle(vec) vec[vec.size()-1] 
#define SZ(x) ((int)((x).size()))
#define REMAX(a,b) (a)=max((a),(b)); // set a to the maximum of a and b
#define REMIN(a,b) (a)=min((a),(b));
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++) // traverse an STL data structure
#define ALL(c) (c).begin(),(c).end() //handy for function like "sort()"
#define PRESENT(c,x) ((c).find(x) != (c).end()) 
#define CPRESENT(c,x) (find(ALL(c),x) != (c).end()) 
#define ll long long //data types used often, but you don't want to type them time by time
#define ull unsigned long long
#define ui unsigned int
#define us unsigned short
#define IOS ios_base::sync_with_stdio(0); //to synchronize the input of cin and scanf
#define INF  (long long int)1e9
#define PI 3.1415926535897932384626
//for map, pair
#define mp make_pair
#define fi first
#define se second
// for debug
namespace ank{
inline void show(int n) { printf("%d\n",n); }
}
#define DBG(vari) cerr<<#vari<<" = "<<(vari)<<endl;
#define printA(a,L,R) ge(i,L,R) cout << a[i] << (i==R?'\n':' ')
#define printV(a) printA(a,0,a.size()-1)
#define MAXN 10000
//for vectors
#define pb push_back
typedef int elem_t;
typedef vector<int> vec; 
typedef vector<vec> vv; 
typedef pair<int,int> ii; 
// directions
const int fx[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
const int fxx[8][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};
template<typename T,typename TT> ostream& operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream& operator<<(ostream &s,vector<T> t){gl(i,0,SZ(t))s<<t[i]<<" ";return s; }
#define inf   INT_MAX
#define mn  INT_MIN 
long int arr[1000005];

long int tree[1000005];
long int lazy[1000005];
void build_tree(long int node,long int a,long int b)
{
	if(a>b)return;
	if(a==b)
	{
		tree[node]=arr[a];
		return ;
	}
build_tree(2*node,a,(a+b)/2);
build_tree(2*node+1,(a+b)/2+1,b);

tree[node]=tree[node*2]+tree[node*2+1];
}
void update_tree(long int node,long int a,long int b,long int i,long int j,long int value)
{
	if(lazy[node]!=0)
	{
		lazy[node]%=3;
		lazy[node]+=lazy[node];
		if(a!=b)
		{
			lazy[node*2]+=lazy[node];
			lazy[node*2+1]+=lazy[node];
			lazy[node*2]%=3;
			lazy[node*2+1]%=3;	
		}
		lazy[node]=0;
	}
	if(a > b || a > j || b < i) // Current segment is not within range [i, j]
		return;
    if(a >= i && b <= j) { // Segment is fully within range
    		tree[node] += value;
 tree[node]%=3;
		if(a != b) { // Not leaf node
			lazy[node*2] += value;
			lazy[node*2+1] += value;
			lazy[node*2]%=3;
			lazy[node*2+1]%=3;
		}
 
    		return;
	}
 
	update_tree(node*2, a, (a+b)/2, i, j, value); // Updating left child
	update_tree(1+node*2, 1+(a+b)/2, b, i, j, value); // Updating right child
 
	tree[node] = max(tree[node*2], tree[node*2+1]); 
	tree[node]%=3;
}
 long int query_tree(long int node, long int a, long int b, long int i, long int j) {
	
	
	if(a > b || a > j || b < i) return 0; // Out of range
 
	if(lazy[node] != 0) { 
		tree[node] += lazy[node]; // Update it
 tree[node]%=3;
		if(a != b) {
			lazy[node*2] += lazy[node]; // Mark child as lazy
			lazy[node*2+1] += lazy[node]; // Mark child as lazy
		lazy[node*2]%=3;
			lazy[node*2+1]%=3;
		}
 
		lazy[node] = 0; // Reset it
	}
 
	if(a >= i && b =<j) // Current segment is totally within range [i, j]
		return tree[node];
 //printf("here\n");
	long int q1 = query_tree(node*2, a, (a+b)/2, i, j); // Query left child
	long int q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j); // Query right child
 
 put2n(q1,q2);
	long int res = q1==0?1:0+q2==0?1:0; // Return final result
	
	return res;
}

int main()
{

long int n,q,x,y,z;
get2(n,q);

gl(i,0,n)arr[i]=0;
build_tree(1,0,n-1);
ms(lazy,0);

while(q--)
{
	printA(tree,0,n+1);
	printA(lazy,0,n+1);
	get3(x,y,z);
	if(x==0)
	{
		update_tree(1,0,n-1,y,z,1);
	}
	if(x==1)
	{
		
		long int ans=query_tree(1,0,n-1,y,z);
		
		printf("%ld\n",ans);
	}
}
return 0;
}
