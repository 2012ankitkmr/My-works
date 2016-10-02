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
#define get2(a,b) scanf("%d%d", &a, &b)
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

struct elem
{
ll val;
int type;
} a[100005];

bool comp(const elem x,const elem y)
{
return x.val>y.val;
}
stack<ll>neg,pos;
int main()
{
  int n,k,flag,posi,nega;
  ll num,ans,MOD = 1000000007,max1,max2,temp1,temp2;

tests
{
get2(n,k);
gl(i,0,n)
{
get1(num);

if(num<0)
{ a[i].val = -1*num;
  a[i].type = -1;
}
else
{
  a[i].val = num;
  a[i].type = 1;
}
}
sort(a,a+n,comp);
//neg.clear();
//pos.clear();
while(!neg.empty())
neg.pop();
while(!pos.empty())
pos.pop();


gl(i,0,k)
{
if(a[i].type==-1)
  neg.push(a[i].val);
else
  pos.push(a[i].val);
}

if(n == k)
{
ans = 1;
gl(i,0,n)
ans = (ans*a[i].val)%MOD;
gl(i,0,n)
ans = ans*a[i].type;
if(ans<0)
cout<<ans+MOD<<endl;
else
cout<<ans<<endl;
continue;
}

if(neg.size()%2==0)
{
ans = 1;
while(!neg.empty())
{ans = (ans*neg.top())%MOD;
  neg.pop();
}
while(!pos.empty())
{ans = (ans*pos.top())%MOD;
  pos.pop();
}
cout<<ans<<endl;
}
else
{
//check if all neg values are present
posi=0;
nega=0;
gl(i,k,n)
{
if(a[i].type == 1)
 posi++;
 else
 nega++;
}
if(pos.empty())
{
if(posi)
{
  neg.pop();
  gl(i,k,n)
  {
    if(a[i].type==1)
    {
      pos.push(a[i].val);
      break;
    }
  }
  ans = 1;
  while(!neg.empty())
  {ans = (ans*neg.top())%MOD;
    neg.pop();
  }
  while(!pos.empty())
  {ans = (ans*pos.top())%MOD;
    pos.pop();
  }
  if(ans<0)
  cout<<ans+MOD<<endl;
  else
  cout<<ans<<endl;

}
else
{
  ans = 1;
for(int i = n-1;i >= n-k;i--)
{
  //printf("The type is %d\n",a[i].type);
ans = (ans*a[i].val)%MOD;
}
if(k&1)
ans= ans*-1;
if(ans<0)
cout<<ans+MOD<<endl;
else
cout<<ans<<endl;
}

}
else if(posi==0)
{
pos.pop();
neg.push(a[k].val);

ans = 1;
while(!neg.empty())
{
  ans = (ans*neg.top())%MOD;
  neg.pop();
}
while(!pos.empty())
{ans = (ans*pos.top())%MOD;
  pos.pop();
}
if(ans<0)
cout<<ans+MOD<<endl;
else
cout<<ans<<endl;

}
else if(nega==0)
{
neg.pop();
pos.push(a[k].val);

ans = 1;
while(!neg.empty())
{ans = (ans*neg.top())%MOD;
  neg.pop();
}
while(!pos.empty())
{ans = (ans*pos.top())%MOD;
  pos.pop();
}
if(ans<0)
cout<<ans+MOD<<endl;
else
cout<<ans<<endl;


}
else
{
//removing neg element
temp1 = neg.top();
neg.pop();
gl(i,k,n)
{
  if(a[i].type==1)
  {
    max1 = a[i].val;
    break;
  }
}
max1 = max1*pos.top();
temp2 = pos.top();

pos.pop();
gl(i,k,n)
{
  if(a[i].type == -1)
  {
    max2 = a[i].val;
    break;
  }
}
max2 = max2*temp1;
if(max1<max2)
{

  ans = max2%MOD;
  while(!neg.empty())
  {ans = (ans*neg.top())%MOD;
    neg.pop();
  }
  while(!pos.empty())
  {ans = (ans*pos.top())%MOD;
    pos.pop();
  }
  if(ans<0)
  cout<<ans+MOD<<endl;
  else
  cout<<ans<<endl;

}
else
{
  ans = max2%MOD;
  while(!neg.empty())
  {ans = (ans*neg.top())%MOD;
    neg.pop();
  }
  while(!pos.empty())
  {ans = (ans*pos.top())%MOD;
    pos.pop();
  }
  if(ans<0)
  cout<<ans+MOD<<endl;
  else
  cout<<ans<<endl;

}

}

}
}

  return  0;
}
