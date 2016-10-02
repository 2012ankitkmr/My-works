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
#define sz(x) ((int)((x).size()))
#define rmax(a,b) (a)=max((a),(b)); // set a to the maximum of a and b
#define rmin(a,b) (a)=min((a),(b));
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
#define printa(a,L,R) ge(i,L,R) cout << a[i] << (i==R?'\n':' ')
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
int matrix[204][204];
int gmatrix[204][204];
int n;
bool bfs(int s,int t,int parent[])
{
	bool visited[n+3];
	memset(visited,0,sizeof visited);
	visited[s]=1;
	queue<int>q;
	q.push(s);
	 parent[s] = -1;
	while(!q.empty())
	{
		int p=q.front();
		q.pop();
		for(int i=0;i<=n;i++)
		{
			if(!visited[i]&&gmatrix[p][i])
			{
				visited[i]=1;
				q.push(i);
				parent[i]=p;
			}
			
		}
		
	}
	return visited[t]==true;
}
int fordfullkerson(int s,int t)
{
	for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)gmatrix[i][j]=matrix[i][j];
	int parent[n+1];
	int i,j;
	int max_flow=0,flow=INT_MAX;
	
	while(bfs(s,t,parent))
	{
		
		for(i=t;i!=s;i=parent[i])
		{
				j=parent[i];
		//printf("j=%d,i=%d\n",j,i);
		flow=min(flow,gmatrix[j][i]);
		}
		for(i=t;i!=s;i=parent[i])
		{
			j=parent[i];
		gmatrix[j][i]-=flow;
		gmatrix[i][j]+=flow;
		}
		max_flow+=flow;
	}	
	return max_flow;
}
int main()
{
	int m,a;
	tests{
	get1(n);
	--n;
	ms(matrix,-1);
	gl(i,0,n)
	{
		get1(m);
		while(m--)
		{
			get1(a);	
			matrix[i][--a]=1;
		}
	}
	max=-1;
	ge(i,1,n)
	{
		int ans=fordfullkerson(0,i);
		if(max<ans)
		ans=max;
	}
	printf("%d\n",ans);
	}
	return 0;
}
