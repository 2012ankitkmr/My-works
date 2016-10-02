#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF (1<<25)
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
// directions
const int fx[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
const int fxx[8][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};
template<typename T,typename TT> ostream& operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream& operator<<(ostream &s,vector<T> t){gl(i,0,SZ(t))s<<t[i]<<" ";return s; }


typedef bool (*comp)(pair<ii,int> , pair<ii,int> );
vector<vi> island;
vector<vi> visited;
int m,n;
int ans;
bool compare (pair<ii,int> a, pair<ii,int> b){
return a.second > b.second;
}
int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};
void fill(){
priority_queue<pair<ii,int> , vector<pair<ii,int> > , comp> pq(compare);
for(int j=0;j<m;++j){
pq.push(pair<ii,int> (ii(0,j),island[0][j]));
}
for(int j=0;j<m;++j){
pq.push(pair<ii,int> (ii(n-1,j),island[n-1][j]));
}
for(int j=1;j<n-1;++j){
pq.push(pair<ii,int> (ii(j,0),island[j][0]));
}
for(int j=1;j<n-1;++j){
pq.push(pair<ii,int> (ii(j,m-1),island[j][m-1]));
}
while(!pq.empty()){
pair<ii,int> top1 = pq.top();
while(!pq.empty()){
pair<ii,int> top2 = pq.top();
if(top2.second>top1.second){
break;
}
pq.pop();
if(visited[top2.first.first][top2.first.second]++){
continue;
}
ans+=top1.second-top2.second;
for(int i=0;i<4;++i){
int cx=top2.first.first+dx[i];
int cy=top2.first.second+dy[i];
if(cx>=0&&cx<n&&cy>=0&&cy<m){
pq.push(pair<ii,int> (ii(cx,cy),island[cx][cy]));
}
}
}
}
}
int main(){
//freopen("B-large.in","r",stdin);
//freopen("out.txt","w+",stdout);

int t;

scanf("%d",&t);

for(int test = 1;test<=t;test++)
{
ans = 0;
scanf("%d %d",&n,&m);
island = vector<vi> (n,vi(m,0));
visited = vector<vi> (n,vi(m,0));
for(int i=0;i<n;++i){
for(int j=0;j<m;++j){
scanf("%d",&island[i][j]);
}
}
fill();
printf("Case #%d: %d\n",test,ans);
}
return 0;
}
