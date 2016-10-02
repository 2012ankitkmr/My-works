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
#define MAX 10000
#define MOD 1000000007
int c[102],d[102];


ll a[1020][1005];
ll lcm[1020][1005];
bool done[100005];
ll multiplier[10005];
ll check[1020][1005];

ll gcd(ll a,ll b){
    ll temp;
    if(b>a){
        temp=a;
        a=b;
        b=temp;
    }
    while(b!=0){
        temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}
void precompute(int n,int k){
    memset(done,0,100004);
   
    for(int i=1;i<1020;i++){
        a[i][1]=i;
        lcm[i][1]=i;
        lcm[i][2]=i*(i-1);
        a[i][2]=i*(i-1);
    }
    check[1][0]=1;
    check[1][1]=1;
  
    ll mul=1;
  
    a[n][1]=n;
    lcm[n][1]=n;
    int y=0;
    multiplier[y]=1;
    for(int j=2;j<=(n+1)/2;j++){
        mul=1;
        ll d=gcd((n-j+1),j-1);
        a[n][j]=((a[n][j-1]*(n-j+1))/(j-1))%MOD;
        ll newm=(j-1)/d;
        ll new3=(n-j+1)/d;
        for(int k=0;k<=y;k++){
            if(multiplier[k]==1)
                continue;
            ll f=gcd(multiplier[k],new3);
            multiplier[k]/=f;
            mul=(mul*multiplier[k])%MOD;
            new3/=f;
        }
        mul=(mul*newm)%MOD;
        y++;
        multiplier[y]=newm;
  
        lcm[n][j]=(a[n][j]*mul)%MOD;
    }


   
}
int main()
{
	//freopen("in.txt","r",stdin);
	int n,k,t,a,b,m,gc;
//	printf("here\n");

	precompute(1000,1000);
	ll ans,mul,temp;
	cin>>t;
	
    get2(n,k);
	
	get3(a,b,m);
	gl(i,0,t-1)
	get1(c[i]);
	gl(i,0,t-1)
	get1(d[i]);
	for(int test=0;test<t;test++)
	{

	if(k>(n+1)/2)
	k=(n+1)/2;
	ans=lcm[n][k]%MOD;

	put1n(ans);

	n=1+(a*ans+c[test])%m;
	k=1+(b*ans+d[test])%n;	
	}
	
	
	return 0;
} 
