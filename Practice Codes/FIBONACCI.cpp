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
#define wez(n) int (n); scanf("%d",&(n)) //handy if the input is right after the definition of a variable
#define wez2(n,m) int (n),(m); scanf("%d %d",&(n),&(m))
#define wez3(n,m,k) int (n),(m),(k); scanf("%d %d %d",&(n),&(m),&(k))
#define TESTS wez(testow)while(testow--) //for multilple cases problems
#define pn printf("\n");
#define pln(x) printf("%ld\n",x);
#define pl(x) printf("%ld",x);
#define whileZ int T; getI(T); while(T--) // the same as above
#define getS(x) scanf("%s", x) //get a char* string
#define ms(a, v) memset(a, v, sizeof(a)) //set elements of array to some value
#define ch2Int(c) (c-'0')
#define lastEle(vec) vec[vec.size()-1] 
#define SZ(x) ((int)((x).size()))
#define REMAX(a,b) (a)=max((a),(b)) // set a to the maximum of a and b
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
 void find(ll f[2][2],ll m[2][2],int M)
    {
    	ll x=((f[0][0]*m[0][0])%M+(f[0][1]*m[1][0])%M)%M;
    	ll y=((f[0][0]*m[0][1])%M+(f[0][1]*m[1][1])%M)%M;
    	ll z=((f[1][0]*m[0][0])%M+(f[1][1]*m[1][0])%M)%M;
    	ll w=((f[1][0]*m[0][1])%M+(f[1][1]*m[1][1])%M)%M;
    	f[0][0]=x;
    	f[0][1]=y;
    	f[1][0]=z;
    	f[1][1]=w;
    }
 namespace ankit{
 
    void fibonacci(ll f[2][2],ll n, int M)
    {
    	if(n==1)
    		return;
    	ll m[2][2]={{1,1},{1,0}};
    	fibonacci(f,n/2,M);
    	find(f,f,M);
    	if(n%2!=0)
    	find(f,m,M);
    }
    
}
    bool select(int a[], int ar[], int n, int r,ll *sum)
    {
    	*sum=0;
    	int i=r,j;
    	while(i>=0&&ar[i]==n-r+i)
    	i--;
    	if(i<0)
    	return false;
    	ar[i]=ar[i]+1;
    	*sum=*sum+a[ar[i]];
    	ge(j,i+1,r){
    	ar[j]=ar[i]+j-i;
    	*sum=*sum+a[ar[j]];
    	}
    	i--;
    	while(i>=0){
    	*sum=*sum+a[ar[i]];
    	i--;
    	}
    	return true;
    }
    int main() {
    	// your code goes here
    	int n, k,M=99991;
    	ll sum=0;
    	get2(n,k);
    	int arr[n];
    	int array[k];
    	int i=0;
    	while(i<n)
    	{
    		get1(arr[i]);
    		if(i<k){
    		array[i]=i;
    		sum+=arr[i];
    		}
    		i++;
    	}
    	ll sumtemp=0;
    	ll fib[2][2];
    	do{
    		fib[0][0]=1,fib[0][1]=1,fib[1][0]=1,fib[1][1]=0;
    	
    		if(sum==1||sum==2)
    		sumtemp=(sumtemp+1)%M;
    		else
    		{
    			ankit::fibonacci(fib,sum-1,M);
    			sumtemp=(sumtemp+fib[0][0])%M;
    		}
    	}while(select(arr,array,n-1,k-1,&sum));
    	cout << sumtemp;
    	return 0;
    } 
