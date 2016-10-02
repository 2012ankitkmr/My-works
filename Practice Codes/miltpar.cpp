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

int matrix[202][202],tmatrix[202][202];
int n;
stack<int>mystack;
void dfs(int a,bool visited[])
{
	visited[a]=1;
	ge(i,1,n)
	if(matrix[a][i]&&!visited[i])
	dfs(i,visited);
	mystack.push(a);
}

void gettranspose()
{
	ge(i,1,n)ge(j,1,n)tmatrix[i][j]=matrix[j][i];	
}
void dfsutil(int a,bool visited[])
{
	visited[a]=1;
	ge(i,1,n)
	if(!visited[i]&&tmatrix[a][i])
	dfsutil(i,visited);
	
}
bool singleSCC()
{
	bool visited[202];
	ms(visited,0);
	ge(i,1,n)if(!visited[i])dfs(i,visited);
	gettranspose();
	ms(visited,0);
	int cnt=0;
	while(!mystack.empty())
	{
		int p=mystack.top();
		mystack.pop();
		if(!visited[p])
		{
			dfsutil(p,visited);
			cnt++;
		}
	}
//	printf("%d\n",cnt);
	return cnt==1;
}

ll shortestpath(int src)
{
	ll dis[202],small,start,new1;
	ms(dis,INF);
	ge(i,1,n)ge(j,1,n)if(!matrix[i][j])matrix[i][j]=INF;
	int que[202];
	ms(que,0);
que[src]=1;
	int current=src,temp;
     dis[src]=0;
int	des=454,t=1;
	while(current!=des)
	{
		small=INF;
		start=dis[current];
		ge(i,1,n)
		{
			if(que[i]==0)
			{
				new1=start+matrix[current][i];
				if(new1<dis[i])
				{
					dis[i]=new1;
					printf("current=%d\n",new1);
				}
				if(dis[i]<small)
				{
				small=dis[i];
				temp=i;	
				}
				
			}
			
		}
		
		if(t=1)
		{
		//dis[1]=INF;
		des=1;
		que[1]=0;
		t=0;
	  }
	  //printf("current=%d\n",temp);
		current=temp;
     	que[current]=1;
	
	}	
	return dis[1];
}

int main()
{
	freopen("in.txt","r",stdin);
	int e,a,b,w;
	tests
	{
	get2(n,e);	
ms(matrix,0);
while(e--)
{
	get3(a,b,w);
	matrix[a][b]=w;
}
if(singleSCC())
printf("%lld\n",shortestpath(1));	
else
printf("Impossible\n");
	}
	return 0;
}
