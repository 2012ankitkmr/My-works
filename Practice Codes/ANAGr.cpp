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
#define tolower(a) if((int)a>=65&&(int)a<=90)a+=32;
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

char c1[111],c2[111];
int  hash1[257],hash2[257];
int main()
{
//freopen("in.txt","r",stdin);
	int t,size1,size2;
	get1(t);
	char ch;
	scanf("%c",&ch);
	while(t--)
	{
		
		ms(hash1,0);
		ms(hash2,0);
	size1=0;
	size2=0;


gets(c1);
//printf("%s\n",c1);
gets(c2);
//printf("%s\n",c2);
int k=strlen(c1);
int j=0; 
//put1n(k);
while(k--)	
{
if(c1[j]<65||(c1[j]>90&&c1[j]<97)||c1[j]>123)
{ j++;
continue;
}
tolower(c1[j]);
//printf("%c",c1[j]);
hash1[(int)c1[j]]++;	
j++;
size1++;
}
k=strlen(c2);
//put1n(k);
j=0;
while(k--)	
{
if(c2[j]<65||(c2[j]>90&&c2[j]<97)||c2[j]>123)
{ j++;
continue;
}
tolower(c2[j]);
//printf("%c",c2[j]);
hash2[(int)c2[j]]++;	
j++;
size2++;
}	

int flag=0;
queue<char>str;
if(size1==size2)
{
	ge(i,0,256)
	if(hash1[i]!=hash2[i])
	flag=1;
	
}
else
{
if(size1>size2)
{
	gl(i,0,256)
	if(hash2[i]>hash1[i])
{
	flag=1;
	break;
}
	else if(hash2[i]<hash1[i])
	{
		flag=2;
		int diff=hash1[i]-hash2[i];
		
		while(diff--)
		{
			str.push((char)i);
		}
	}
	
}	
else
{
	gl(i,0,256)
	if(hash1[i]>hash2[i])
	{
	flag=1;
	break;
}
	else if(hash1[i]<hash2[i])
	{
		flag=2;
		int diff=hash2[i]-hash1[i];
		
		while(diff--)
		{
			str.push((char)i);
		}
	}
	
}	
}		
if(flag==1)
printf("NO LUCK\n");

else if(flag==0)
printf("YES\n");	
else if(flag==2)	
{
	while(!str.empty())
	{
		int cp=str.front();
		str.pop();
		printf("%c",cp);
	}
	pn
}

	}
	return 0;
}
