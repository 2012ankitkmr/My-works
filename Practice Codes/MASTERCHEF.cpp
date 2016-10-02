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

int n,k,m,i,j,x;
ll sum,sumtemp;
ll temp[100005],arr[100005],temp2[100005],index[100005];
struct chef{
	ll l;
	ll r;
	ll c;
}store[100005];
 
ll relation[100005][501]={0};
 
void merge( int low, int mid, int high)
{
    vector<chef> vec1(store + low, store+ mid + 1);
    vector<chef> vec2(store+ mid + 1, store+ high + 1);
 
    int n1 = mid - low + 1;
    int n2 = high - mid;
 
    int i, j; i = j = 0;
 
    while (i < n1 && j < n2) {
        if (vec1[i].c < vec2[j].c) {
            store[low].r=vec1[i].r;
            store[low].c=vec1[i].c;
   			store[low++].l=vec1[i++].l;
 
        } else {
            store[low].r=vec2[j].r;
            store[low].c=vec2[j].c;
   			store[low++].l=vec2[j++].l;
        }
    }
 
    while (i < n1) {
            store[low].r=vec1[i].r;
            store[low].c=vec1[i].c;
   			store[low++].l=vec1[i++].l;
    }
 
    while (j < n2) {
            store[low].r=vec2[j].r;
            store[low].c=vec2[j].c;
   			store[low++].l=vec2[j++].l;
    }
}
 
void merge_sort(ll low, ll high)
{
    if (low < high) {
        int mid = (low + high) / 2;
        merge_sort(low, mid);
        merge_sort(mid + 1, high);
        merge(low, mid, high);
    }
}

ll knapsack(ll Items, ll size, ll weights[], ll values[]){
    ll i,j;
 
    ge(i,1,Items){
        ge(j,0,size){
            if (weights[i-1]<=j){
                relation[i][j] = max(relation[i-1][j],values[i-1]+relation[i-1][j-weights[i-1]]);
            }
            else{
                relation[i][j] = relation[i-1][j];
            }
        }
    }
    return relation[Items][size];
}
 
int main()
{
	
	tests
	{
		sum=0;
get3(n,k,m);
 		x=0;
 
	gl(i,0,n)
		{
			scanf("%lld",&arr[i]);
 
			sum+=arr[i];
			if(arr[i]<0){
				temp2[x]=-arr[i];
			temp[x]=510;
			index[x]=i;
			x++;
			}
		}
		
	gl(i,0,x)
		{
			for(j=0;j<=k;j++)
			relation[i][j]=0;
		}
	gl(i,0,m)
		{
			scanf("%lld%lld%lld",&store[i].l,&store[i].r,&store[i].c);
		}
 
		merge_sort(0,m-1);
 
		gl(i,0,x)gl(j,0,m)
	   if(index[i]>=(store[j].l-1) && index[i]<=(store[j].r-1) && store[j].c<temp[i])
		{
		temp[i]=store[j].c;
		break;
	    }
 
		sumtemp=knapsack(x,k,temp,temp2);
		printf("%lld\n",sum+sumtemp);
	}
	return 0;
}
