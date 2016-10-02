#include<iostream>
#include<stdio.h>
#include<functional>
#include<algorithm>
#include<math.h>
#include<limits.h>

#include<set>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<deque>

#include<cstring>
#include<string>


#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define lli long long int
#define mod1 1000000007
#define mod2 1000000009
#define ppi pair<int,int>
#define tr(a,it) for(typeof(a.begin()) it=a.begin();it!=a.end();it++)

using namespace std;

int segtree[10000000][3],ar[10000000];
int lazy[10000000];
int st[1000000][3];

int build(int node,int a,int b)
{
    if(a==b)
    {
            lazy[node]=0;
            FOR(i,0,2)segtree[node][i]=0;
            segtree[node][ar[a]%3]++;
            return 0;
    }

    int mid=(a+b)/2;

    build(2*node,a,mid);
    build(2*node+1,mid+1,b);
    lazy[node]=0;
    FOR(i,0,2)segtree[node][i]=segtree[2*node+1][i]+segtree[2*node][i];
    return 0;
}

int update(int node,int a,int b,int x,int y,int k)
{
    if(x>b||y<a)return 0;

    if(x<=a&&b<=y)
    {
                  FOR(i,0,2)st[node][i]=segtree[node][i];

                  FOR(i,0,2)segtree[node][i]=0;
                  lazy[node]+=k;
                  FOR(i,0,2)segtree[node][i]=st[node][(i%3-lazy[node]%3+3)%3];

                  if(a!=b)
                  {
                  lazy[2*node]+=lazy[node];
                  lazy[2*node+1]+=lazy[node];
                  }
                  lazy[node]=0;
                  return 0;
    }

    lazy[2*node]+=lazy[node];
    lazy[2*node+1]+=lazy[node];
    lazy[node]=0;

    int mid=(a+b)/2;
    update(2*node,a,mid,x,y,k);
    update(2*node+1,mid+1,b,x,y,k);

    FOR(i,0,2)segtree[node][i]=segtree[2*node][i]+segtree[2*node+1][i];

    return 0;
}

int query(int node,int a,int b,int x,int y,int j)
{
    if(x>b||y<a)return 0;

    if(x<=a&&b<=y)
    {
                  return segtree[node][(j%3-lazy[node]%3)%3];
    }

    int mid=(a+b)/2;

    lazy[2*node]+=lazy[node];
    lazy[2*node+1]+=lazy[node];
    lazy[node]=0;

    int q1=query(2*node,a,mid,x,y,j);
    int q2=query(2*node+1,mid+1,b,x,y,j);

    FOR(i,0,2)segtree[node][i]=segtree[2*node][(i%3-lazy[2*node]%3)%3]+segtree[2*node+1][(i%3-lazy[2*node+1]%3)%3];

    return q1+q2;

}

int main()
{
    ios_base::sync_with_stdio(false);
    int n,p;
    cin>>n>>p;

    char ch[n];

    cin>>ch;

    ar[0]=0;

    FOR(i,1,n)ar[i]=(ar[i-1]+(ch[i-1]-'1'+1))%3;

    FOR(i,0,2)build(1,0,n);

    while(p--)
    {
          int x,l,r;

          cin>>x>>l>>r;

          if(x==1)
          {
                  int k=(r%3 -ar[l]%3+3)%3;

                  update(1,0,n,l,n,k);

          }
          else
          {
              lli ans=0;

              FOR(i,0,2)
              {
                        int q1=query(1,0,n,l-1,r,i);
                        ans+=((lli)(q1)*(lli)(q1-1)/2);
              }
              cout<<ans<<endl;
          }
    }

    return 0;
}
