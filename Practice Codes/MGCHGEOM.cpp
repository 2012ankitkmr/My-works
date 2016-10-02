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
#define get2(a,b) scanf("%ld%ld", &a, &b)
#define get3(a,b,c) scanf("%ld%ld%ld", &a, &b, &c)
#define wez(n) long long (n); scanf("%lld",&(n)); //handy if the input is right after the definition of a variable
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


struct Point
{
    ll x, y;
    bool operator==(const Point&a) const
    {
      return x==a.x&&y==a.y;
    }
     bool operator<(const Point&a) const
    {
    	if(x==a.x)
    	return y<a.y;
    	return x<a.x;
    }
};


vector<Point>hull;

 
ll orientation(Point p, Point q, Point r)
{
    ll val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);
 
    if (val == 0) return 0;  // colinear
    return (val > 0)? 1: 2; // clock or counterclock wise
}
Point p0;
 
Point nextToTop(stack<Point> &S)
{
    Point p = S.top();
    S.pop();
    Point res = S.top();
    S.push(p);
    return res;
}
 

ll swap(Point &p1, Point &p2)
{
    Point temp = p1;
    p1 = p2;
    p2 = temp;
}
 

ll distSq(Point p1, Point p2)
{
    return (p1.x - p2.x)*(p1.x - p2.x) +
          (p1.y - p2.y)*(p1.y - p2.y);
}
 

int compare(const void *vp1, const void *vp2)
{
   Point *p1 = (Point *)vp1;
   Point *p2 = (Point *)vp2;
 
   // Find orientation
   ll o = orientation(p0, *p1, *p2);
   if (o == 0)
     return (distSq(p0, *p2) >= distSq(p0, *p1))? -1 : 1;
 
   return (o == 2)? -1: 1;
}

int compare2(Point *p1, Point *p2)
{
    // Find orientation
   ll o = orientation(p0, *p1, *p2);
   if (o == 0)
     return (distSq(p0, *p2) >= distSq(p0, *p1))? -1 : 1;
 
   return (o == 2)? -1: 1;
} 
	Point points[100005];
void convexHull(vector<Point>pts, ll n)
{

	for(ll i = 0 ;i<pts.size();i++)
	points[i] = pts[i];
	
   // Find the bottommost poll
   ll ymin = points[0].y, min = 0;
   for (ll i = 1; i < n; i++)
   {
     ll y = points[i].y;
 
     // Pick the bottom-most or chose the left
     // most point in case of tie
     if ((y < ymin) || (ymin == y &&
         points[i].x < points[min].x))
        ymin = points[i].y, min = i;
   }
 
   // Place the bottom-most point at first position
   swap(points[0], points[min]);


   p0 = points[0];
   qsort(&points[1], n-1, sizeof(Point), compare);
 
   ll m = 1; // Initialize size of modified array
   for (ll i=1; i<n; i++)
   {
       // Keep removing i while angle of i and i+1 is same
       // with respect to p0
       while (i < n-1 && orientation(p0, points[i],
                                    points[i+1]) == 0)
          i++;
 
 
       points[m] = points[i];
       m++;  // Update size of modified array
   }
 
   // If modified array of points has less than 3 points,
   // convex hull is not possible
   if (m < 3)
   {
   	hull.push_back(points[0]);
   	return;
   };

   // Create an empty stack and push first three points
   // to it.
   stack<Point> S;
   S.push(points[0]);
   S.push(points[1]);
   S.push(points[2]);
 
   // Process remaining n-3 points
   for (int i = 3; i < m; i++)
   {
      // Keep removing top while the angle formed by
      // points next-to-top, top, and points[i] makes
      // a non-left turn
      while (orientation(nextToTop(S), S.top(), points[i]) != 2)
         S.pop();
      S.push(points[i]);
   }
 
   // Now stack has the output points, print contents of stack
   
   while (!S.empty())
   {
    p0 = S.top();
    hull.push_back(p0);
    S.pop();
   }
    //printf("here\n");
}


