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
#define gl(i,L,R) for (ll i = L; i < R; i++) //next four are for "for loops"
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
#define put1n(x) printf("%lld\n",x);
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

ll stree[300000],mtree[300000];
ll getmid(ll a,ll b)
{
	return a+(b-a)/2;
}

ll sumquery(ll ss,ll se,ll l,ll r,ll node)
{
	if(ss<0||ss>se||l<0||l>r||se<l||ss>r)
	return 0;
	if(l<=ss&&r>=se)
	return stree[node];
	ll mid=getmid(ss,se);
	return sumquery(ss,mid,l,r,2*node+1)+sumquery(mid+1,se,l,r,2*node+2);
}

ll minquery(ll ss,ll se,ll l,ll r,ll node)
{
	 if (l <= ss && r >= se)
        return mtree[node];
 
    // If segment of this node is outside the given range
    if (se < l || ss > r)
        return INT_MAX;
	
	if(l<=ss&&r>=se)
	return mtree[node];
	ll mid=getmid(ss,se);
	return min(minquery(ss,mid,l,r,2*node+1),minquery(mid+1,se,l,r,2*node+2));
}



void updatemin(ll ss,ll se,ll index,ll val,ll node)
{
if(index<ss||index>se)
return; 
//process
if(ss==se)
{
	mtree[node]=val;
	return;
}
ll mid=getmid(ss,se);
updatemin(ss,mid,index,val,2*node+1);
updatemin(mid+1,se,index,val,2*node+2);
mtree[node]=min(mtree[2*node+1],mtree[2*node+2]);	
}
void updatesumutil(ll ss,ll se,ll index,ll diff,ll node)
{
	if(index<ss||index>se)
	return;
	stree[node]=stree[node]+diff;
	if(ss!=se)
	{
		ll mid=getmid(ss,se);
		updatesumutil(ss,mid,index,diff,2*node+1);
		updatesumutil(mid+1,se,index,diff,2*node+2);
	}
}

void updatesum(ll arr[],ll i,ll value,ll n)
{
	if(i<0||i>n)
	return ;
	ll diff=value-arr[i];
	updatesumutil(0,n-1,i,diff,0);
}

ll construct_min(ll arr[],ll ss,ll se,ll node)
{
	if(ss==se)
	{
		mtree[node]=arr[se];
		return arr[se];
	}
	ll mid=getmid(ss,se);
	mtree[node]=min(construct_min(arr,ss,mid,2*node+1),construct_min(arr,mid+1,se,2*node+2));
	return  mtree[node];
}
ll construct_sum(ll arr[],ll ss,ll se,ll node)
{
	if(ss==se)
	{
		stree[node]=arr[se];
		return arr[se];
	}
	ll mid=getmid(ss,se);
	stree[node]=construct_sum(arr,ss,mid,2*node+1)+construct_sum(arr,mid+1,se,2*node+2);
	return  stree[node];
}
ll max_size;
void build2trees(ll arr[],ll n)
{
	ll h=(ll)ceil(sqrt(n));
	 max_size=pow(2,h+1)-1;
	ll temp=construct_min(arr,0,n-1,0);
	temp=construct_sum(arr,0,n-1,0);
}
ll apples[100005];
int main()
{
	freopen("in.txt","r",stdin);
	char s[12];
	ll n,m,a,b,ans1,ans2;
	get1(n);
	//	printf("here\n");
	gl(i,0,n)
	get1(apples[i]);
	get1(m);
	//printf("here\n");
	build2trees(apples,n);
				//printA(mtree,0,max_size-1);
		//	prll A(stree,0,max_size-1);
//pn
	while(m--)
	{
		getS(s);
		if(s[0]=='C')
		{
			get2(a,b);
			
			ans1=sumquery(0,n-1,a,b,0);
			ans2=minquery(0,n-1,a,b,0);
		//put2n(ans1,ans2);
		put1n(ans1-ans2);
		}
		else
		{
			get2(a,b);
			if(s[0]=='G')
			{
			
			updatemin(0,n-1,b,a+apples[b],0);
			updatesum(apples,b,a+apples[b],n);
		apples[b]+=a;
		}
		if(s[0]=='E')
			{
			
			updatemin(0,n-1,b,apples[b]-a,0);
			updatesum(apples,b,apples[b]-a,n);
		apples[b]-=a;
		}
					
		//	printA(mtree,0,max_size-1);
		//	printA(stree,0,max_size-1);
//pn
		}
	}
	return 0;
}
