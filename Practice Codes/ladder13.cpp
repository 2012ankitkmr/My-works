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
#define inf INT_MAX
#define mn INT_MIN 

int a[2002][2002];
ll cost[2002][2002];
vector<ll>neg_diag,pos_diag;
typedef pair<ll, pair<int,int> > chess;
chess  white,black;
int n;
ll getsumnegativediagonal(int x,int y)
{
	ll sum=0;
	int i=x,j=y;
	while(i<=n&&j<=n)
	{
		sum+=a[i][j];
		i++,j++;
	}
	return sum;
}
ll getsumpositivediagonal(int x,int y)
{
	ll sum=0;
	int i=x,j=y;
	while(i<=n&&j>=1)
	{
		sum+=a[i][j];
		i++,j--;
	}
	return sum;
}
void fill_neg_diagonal(int x,int y,ll val)
{
	
	int i=x,j=y;
	while(i<=n&&j<=n)
	{
        cost[i][j]=val;
		i++,j++;
	}	
	
}
void fill_pos_diagonal(int x,int y,ll totalsum)
{
	// even is for white
	int i=x,j=y;
	while(i<=n&&j>=1)
	{
	cost[i][j]=totalsum-a[i][j]+cost[i][j];
    if((i+j)&1)
    {
	if(black.fi<cost[i][j])
	{
	//printf("here1\n");
		black.fi=cost[i][j];
		black.se.fi=i,black.se.se=j;
	}
    }
	else
	{
	if(white.fi<cost[i][j])
	{
		//printf("here2\n");
		white.fi=cost[i][j];
		white.se.fi=i,white.se.se=j;
	}	
	}	  
     i++,j--;
	}
}


int main()
{
//freopen("in.txt","r",stdin);	
	get1(n);
	ge(i,1,n)ge(j,1,n)
	get1(a[i][j]);
	//filling the sum of diagonal element with negative slope
	for(int i=n;i>=1;i--)
	{
		neg_diag.pb(getsumnegativediagonal(i,1));
	}
	for(int i=2;i<=n;i++)
	{
		neg_diag.pb(getsumnegativediagonal(1,i));		
	}
	
	//filling the sum of diagonal element with positive slope
	for(int i=1;i<=n;i++)
	{
		pos_diag.pb(getsumpositivediagonal(1,i));		
	}

	for(int i=2;i<=n;i++)
	{
		pos_diag.pb(getsumpositivediagonal(i,n));
	}
	//filling the cost matrix with neg diagonal	
int p=0;
	for(int i=n;i>=1;i--)
	{
		fill_neg_diagonal(i,1,neg_diag[p++]);
	}
	for(int i=2;i<=n;i++)
	{
		fill_neg_diagonal(1,i,neg_diag[p++]);		
	}
	//filling and find the max values using pos diagonal
	white.fi=0,black.fi=0;
	white.second.fi=1,white.second.se=1,black.second.fi=1,black.second.se=2;
	p=0;

	for(int i=1;i<=n;i++)
	{
	fill_pos_diagonal(1,i,pos_diag[p++]);		
	}
	
	for(int i=2;i<=n;i++)
	{
	fill_pos_diagonal(i,n,pos_diag[p++]);
	}	
    
	cout<<black.fi+white.fi<<endl;
	printf("%d %d %d %d\n",white.se.first,white.second.se,black.second.fi,black.second.se);	
	
	return 0;
}
