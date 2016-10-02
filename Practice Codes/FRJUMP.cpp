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
#define get1(a) scanf("%lld", &a) //next three are handy ways to get ints, it's also force you to use '&' sign
#define get2(a,b) scanf("%lld%lld", &a, &b)
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
//#define MOD 1000000007

ll modPow(ll a, ll x, ll MOD) {
// return a^x mod MOD
ll res = 1;
while(x>0) {
if(x & 1) res = (res*a) % MOD;
a=(a*a)%MOD;
x >>= 1;
}
 
return res;
}
 
ll modInverse(ll a, ll MOD) {
// return modular multiplicative of: a mod p, assuming p is prime
return modPow(a, MOD-2, MOD);
}
 
vec factor[100005];
ll mul[100005],a[100005];
double sum[100005];
int main()
{
	ll n,q,ch,x,y,r,index,R,num,m;
	ll p,MOD=1000000007,ans;
	
	ll u = 1,v;
	//printf("here\n");
	while(u<=100001)
	{
		v = 1,num; 
		while((num=u*v)<=100001)
		{
			factor[num].push_back(u);
			v++;
		}
		u++;
	}
	//int maxsize = INT_MIN;
	
//	for(int i = 0 ; i <= 100001 ; i ++)
//	{
	//	for(int j = 0 ; j < factor[i].size();j++ )
	//	{
		//	printf("%d ",factor[i][j]);
	
	//	}
		//pn
		
//	int j =	factor[i].size();
//	maxsize = max(maxsize,j);
//	}
//	printf("here =%d\n",maxsize);
	
	get1(n);
	
	double logval[14],decimal,_sum;
	
	for(int i = 1;i<=10;i++)
	logval[i] = log10(i);
	
	ge(i,1,n)get1(a[i]);
	
	R = n;
	ge(i,0,n)mul[i]=1;
	ge(i,0,n)sum[i]=0;
	for(int j = 1; j <= R-1 ; j++ )
	for(int i = 1 ; i <= n; i += j )
	{
		if(i==1)
		continue;
	   mul[j] = (mul[j]*a[i])%MOD;
       sum[j] += log10(a[i]);
	}
//	ge(i,0,n)
//	{
//		printf("%d ",mul[i]);
//	}
//	pn
//	ge(i,0,n)
//	{
//		printf("%lf ",sum[i]);
//	}
//	pn
	
	
	get1(q);
	if(n<=10)
	{
		while(q--)
	{
		ans =1;
		get1(ch);
		if(ch==2)
		{
			get1(r);
			for(int i = 1 ; i<= n; i += r )
			ans = ans*a[i];
			p = ans;
			while((p/10)!=0)
			{
			p=p/10;	
			}
			
				printf("%lld %lld\n",p,ans%MOD);
		}
		else
		{
			get2(x,y);
			a[x] = y;
		}
	
	}
	}
	else
	{
	
	while(q--)
	{
		//ans =1;
		get1(ch);
		if(ch==2)
		{
			
			get1(r);
	     	_sum = (sum[r]+log10(a[1]));
	     	ans = (mul[r]*a[1])%MOD;

			 _sum = modf(_sum,&decimal);
	     	p = 1,index = 2;
			 while(1)
	     	{
	     		if(_sum<logval[index]&&abs(logval[index]-_sum)>=0.000000000001)
	     		break;
	     		index++;
	     		p++;
	     	}
			//printf("sum=%lf\n",logval[5]);
				printf("%lld %lld\n",p,ans);
		}
		else
		{
			get2(x,y);
			m = modInverse(a[x],MOD);
			for(int i = 0 ; i < factor[x-1].size() ; i++)
			{
				r = factor[x-1][i];
			
				mul[r] = (mul[r]*m)%MOD;
				mul[r] = (mul[r]*y)%MOD;
				sum[r] = sum[r]-log10(a[x])+log10(y);
			}
			a[x] = y;
		}
	
	}
}
	
	return  0;
}
