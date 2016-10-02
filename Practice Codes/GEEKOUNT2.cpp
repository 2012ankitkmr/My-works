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
#define getS(x) scanf(" %s", x) //get a char* string
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
typedef vector<ll> vec; 
typedef vector<vec> vv; 
typedef pair<int,int> ii; 
// directions
const int fx[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
const int fxx[8][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};
template<typename T,typename TT> ostream& operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream& operator<<(ostream &s,vector<T> t){gl(i,0,SZ(t))s<<t[i]<<" ";return s; }
#define inf INT_MAX
#define mn INT_MIN 


int fives[15];
int dp[15][12];
ll culfive[15];

int find_odds(char s[])
{
	int len=strlen(s);
	int ans=dp[len][s[0]-'0'];
		if(((int)(s[0]-'0'))%2==0)
		return ans;
	for(int i=1;s[i];i++)
	{
		ans+=(dp[len-i][s[i]-'0']);
		ans-=culfive[len-i-1];
		if(((int)(s[i]-'0'))%2==0)
		break;
	}
	return ans;
	
}
int conint(char s[])
{

//int len=strlen(s);
int num=(int)(s[0]-'0');
for(int i=1;s[i];i++)
{
num*=10;	
num+=((int)(s[i]-'0'));
}
	
	return num;
}
bool even(char s[])
{
	for(int i=0;s[i];i++)
	{
		if((int)(s[i]-'0')%2==0)
		return true;
	}
	return false;
}
int main()
{
int sum;
	
fives[1]=5;
gl(i,2,11)
fives[i]=fives[i-1]*5;
culfive[1]=5;
gl(i,2,11)
culfive[i]=fives[i]+culfive[i-1];

//printA(culfive,1,4);
dp[1][0]=0;
dp[1][1]=1;
dp[1][2]=1;
dp[1][3]=2;
dp[1][4]=2;
dp[1][5]=3;
dp[1][6]=3;
dp[1][7]=4;
dp[1][8]=4;
dp[1][9]=5;

for(int pos=2;pos<=10;pos++)
{
	sum=0;
	ge(i,1,pos-1)
	{
		sum+=fives[i];
	}
	dp[pos][0]=sum;
	dp[pos][1]=sum;
	for(int num=2;num<=9;num+=2)
	{
	dp[pos][num]=dp[pos-1][9]+dp[pos][num-1];
	dp[pos][num+1]=dp[pos][num];	
	}
	
}	

ge(pos,1,10)
{
ge(num,0,9)
printf("%8lld",dp[pos][num]);
pn
	
}
printf("%lld\n",dp[4][5]);
	char l[15],r[15];
	int li,ri,ans1,ans2,ans;
tests
{
getS(l);
getS(r);	

 ans1=find_odds(l);
li=conint(l);
put1n(ans1);
ans1=li-ans1;
ans2=find_odds(r);
ri=conint(r);
put1n(ans2);
ans2=ri-ans2;
ans=ans2-ans1;
if(even(l))
ans++;

put1n(ans);	
}	
	
	return 0;
}
