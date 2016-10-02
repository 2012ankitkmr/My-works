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
#define get1(a) scanf("%d", &a) //next three are handy ways to get ints, it's also force you to use '&' sign
#define get2(a,b) scanf("%d%d", &a, &b)
#define get3(a,b,c) scanf("%d%d%d", &a, &b, &c)
#define wez(n) int (n); scanf("%d",&(n)); //handy if the input is right after the definition of a variable
#define wez2(n,m) int (n),(m); scanf("%d %d",&(n),&(m))
#define wez3(n,m,k) int (n),(m),(k); scanf("%d %d %d",&(n),&(m),&(k))
#define tests wez(testow)while(testow--) //for multilple cases problems
#define pn printf("\n");
#define put1n(x) printf("%d\n",x);
#define put1(x) printf("%d",x);
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
 
int mat[1003][1003],sum[1003][1003];
 
 
int getsum(int n,int m,int a,int b)
{
	int _sum = 0;
gl(i,m,m+b)
{
	
	if(n!=0)
	_sum+=(sum[n+a-1][i] - sum[n-1][i]);
	else
	_sum+=(sum[n+a-1][i]);
	
	//printf("%d\n",_sum);
}	
	return _sum;	
}
 
int updatesum(int n,int m,int a,int b,int _sum)
{
	if(n!=0)
	_sum-=(sum[n+a-1][m-1] - sum[n-1][m-1]);
	else
	_sum-=(sum[n+a-1][m-1]);
	
	if(n!=0)
	_sum+=(sum[n+a-1][m+b-1] - sum[n-1][m+b-1]);
	else
	_sum+=(sum[n+a-1][m+b-1]);
	
return _sum;
	
}
/* 
 
int getMid(int s, int e) {  return s + (e - s)/2;  }
 
void update(int *st,int ss,int se,int i,int val,int pos){
 
	if(i < ss || i > se)
 
	return;
 
	if(ss==se){
 
		st[pos] = val;
		return ;
 
	}
 
	int mid = getMid(ss, se);
 
	update(st,ss,mid,i,val,pos*2+1);
 
	update(st,mid+1,se,i,val,pos*2+2);
 
	st[pos]=max(st[2*pos+1],st[2*pos+2]);
 
}
 
 
 
int RMQUtil(int *st, int ss, int se, int qs, int qe, int index)
{
    if (qs <= ss && qe >= se)
        return st[index];
 
    if (se < qs || ss > qe)
        return INT_MIN;
 
    int mid = getMid(ss, se);
    return max(RMQUtil(st, ss, mid, qs, qe, 2*index+1),
                  RMQUtil(st, mid+1, se, qs, qe, 2*index+2));
}
 
int RMQ(int *st, int n, int qs, int qe)
{
    return RMQUtil(st, 0, n-1, qs, qe, 0);
}
 
 
int constructSTUtil(int arr[], int ss, int se, int *st, int si)
{
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }
    int mid = getMid(ss, se);
    st[si] =  max(constructSTUtil(arr, ss, mid, st, si*2+1),
                     constructSTUtil(arr, mid+1, se, st, si*2+2));
    return st[si];
}
 
int tree[1003][18004],temptree[18004];
int arr[1003][1003];
void constructST(int n,int m)
{
   gl(i,0,m)gl(j,0,n)arr[i][j] = mat[j][i];
   	
   gl(i,0,m)
   constructSTUtil(arr[i], 0, n-1, tree[i], 0);   
}
 
void constructtemptree(int arr[],int b)
{
	
	constructSTUtil(arr,0,b-1,temptree,0);
}
 */
 vector<int> max_sub_deque(int A[],int k,int m)
{
    deque<int> q;
    for(int i=0;i<k;i++)
    {
        while(!q.empty() && A[i] >= A[q.back()])
            q.pop_back();
        q.push_back(i);
    }
    vector<int> res;
    for(int i=k;i<m;i++)
    {
        res.push_back(A[q.front()]);
        while(!q.empty() && A[i] >= A[q.back()] )
            q.pop_back();
        while(!q.empty() && q.front() <= i-k)
            q.pop_front();
        q.push_back(i); 
    }
    res.push_back(A[q.front()]);
    return res;
}
vec maxmat[1003],arr(1003);
 
int main()
{
//	freopen("in.txt","r",stdin);
	int n,m,q,a,b,ans,max_elem,_sum,temparr[1003],up;
	
	get2(n,m);
	gl(i,0,n)gl(j,0,m)get1(mat[i][j]);
 
	gl(i,0,m)
	sum[0][i] = mat[0][i];
	
	gl(i,1,n)
	{
		gl(j,0,m)
		{
			sum[i][j] = sum[i-1][j] + mat[i][j];
		}	
	}
		//constructST(n,m);
	// construct max tree
 
	get1(q);
 
	while(q--)
	{
		get2(a,b);
		_sum = 0;
		ans = INT_MAX;
		
		for(int i = 0 ; i < n ;i++ )
		{
		maxmat[i] =  max_sub_deque(mat[i],b,m);	
		}
		
		for(int i = 0 ; i < m-b+1 ; i++ )
		{
			for(int j = 0; j < n ;j++)
			{
				temparr[j] = maxmat[j][i];
			}
			
		arr =  max_sub_deque(temparr,a,n);
		    
			for(int j = 0; j < n-a+1 ;j++)
			{
				maxmat[j][i] = arr[j];
			}	
		}
	/*	for(int i = 0 ; i < n-a+1 ; i++ )
		{
		   for(int j = 0; j < m-b+1 ;j++)
			{
				printf("%d ",maxmat[i][j]); 
			}	
		pn
		}
	*/	
		ge(i,0,n-a)
		{
			_sum = getsum(i,0,a,b);
		/*
		    gl(j,0,b)
		    {
		    	temparr[j] = RMQ(tree[j],n,i,i+a-1);
		    }
		    
			constructtemptree(temparr,b);
		    max_elem = RMQ(temptree,b,0,b-1);
 */
			ge(j,0,m-b)
			{
				
				if(j!=0)
				{
				_sum = updatesum(i,j,a,b,_sum);	
	
/*			    up = RMQ(tree[j+b-1],n,i,i+a-1);
	
			    update(temptree,0,b-1,(j-1)%b,up,0);
			    max_elem = RMQ(temptree,b,0,b-1);
 */
				}
				
				max_elem = maxmat[i][j];
				//_sum = 456;
				ans = min( max_elem * a * b - _sum ,  ans);
			}
			
		}
		
		printf("%d\n",ans);
	}
	
	return  0;
}
