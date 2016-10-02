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
bool matrix[1002][1002];
long int n,r;
int indegree[1002];
int topologicalorder1[1002];
int topologicalorder2[1002];
void calculate_indegree()
{ms(indegree,0);
	gl(i,0,n)gl(j,0,n)
	{
		if(matrix[i][j])
		indegree[j]++;
	}
}
void topological_sort()
{
	queue<long int>q;
	for(int i=n-1;i>=0;i--)
	{
		if(indegree[i]==0)
		q.push(i);
	}
	int cnt=0;
	while(!q.empty())
	{
		int p=q.front();
		q.pop();
		topologicalorder1[p]=cnt++;
		gl(i,0,n)
		{
			if(matrix[p][i])
			{
				matrix[p][i]=0;
				--indegree[i];
				if(indegree[i]==0)
				q.push(i);
			}
			
		}
		
	}
	gl(i,0,n)topologicalorder2[topologicalorder1[i]]=i;
	stack<long int>mystack;
	gl(i,0,n)
	mystack.push(topologicalorder2[i]);
	int i=0;
	while(!mystack.empty())
	{
		topologicalorder2[i]=mystack.top();
		mystack.pop();
		i++;
	}
	
}
int it;
int counter[1002];
//bool visited[1002];
void dfs()
{
int i=0;
counter[a]=++it;
	while(1)
	{
		++it;
		gl(j,0,n)
	if(gmatrix[i][j])
     {
     	counter[j]=it;
     	i=j;
     }
     
}
	
}
bool gmatrix[1002][1002];
int main()
{ long int x,y;
tests{
	get2(n,r);
	ms(matrix,0);
	while(r--)
	{
		get2(x,y);
		matrix[x][y]=1;
	}
it=0;
	gl(i,0,n)gl(j,0,n)gmatrix[i][j]=matrix[j][i];
	dfs();
	calculate_indegree();
	topological_sort();
	int t=0;

     gl(i,0,n)
	printf("%d %d\n",counter[i],topologicalorder2[i]);
	}
	
	return 0;
}

