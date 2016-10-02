#include<bits/stdc++.h>
using namespace std;
#define bit(x,i) (x&(1<<i))  //select the bit of position i of x
#define lowbit(x) ((x)&((x)^((x)-1))) //get the lowest bit of x
#define hBit(msb,n) asm("bsrl %1,%0" : "=r"(msb) : "r"(n)) //get the highest bit of x, maybe the fastest
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
#define printA(a,L,R) FE(i,L,R) cout << a[i] << (i==R?'\n':' ')
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
long int getmid(long int a,long int b)
{
	return a+(b-a)/2;
}
long int rmqutil(long int *st,long int ss,long int se,long int qs,long int qe,long int index)
{
	if(ss>=qs&&se<=qe)
	return st[index];
	if(se<qs||ss>qe)
	return inf;
	long int mid=getmid(ss,se);
	return min(rmqutil(st,ss,mid,qs,qe,2*index+1),rmqutil(st,mid+1,se,qs,qe,2*index+2));
}
long int rmq(long int*st,long int n,long int qs,long int qe )
{
	if(qs<0||qe>n-1||qs>qe)
	return -1;
	
	return rmqutil(st,0,n-1,qs,qe,0);	
}
long int constructutil(long int arr[],long int ss,long int se,long int*st,long int index)
{
	if(ss==se)
	{
		st[index]=arr[se];
		return arr[ss];
	}
	
	long int mid=getmid(ss,se);
	st[index]=min(constructutil(arr,ss,mid,st,2*index+1),constructutil(arr,mid+1,se,st,2*index+2));
	return st[index];
}

long int*buildtree(long int arr[],long int n)
{
	long int h=(int)(ceil(log2(n)));
	long int max_size=(h+1)<<2-1;
	//ank::show(max_size);
	long int *st=new long int[max_size];
	constructutil(arr,0,n-1,st,0);	
//ge(i,0,max_size)put1n(st[i]);
return st;
}


int main()
{
	long int x,y,n,q,arr[1000005],t=0;
	tests{
	get2(n,q);
	gl(i,0,n)get1(arr[i]);
	long int *st=buildtree(arr,n);
	printf("Scenario #%d:\n",++t);
	while(q--)
	{
		get2(x,y);
		x--;
		y--;
		long int ans=rmq(st,n,x,y);
		put1n(ans);
	}
	}
	
	return 0;
}


