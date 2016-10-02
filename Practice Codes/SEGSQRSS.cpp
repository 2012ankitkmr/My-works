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

long int st[1000000];
long int getmid(long int a,long int b)
{
	return a+(b-a)/2;
}
void updateutil(long int *st,long int ss,long int se,long int i,long int diff,long int index)
{
	if(i<ss||i>se)
	return;
	
	st[index]=st[index]+diff;
	if(ss!=se)
	{
		long int mid=getmid(ss,se);
		 updateutil(st,ss,mid,i,diff,2*index+1);
		 updateutil(st,mid+1,se,i,diff,2*index+2);
	}
	
}

void updatevalue(long int arr[],long int *st,long int n,long int i,long int val)
{
	if(i<0||i>n)
	return;
	long int diff=val*val-arr[i]*arr[i];
	
	arr[i]=val;
	
	updateutil(st,0,n-1,i,diff,0);
	
}

long int getsum(long int *st,long int ss,long int se,long int qs,long int qe,long int index)
{
	if(ss<0||ss>se||qs<0||qs>qe||se<qs||ss>qe)
	return 0;
	if(qs<=ss&&qe>=se)
	return st[index];
	
	long int mid=getmid(ss,se);
	return getsum(st,ss,mid,qs,qe,2*index+1)+getsum(st,mid+1,se,qs,qe,2*index+2);
}
long int constructutil(long int arr[],long int ss,long int se,long int *st,long int si)
{
	if(ss==se)
	{
		st[si]=arr[se]*arr[se];
		
		return st[si];
	}
	
	long int mid=getmid(ss,se);
	st[si]=constructutil(arr,ss,mid,st,2*si+1)+constructutil(arr,mid+1,se,st,2*si+2);
	return st[si];	
}

long int max_size;
long int*construct(long int arr[],long int n)
{
	long int h=(long int)(ceil(log2(n)));
 max_size=pow(2,h+1)-1;
	long int *st=new long int[max_size];
constructutil(arr,0,n-1,st,0);
return st;
}
int main()
{long int n,q,a,sta,nd,x,t;
long int arr[100005];
	tests
	{ t++;
	get2(n,q);
	gl(i,0,n)get1(arr[i]);
	long int *st=construct(arr,n);
	printf("Case %d:\n",t);
	while(q--)
	{
	get1(a);
	// gl(i,0,max_size)printf("%ld ",st[i]);
	switch(a)
	{ 
		case 0: 
			    get3(sta,nd,x);
			 sta--;
			 nd--;
		        ge(i,sta,nd)updatevalue(arr,st,n,i,x);
				break;
		case 1: get3(sta,nd,x);
		        sta--;
		        nd--;
				ge(i,sta,nd)updatevalue(arr,st,n,i,x+arr[i]);
	            break;	
		case 2: get2(sta,nd);
		sta--;
		nd--;
		        printf("%ld\n",getsum(st,0,n-1,sta,nd,0));
				break; 
	}	
		
	}	
		
    }
	return 0;
}
