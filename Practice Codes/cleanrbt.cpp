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
#define get1(a) scanf("%d", &a) //next three are handy ways to get ints, it's also force you to use '&' sign
#define get2(a,b) scanf("%d%d", &a, &b)
#define get3(a,b,c) scanf("%ld%ld%ld", &a, &b, &c)
#define wez(n) int (n); scanf("%d",&(n)); //handy if the input is right after the definition of a variable
#define wez2(n,m) int (n),(m); scanf("%d %d",&(n),&(m))
#define wez3(n,m,k) int (n),(m),(k); scanf("%d %d %d",&(n),&(m),&(k))
#define tests wez(testow)while(testow--) //for multilple cases problems
#define pn printf("\n");
#define put1n(x) printf("%d\n",x);
#define put1(x) printf("%ld",x);
#define put2(x,y) printf("%ld %ld",x,y);
#define put2n(x,y) printf("%d %d\n",x,y);
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
char matrix[22][22];
bool visited[22][22];
int shortest[22][22];
int bfs(int num,int w,int h,int srcx,int srcy)
{
	//printf("%d %d %d %d %d\n",num,w,h,srcx,srcy);
	
	ii pos;
	queue<ii>q;
	q.push(make_pair(srcx,srcy));
	ms(visited,0);
	gl(i,0,h)gl(j,0,w)shortest[i][j]=21440;
	shortest[srcx][srcy]=0;
	int posx,posy,moves=0;
	deque<ii>ank;
	//put1[0][0]);
while(!q.empty())
{
	pos=q.front();
	q.pop();	
if(matrix[pos.fi][pos.se]=='*')
{
moves+=shortest[pos.fi][pos.se];
//	printf("%d\n",moves);
	
	num--;
if(num==0)
{
	while(!ank.empty())
	{
		ank.pop_front();
	}
return moves;
}
ms(visited,0);
gl(i,0,h)gl(j,0,w)shortest[i][j]=21440;
ank.pb(pos);
for(int i=0;i<ank.size();i++)
{
visited[ank[i].fi][ank[i].se]=1;	
//printf("here\n");
}

shortest[pos.fi][pos.se]=0;
while(!q.empty())
{
	q.pop();
}
}



	
gl(i,0,4)
{
	posx=pos.fi+fx[i][0];
	posy=pos.se+fx[i][1];	

if(posx<0||posy<0||posx>=h||posy>=w||matrix[posx][posy]=='x')
continue;	


else if(!visited[posx][posy])
{
	//put2n(posx,posy);
	visited[posx][posy]=1;
	q.push(make_pair(posx,posy));
shortest[posx][posy]=min(shortest[posx][posy],shortest[pos.fi][pos.se]+1);	
		
}
	
}	
}	
	
}



int main()
{
	freopen("in.txt","r",stdin);
	int w,h,srcx,srcy,dtile;
	while(1)
	{
	
	get2(w,h);
	if(w==0)
	break;
	gl(i,0,h)
	getS(matrix[i]);
	dtile=0;
	gl(i,0,h)gl(j,0,w)
	{
		if(matrix[i][j]=='o')
		{
			srcx=i;
			srcy=j;
		}
		if(matrix[i][j]=='*')
		{
			dtile++;			
		}
	}
	if(dtile==0)
	printf("0\n");
	else
	{
	
	int ans=bfs(dtile,w,h,srcx,srcy);
	if(ans>=21440)
	printf("-1\n");
	else
	put1n(ans);
}
	}
	return 0;
}
