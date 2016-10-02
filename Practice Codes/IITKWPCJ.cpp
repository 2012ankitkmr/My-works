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
int f[100005]={0};
void prefix_table(char p[],int m)
{
	f[0]=0;
	int i=1,j=0;
	while(i<m)
	{
		if(p[j]==p[i])
		{
			i++;
			j++;
			f[i]=j;
		}
		else if(j>0)
		{
			j=f[j-1];
		}
		else
		{
		f[i]=0;
		i++;
	}
	}
	
}

int KMP(char T[],int n,char prefix[],int m)
{
	int i=0,j=0;
	prefix_table(prefix,m);
	while(i<n)
	{
		if(T[i]==prefix[j])
		{
			if(j==m-1)
			return i-j;
			else
			{
				i++;
				j++;
			}

}			else
			     if(j>0)
			{
				j=f[j-1];
			}
			else
			i++;
		
	}
	return -1;
}

char s[100005],t[100005],aux[100005];
int main()
{long int ans,len1,len2,len3,len;

freopen("in.txt","r",stdin);
	tests
	{
ms(f,0);int flag,len3=0;
		scanf("%s",s);
		scanf("%s",t);
	int i,j;
		len1=strlen(s);
		len2=strlen(t);
	if(len1>len2)
	{
		len3=len1-len2;
	}
	if(len1<len2)
	{
		len3=len2-len1;
	}
	if(len3<=len1&&len3<=len2)
	{
		flag=3;	
	}
	if(len1<len3&&len1<len2)
	{
	flag=1;
	}
	if(len2<len3&&len2<len1)
	{
		flag=2;
	}
	if(flag==3)
	{
	if(len2>len1)
	{
		i=len1;
		j=0;
	while(t[i])
	{
		aux[j++]=t[i];
		i++;
	}	
	}
	if(len1>len2)
	{
		i=len2;
		j=0;
	while(s[i])
	{
		aux[j++]=s[i];
		i++;
	}	
	}
	len=len3;	
	}
	if(flag==1)
	{
		len=len1;
		i=0,j=0;
		while(s[i])
		{
			aux[j++]=s[i++];
		}
	}
	if(flag==2)
	{
		len=len2;
	i=0,j=0;
		while(t[i])
		{
			aux[j++]=t[i++];
		}
	}
	j=0,i=0;
	 flag=0;
	//printf("%s ,%d\n",aux,len);
	while(s[j])
	{
	
	if(aux[i++]!=s[j++])
	{
		flag=1;
	}
	if(i>=len)
	i=0;
	}
	j=0;
	i=0;
	while(t[j])
	{
	if(aux[i++]!=t[j++])
	{
		flag=1;
	}
	if(i>=len)
	i=0;
	}
	
		if(flag&&len)
		{
			printf("NO\n");
		}
		else
		{
		
		if(len1>len2)
		 ans=KMP(s,len1,t,len2);
		else
		ans=KMP(t,len2,s,len1);
		if(ans==-1)
		printf("NO\n");
		else
		printf("YES\n");
		
		}
	}
	return 0;
}
