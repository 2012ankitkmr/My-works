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
//#define pn printf("\n");
#define put1n(opo) printf("%lld\n",opo);
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
#define ll long long int //data types used often, but you don't want to type them time by time
#define ull unsigned long long
#define ui unsigned int
#define us unsigned short
#define IOS ios_base::sync_with_stdio(0); //to synchronize the input of cin and scanf
#define INF 1000000007
#define PI 3.1415926535897932384626
//for map, pair
#define mp make_pair
#define fi first
#define se second
// for debug
//namespace ank{
//long int hast[10000000];
 
//inline void show(int n) { printf("%d\n",n); }
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
//}
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
 
 
ll next_int()
{
        int cc = getc(stdin);
       for (;cc < '0' || cc > '9';)  cc = getc(stdin);
       int ret = 0;
       for (;cc >= '0' && cc <= '9';)
       {
          ret = ret * 10 + cc - '0';
          cc = getc(stdin);
       }
      return ret;
}
 
ll st[410015],a[100005];
ll n,mid;
ll lazy[3][410015];

 
void updit(ll node,ll beg,ll last){
    if(lazy[2][node]){
        st[node]=(lazy[2][node]*(last-beg+1))%INF;
        if(beg!=last){
            lazy[2][node*2]=lazy[2][node*2+1]=lazy[2][node];
            lazy[0][node*2]=lazy[0][node*2+1]=0;
            lazy[1][node*2]=lazy[1][node*2+1]=1;
        }
        lazy[2][node]=0;
    }
    if(lazy[1][node]!=1 || lazy[0][node]!=0)
    {
		st[node]=(st[node]*lazy[1][node])%INF;
    	st[node]=(st[node]+(lazy[0][node]*(last-beg+1))%INF)%INF;
 
    	if(beg!=last){
        lazy[1][node*2+1]*=lazy[1][node];
        lazy[1][node*2]*=lazy[1][node];
        lazy[0][node*2]*=lazy[1][node];
        lazy[0][node*2+1]*=lazy[1][node];
        lazy[0][node*2]%=INF;
        lazy[0][node*2+1]%=INF;
        lazy[0][node*2]+=lazy[0][node];
        lazy[0][node*2+1]+=lazy[0][node];
        lazy[1][node*2]%=INF;
        lazy[1][node*2+1]%=INF;
        lazy[0][node*2]%=INF;
        lazy[0][node*2+1]%=INF;
    }
    lazy[0][node]=0;
    lazy[1][node]=1;
    }
}
 
void build_tree(ll node,ll beg,ll last){
    if(beg==last){
        st[node]=a[beg];
        lazy[0][node]=lazy[2][node]=0;
        lazy[1][node]=1;
    }
    else{
        ll  mid=(beg+last)/2;
        build_tree(node*2,beg,mid);
        build_tree(node*2+1,mid+1,last);
        st[node]=(st[node*2]+st[node*2+1])%INF;    
        lazy[0][node]=lazy[2][node]=0;
        lazy[1][node]=1;
    }
}
 
ll sum(ll node,ll beg,ll last,ll l,ll r){
    updit(node,beg,last);
    if(last<l || beg>r)
        return 0;
    if(beg>=l && last<=r)
        return st[node];
    else{
        ll  mid=(beg+last)/2;
        return (sum(node*2,beg,mid,l,r)+sum(node*2+1,mid+1,last,l,r))%INF;
    }
}
 
 
void update(ll node,ll beg,ll last,ll l,ll r,ll type, ll val){
    updit(node,beg,last);
    if(beg>r || last<l)
        return ;
    if(beg>=l && last<=r){
        switch(type){
            case 3:
                st[node]=(val*(last-beg+1))%INF;
                if(beg!=last){
                    lazy[2][node*2+1]=lazy[2][node*2]=val;
                    lazy[1][node*2+1]=lazy[1][node*2]=1;
                    lazy[0][node*2+1]=lazy[0][node*2]=0;
                }
                break;
            case 2 :
                st[node]=(st[node]*val)%INF;
                if(beg!=last){
                    lazy[0][node*2]=(lazy[0][node*2]*val)%INF;
                    lazy[0][node*2+1]=(lazy[0][node*2+1]*val)%INF;
                    lazy[1][node*2]=(lazy[1][node*2]*val)%INF;
                    lazy[1][node*2+1]=(lazy[1][node*2+1]*val)%INF;
                }
                break;
            case 1:
                st[node]=(st[node]+(val*(last-beg+1))%INF)%INF;
                if(beg!=last){
                    lazy[0][node*2]=(lazy[0][node*2]+val)%INF;
                    lazy[0][node*2+1]=(lazy[0][node*2+1]+val)%INF;
                }
                break;
        }
    }
    else{
        ll  mid=(beg+last)/2;
        update(node*2,beg,mid,l,r,type,val);
        update(node*2+1,mid+1,last,l,r,type,val);
        st[node]=(st[node*2]+st[node*2+1])%INF;
    }
}
 
int main(){
	ll i,sta,x,y,v,c;
   
    scanf("%lld %lld",&n,&c);
    for(i=0;i<n;i++)
       a[i]=next_int(); 
    build_tree(1,0,n-1);
    while(c--){
   
        sta=next_int();
        x=next_int();
        y=next_int();
        if(sta!=4){
            v=next_int();
             x--;
             y--;
            	update(1,0,n-1,x,y,sta,v);
        }
        else
        {
x--;
y--;
        
            printf("%lld\n",sum(1,0,n-1,x,y));
}
    }
    return 0;
} 
