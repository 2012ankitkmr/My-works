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
#define MOD 1000000007
#define MOD_INV 500000004
 
int n,a[100005],b[100005];
int find_index_of_same_element()
{
	int ans;
	gl(i,0,n)
	{
		if(a[i]==b[0])
		{
		ans=i;
		break;
	}
	}
	return ans;
}
ll fact[100005];
ll ifact[100005];
void find_factorials(int n)
{
	fact[0]=1;
	ifact[0]=1;
	fact[1]=1;
	ifact[1]=1;
	ge(i,2,n)
	{
		fact[i]=(fact[i-1]*i)%MOD;
		ifact[i]=(fact[i]*MOD_INV)%MOD;
	}
	
}
 
 
struct node
{
    int ki;
    struct node *left;
    struct node *right;
    int height;
    int size; // size of the tree rooted with this node
};
 
int height(struct node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}
 
int size(struct node *N)
{
    if (N == NULL)
        return 0;
    return N->size;
}
struct node* newNode(int ki)
{
    struct node* node = (struct node*)
                        malloc(sizeof(struct node));
    node->ki   = ki;
    node->left   = NULL;
    node->right  = NULL;
    node->height = 1;  // new node is initially added at leaf
    node->size = 1;
    return(node);
}
 
// A utility function to right rotate subtree rooted with y
struct node *rR(struct node *y)
{
    struct node *x = y->left;
    struct node *T2 = x->right;
 
    // Perform rotation
    x->right = y;
    y->left = T2;
 
    // Update heights
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;
 
    // Update sizes
    y->size = size(y->left) + size(y->right) + 1;
    x->size = size(x->left) + size(x->right) + 1;
 
    // Return new root
    return x;
}
 
// A utility function to left rotate subtree rooted with x
struct node *lR(struct node *x)
{
    struct node *y = x->right;
    struct node *T2 = y->left;
 
    // Perform rotation
    y->left = x;
    x->right = T2;
 
    //  Update heights
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;
 
    // Update sizes
    x->size = size(x->left) + size(x->right) + 1;
    y->size = size(y->left) + size(y->right) + 1;
 
    // Return new root
    return y;
}
 
// Get Balance factor of node N
int getBalance(struct node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}
struct node* insert(struct node* node, int ki, int *count)
{
    /* 1.  Perform the normal BST rotation */
    if (node == NULL)
        return(newNode(ki));
 
    if (ki < node->ki)
        node->left  = insert(node->left, ki, count);
    else
    {
        node->right = insert(node->right, ki, count);
 
        // UPDATE COUNT OF SMALLER ELEMENTS FOR ki
        *count = *count + size(node->left) + 1;
    }
    node->height = max(height(node->left), height(node->right)) + 1;
    node->size   = size(node->left) + size(node->right) + 1;
 
    int balance = getBalance(node);
 
    // If this node becomes unbalanced, then there are 4 cases
 
    // Left Left Case
    if (balance > 1 && ki < node->left->ki)
        return rR(node);
 
    // Right Right Case
    if (balance < -1 && ki > node->right->ki)
        return lR(node);
 
    // Left Right Case
    if (balance > 1 && ki > node->left->ki)
    {
        node->left =  lR(node->left);
        return rR(node);
    }
 
    // Right Left Case
    if (balance < -1 && ki < node->right->ki)
    {
        node->right = rR(node->right);
        return lR(node);
    }
 
    /* return the (unchanged) node pointer */
    return node;
}
 void cRA(int arr[], int countSmaller[], int n)
{
  int i, j;
  struct node *root = NULL;
 
  // initialize all the counts in countSmaller array as 0
  for  (i = 0; i < n; i++)
     countSmaller[i] = 0;
 
  // Starting from rightmost element, insert all elements one by one in
  // an AVL tree and get the count of smaller elements
  for (i = n-1; i >= 0; i--)
  {
     root = insert(root, arr[i], &countSmaller[i]);
  }
}
 
 
 
int suffix[100005];
void suffix_sum(int n)
{
	ms(suffix,0);
	suffix[n-1]=0;
	
cRA(b,suffix, n);	
//printA(suffix,0,n-1);
}
int fl;
ll find_lexicographical_order()
{
	suffix_sum(n);
	ll ans=MOD_INV;
	gl(i,0,n-2)
	{
	ans=(ans+(ifact[n-i-1]*suffix[i])%MOD)%MOD;
	//put2n(ifact[n-i-1],suffix[i]);
	}
	return ans;
}
ll find_lexicographical_order_()
{
	ll temp;
	suffix_sum(n);
	ll ans=1;
	gl(i,0,n)
	{
	ans=(ans+(fact[n-i-1]*suffix[i])%MOD)%MOD;
	}
	return ans;
}
ll cnt;
void merge(int arr[],int temp[],int left,int mid,int right)
{
    int i=left;
    int j=mid;
    int k=left;
    //printf("(%d,%d,%d)\n",left,mid,right);
    while((i<=mid-1) && (j<=right))
    {
        if(arr[i]<=arr[j])
        temp[k++]=arr[i++];
        else
        {
            temp[k++]=arr[j++];
           cnt+=(mid-i);
           //printf("%d%d\n",mid,i);
        }
    }
    while(i<=mid-1)
    temp[k++]=arr[i++];
    while(j<=right)
    temp[k++]=arr[j++];
    for(int i=left;i<=right;i++)
    arr[i]=temp[i];
    
}
void mergesort( int arr[],int temp[],int left,int right)
{
    
    if(right>left){
        int mid=(left+right)/2;
        mergesort(arr,temp,left,mid);
        mergesort(arr,temp,mid+1,right);
        merge(arr,temp,left,mid+1,right);
               }
    
}
int find_parity(int arr[])
{
	cnt=0;
	int temp[100005];
	ms(temp,0);
	mergesort(arr,temp,0,n-1);
//	put1n(cnt);
	return cnt;
}
int temp1[100005];
 
 
 
int main()
{
int k,x,flag=0,sigma1,sigma2;
ll ans;
find_factorials(100001);
//freopen("in.txt","r",stdin);
 
tests
{
	get2(n,k);
	gl(i,0,n)
	get1(a[i]);
	gl(i,0,n)
	get1(b[i]);
 
if(k==n)
{
	flag=0;
	x=find_index_of_same_element();
	gl(i,x,n)
	{
		if(a[i]!=b[i-x])
		flag=1;
	}
	gl(i,0,x)
	{
		if(a[i]!=b[n-x+i])
		flag=1;
	}
	
	
	if(flag)
	printf("-1\n");
	else
   {
	printf("%d\n",b[0]);						
   }
}
 
else if(k%2==0)
{
ans=find_lexicographical_order_();	
printf("%lld\n",ans);	
}
else
{
	gl(i,0,n)
	temp1[i]=b[i];
	sigma1=find_parity(a);
	sigma1=(sigma1%2==0?1:-1);
	sigma2=find_parity(temp1);
	sigma2=(sigma2%2==0?1:-1);
	if(sigma1!=sigma2)
	printf("-1\n");
	else
	{
		fl=0;
	
		ans=find_lexicographical_order();
		//printf("ans=%lld\n",ans);
		//sigma1=ans&1;
		ans=(ans+MOD_INV)%MOD;
		printf("%lld\n",ans);
	      
	}
}
 
}
	return 0;
}