void convexHull2(vector<Point>points, ll n)
{
	
   // Find the bottommost poll
   ll ymin = points[0].y, min = 0;
 /*  for (ll i = 1; i < n; i++)
   {
     ll y = points[i].y;
 
     // Pick the bottom-most or chose the left
     // most point in case of tie
     if ((y < ymin) || (ymin == y &&
         points[i].x < points[min].x))
        ymin = points[i].y, min = i;
   }*/
    ll y = points[n-1].y; 
 if ((y < ymin) || (ymin == y && points[n-1].x < points[min].x))
           min = n-1;
   // Place the bottom-most point at first position
   swap(points[0], points[min]);
   ge(i,1,n-2)
   {
   	if(compare2(&points[i],&points[n-1])==1)
   	{
   		Point temp = points[i+1],temp1;
   		points[i+1]=points[n-1];
   		ge(j,i+2,n-1)
   		{
   			temp1 = points[j];
   		points[j]=temp;
   		temp = temp1;
     	}
     	break;
    	}
   }
   


   p0 = points[0];
  // qsort(&points[1], n-1, sizeof(Point), compare);
  
 
   ll m = 1; // Initialize size of modified array
   for (ll i=1; i<n; i++)
   {
       // Keep removing i while angle of i and i+1 is same
       // with respect to p0
       while (i < n-1 && orientation(p0, points[i],
                                    points[i+1]) == 0)
          i++;
 
 
       points[m] = points[i];
       m++;  // Update size of modified array
   }
 
   // If modified array of points has less than 3 points,
   // convex hull is not possible
   if (m < 3)
   {
   	hull.push_back(points[0]);
   	return;
   };

   // Create an empty stack and push first three points
   // to it.
   stack<Point> S;
   S.push(points[0]);
   S.push(points[1]);
   S.push(points[2]);
 
   // Process remaining n-3 points
   for (int i = 3; i < m; i++)
   {
      // Keep removing top while the angle formed by
      // points next-to-top, top, and points[i] makes
      // a non-left turn
      while (orientation(nextToTop(S), S.top(), points[i]) != 2)
         S.pop();
      S.push(points[i]);
   }
 
   // Now stack has the output points, print contents of stack
   
   while (!S.empty())
   {
    p0 = S.top();
    hull.push_back(p0);
    S.pop();
   }
    //printf("here\n");
}


double polygonArea(vector<Point>hull, ll n)
{
    double area = 0.0;
 
    // Calculate value of shoelace formula
    ll j = n - 1;
    for (int i = 0; i < n; i++)
    {
        area += ((double)hull[j].x + (double)hull[i].x) * ((double)hull[j].y - (double)hull[i].y);
        
        j = i;  // j is previous vertex to i
    }
 
    // Return absolute value
    return abs(area / 2.0);
}

vector<Point> temp;
vector<Point>pt;
map<Point,ll>mymap;
int main()
{
	freopen("in.txt","r",stdin);
	ll n,xc,yc;
	char ch;
	Point p;
	double area;
	tests
	{
		temp.clear();
		pt.clear();
		mymap.clear();
		area = 0.0;
	
		get1(n);
		gl(i,0,n)
		{

			cin>>ch;
			

			cin>>xc>>yc;

			if(ch=='+')
			{	
			p.x = xc;
			p.y = yc;	
			//cout<<p.x<<" "<<p.y<<endl;
			
			if(mymap[p])
			{
				
			mymap[p]++;	
			}
			else
			{
			area = 0.0;
			pt.pb(p);
			mymap[p] = 1;
	     	}
			//cout<<myset.size();
			if(pt.size()<3)
			printf("0.0\n");
			
			else
			{
				if(area==0.0)
				{
				
				hull.clear();

				convexHull2(pt,pt.size());
				area = polygonArea(hull,hull.size());
				}
				printf("%.1lf\n",area);
			}	
				
			}
			else
			{
			//	printf("here\n");
			p.x = xc;
			p.y = yc;
			if(mymap[p]==1)
			{
				temp.clear();
				for(int j = 0 ;j < pt.size() ;j++)
				{
					if(!(pt[j]==p))
					temp.push_back(pt[j]);
				}
				pt.clear();
				for(int j = 0 ;j < temp.size() ;j++)
				{	
					pt.push_back(temp[j]);
				}
			//myset.erase(p);
	    	mymap[p]--;
	     	area = 0.0;
			 }
			else
			mymap[p]--;
		
			if(pt.size()<3)
			printf("0.0\n");
			else
			{
				if(area==0.0)
				{
				
			    hull.clear();

				 convexHull(pt,pt.size());
				area = polygonArea(hull,hull.size());
				}
				printf("%.1lf\n",area);
			}	
				
			}
		}
		
	}
	
	return  0;
}
