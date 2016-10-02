#include<bits/stdc++.h>
using namespace std;
#define bit(x,i) (x&(1<<i))  //select the bit of position i of x
#define lowbit(x) ((x)&((x)^((x)-1))) //get the lowest bit of x
#define hBit(msb,n) asm("bsrl %1,%0" : "=r"(msb) : "r"(n)) //get the highest bit of x, maybe the fastest
#define max3(a,b,c) (a,max(b,c))
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
//long int hast[10000000];

inline void show(int n) { printf("%d\n",n); }
/*inline void sortlinear(long int a[],long int n)
{
	ms(hast,0);
    long int mx=a[0];
	gl(i,0,n)
	{
	hast[a[i]]++;
	if(mx<a[i])
	mx=a[i];
}
long int iter=0,indexer=0;
	while(iter<=mx)
	{
		while(hast[iter]--)
		{
			a[indexer++]=iter;
		}
		iter++;
	}
}*/
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


struct edge
{
ll to;
ll value;	

}graph[100005],transpose[100005];

ll sum[100005];


ll findterminalnode(ll n)
{
	queue<ll>q;
	q.push(1);
ll node=1;
while(!q.empty())
{
ll p=q.front();
q.pop();
if(graph[p].to!=-1)
{
	q.push(graph[p].to);
	node=graph[p].to;
}

}	
return node;	
}


void init()
{
	gl(i,0,100003)
	{
		graph[i].to=-1;
		graph[i].value=0;
			transpose[i].to=-1;
		transpose[i].value=0;
	}
	
}
ll  findsumfromnode(ll n,ll node)
{
	queue<ll>q;
	q.push(node);
	ll tempsum=0,net=0;
while(!q.empty())
{
ll p=q.front();
q.pop();
if(transpose[p].to!=-1)
{
	tempsum+=transpose[p].value;
	q.push(transpose[p].to);
	net+=tempsum;
//	put1n(net);
}
}
//pn		
	return net;
}

void crawl(ll n,ll node)
{
	queue<int>q;
	q.push(transpose[node].to);
ll preval=transpose[node].value;
ll net=sum[node];
ll mul,add;
ll remnode=n-2;
ll precnode=0;
while(!q.empty())
{
ll p=q.front();
q.pop();		
	
	mul=(remnode)*preval;
	add=precnode*preval;	
net=(net-mul);
net=(net+add);
sum[p]=net;
	remnode--;
	precnode++;
	preval=transpose[p].value;	
	if(transpose[p].to!=-1)
	{
		q.push(transpose[p].to);
	}
		
}
	
}
int main()
{
	//freopen("in.txt","r",stdin);
	ll a,b,c,n,node;
	edge temp;
	tests
	{
		ms(sum,0);
		init();
		scanf("%lld",&n);
		gl(i,0,n-1)
		{
			scanf("%lld%lld%lld",&a,&b,&c);
			temp.to=b;
			temp.value=c;
		graph[a]=temp;
		temp.to=a;
		transpose[b]=temp;
		}
		
		node=findterminalnode(n);
//printf("node=%d\n",node);
	
		sum[node]=findsumfromnode(n,node);
		//printf("sum[node]=%d\n",sum[node]);
		crawl(n,node);
ge(i,1,n)
{
	printf("%lld\n",sum[i]);
}
		
	}
	
	return 0;
}
