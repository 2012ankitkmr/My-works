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


long long int a[500005];

struct prime{
	long long int cnt,mask;	
prime operator+(const prime& a)const
{
	prime temp;
	temp.cnt=cnt+a.cnt;
		if(mask==(1<<4)||a.mask==(1<<4))
		temp.mask=(1<<4);
		else
	    temp.mask=mask^a.mask;
	return temp;
}
};

prime tree[2000000];


long long int getmid(long long int a,long long int b)
{
	return a+(b-a)/2;
}


void modify_array(long long int n)
{
	long long int temp;
	gl(i,0,n)
	{
	temp=1;
	while(a[i])
	{
	temp=temp*(a[i]%10);
	a[i]/=10;
	}
	a[i]=temp;
	}
}


prime construct_util(long long int node,long long int ss,long long int se)
{
	if(ss==se)
	{
		//printf("here\n");
		if(a[ss]==0)
		{
			tree[node].mask=(1<<4);			
		}
		else
		{
		tree[node].mask=0;
		long long int countp;
		countp=0;
		while(a[ss]%2==0)
		{
			a[ss]/=2;
			countp=1-countp;			
		}
		if(countp)
		tree[node].mask=tree[node].mask|(1<<0);
		countp=0;
		while(a[ss]%3==0)
		{
			a[ss]/=3;
			countp=1-countp;			
		}
		if(countp)
		tree[node].mask=tree[node].mask|(1<<1);
		countp=0;
		while(a[ss]%5==0)
		{
			a[ss]/=5;
			countp=1-countp;			
		}
		if(countp)
		tree[node].mask=tree[node].mask|(1<<2);
		countp=0;
		while(a[ss]%7==0)
		{
			a[ss]/=7;
			countp=1-countp;			
		}
		if(countp)
		tree[node].mask=tree[node].mask|(1<<3);
	  //  put1n(tree[node].mask);
		
		}
	    if(tree[node].mask==0||tree[node].mask==16)
	    {
	    	tree[node].cnt=1;	    	
	    }
return tree[node];
	}
	long long int mid=getmid(ss,se);
	tree[node]=construct_util(2*node+1,ss,mid)+construct_util(2*node+2,mid+1,se);
	return tree[node];	
}

//query type1->returns only sum of counts

long long int query1(long long int node,long long int ss,long long int se,long long int qs,long long int qe)
{
	if(ss>qe||se<qs||ss>se)
	{
	return 0; 
     }
	if(ss>=qs&&se<=qe)
	return tree[node].cnt;
	long long int mid=getmid(ss,se);
	return query1(2*node+1,ss,mid,qs,qe)+query1(2*node+2,mid+1,se,qs,qe);	
	
}


prime query2(long long int node,long long int ss,long long int se,long long int qs,long long int qe)
{
	if(ss>qe||se<qs||ss>se)
	{
		prime temp;
		temp.cnt=-1,temp.mask=-1;
	return temp; 
    }
	if(ss>=qs&&se<=qe)
	{

	//	printf("returning %d at node %d\n",(tree[node].mask),node);
	return tree[node];
    }
	long long int mid=getmid(ss,se);
	prime lhs,rhs;
	 lhs=query2(2*node+1,ss,mid,qs,qe);
	 rhs=query2(2*node+2,mid+1,se,qs,qe);
	 if(lhs.cnt==-1) return rhs;
	if(rhs.cnt==-1) return lhs;
 
	prime ans=lhs+rhs;
 
	return ans;	
}


void build_tree(long long int n)
{
prime temp=construct_util(0,0,n-1);

}


void update(long long int node,long long int ss,long long int se,long long int val,long long int index)
{
	if(ss>se||ss>index||se<index)
	return;
	//if(ss<=index&&se>=index)
	//{
		if(ss==se)
		{
			
		if(val==0)
		{
		//	printf("here at %d,%d\n",ss,se);
			tree[node].mask=(1<<4);			
		}
		else
		{
		tree[node].cnt=0,tree[node].mask=0;
		long long int countp;
		countp=0;
		while(val%2==0)
		{
	    val/=2;
		countp=1-countp;			
		}
		if(countp)
		tree[node].mask=tree[node].mask|(1<<0);
		countp=0;
		while(val%3==0)
		{
		val/=3;
		countp=1-countp;			
		}
		if(countp)
		tree[node].mask=tree[node].mask|(1<<1);
		countp=0;
		while(val%5==0)
		{
     	val/=5;
		countp=1-countp;			
		}
		if(countp)
		tree[node].mask=tree[node].mask|(1<<2);
		countp=0;
		while(val%7==0)
		{
		val/=7;
		countp=1-countp;			
		}
		if(countp)
		tree[node].mask=tree[node].mask|(1<<3);
	  //  put1n(tree[node].mask);
		
		}
	    if(tree[node].mask==0||tree[node].mask==(1<<4))
	    {
	   	tree[node].cnt=1;	    	
	    }
        return;
	    }			
			
		long long int mid=getmid(ss,se);
		update(2*node+1,ss,mid,val,index);
		update(2*node+2,mid+1,se,val,index);		
		tree[node]=tree[2*node+1]+tree[2*node+2];
//	}
	
}
long long int query3(long long int node,long long int ss,long long int se,long long int k)
{
	if(ss==se)
	{
		return se;
	}
	long long int mid=getmid(ss,se);
	long long int temp=tree[2*node+1].cnt-k;
	if(temp<0)
	{
		return query3(2*node+2,mid+1,se,abs(k));
	}
	else
	{
	    return query3(2*node+1,ss,mid,k);	
    }
}


int main()
{
	freopen("in.txt","r",stdin);
	long long int n,q;
	get2(n,q);
	gl(i,0,n)
	get1(a[i]);
	modify_array(n);
	//printA(a,0,n-1);
    ms(tree,0);
	build_tree(n);
	/*gl(i,0,9)
		printf("%d ",tree[i].cnt);
		pn*/
long long int a,x,y;
	while(q--)
	{
		get1(a);
		if(a==1)
		{
		get2(x,y);
		printf("%lld\n",query1(0,0,n-1,x,y));	
		}
		if(a==3)
		{
		get2(x,y);
		prime num=query2(0,0,n-1,x,y);
		if(num.mask==0||(num.mask==(1<<4)))
		printf("Yes\n");
		else
		printf("No\n");
		}
		if(a==2)
		{
		get2(x,y);	
		long long int val=1;
		if(y==0)
		val=0;
		while(y)
		{
		val=val*(y%10);
		y/=10;
		}
		/*gl(i,0,9)
		printf("%d ",tree[i].mask);
		pn*/
		update(0,0,n-1,val,x);
	/*gl(i,0,9)
		printf("%d ",tree[i].mask);
		pn*/
		}
		if(a==4)
		{
		get1(x);
		if(tree[0].cnt<x)
		printf("-1\n");
		else
		printf("%lld\n",query3(0,0,n-1,x));
		}
		
	}

	return 0;
}
