#include<stdio.h>
#include<algorithm>
#include<queue>
#include<string.h>
//////////definitions
#define he cout<<"HERE"<<endl;
#define ones7 1111111
#define ones6 111111
#define ones5 11111
#define ge getch();
#define pi pair<int,int>
#define pii pair<pi,int>
#define mii map<int,int>
#define ff first
#define ss second
#define vi vector<int>
#define sti set<int>
#define qui queue<int>
#define l long
#define ll long long
#define qull queue<ll>
#define vill vector<ll>
#define stll set<ll>
#define mll map<ll,ll>
#define forr(i,n) for(int i=0;i<n;i++)
#define forrr(i,j,n) for(int i=j;i<n;i++)
#define forrb(i,n) for(int i=n;i>0;i--)
#define forrrb(i,n,v)  for(int i=n;i>v;i--)
#define s(n) scanf("%d",&n);
#define p(n) printf("%d\n",n);
#define sll(n) scanf("%lld",&n);
#define pll(n) printf("%lld\n",n);
#define c(n) cin>>n;
#define pause system("pause");
#define set(a,val) memset(a,val,sizeof a);
#define pb push_back
#define co(n) cout<<n<<endl;
#define MOD 1000000007
#define INF 1000000007
#define foreach(it,container) for(typeof(container.begin()) it=container.begin() ; it!=container.end() ; it++)
#define NAME "problem"

using namespace std;
inline int max_(int a,int b)
{
    if(a>=b)
    {
        return a;
    }
    else return b;
}
inline int min_(int a,int b)
{
    if(a>=b)
    {
        return b;
    }
    else
    {
        return a;
    }
}

int dx[] = {0, 1, 0, -1};
int dx2[] = {0, 1, 0, -1,1,-1,1,-1};
int dy[] = {1, 0, -1, 0};
int dy2[] = {1, 0, -1, 0,1,-1,-1,1};

int arr[4][222][222];
int N;
int M;
int a[222][222];
pi pos[5];

inline int check(int x,int y)
{
    if(x<N &&  x>=0 && y<M && y>=0 &&  a[x][y]!=-1)
    {
        return 1;
    }
    return 0;
}

int T;

int bfs(pi start , int v)
{
    queue<pi> Q;
    int visit[N+3][M+3];
    for (int i=0; i<N+4; i++)
    {
        for (int j=0; j<M+3; j++)
        {
            arr[v][i][j]=111111;
        }
    }
    Q.push(start);
    int newx,newy;
    pi ini;
    arr[v][start.ff][start.ss]=0;
    while(!Q.empty())
    {
        ini=Q.front();
        Q.pop();
        int x=ini.ff;
        int y=ini.ss;
        forr(j,4)
        {
            newx=x+dx[j];
            newy=y+dy[j];
            if(check(newx,newy)==0)
            {
                continue;
            }
            if(arr[v][newx][newy]>arr[v][x][y]+1 )
            {
                arr[v][newx][newy]=arr[v][x][y]+1;

                Q.push(pi(newx,newy));
            }
        }
    }
    return 0;
}

int main()
{
#ifndef ONLINE_JUDGE
    //generatetests(1000);
    freopen("in.txt","r",stdin);
#endif
    s(T);
    int tot=0;
    while(T--)
    {
        s(N) s(M) tot=0;
        forr(i,N+2)
        {
            if(i==0 || i==N+1)
            {
                for (int j=0;j<M+2;j++)
                {
                  a[i][j]=0;
                }
                continue;
            }
            char str[11111];
            str[0]='.';
            scanf("%s",str+1);
            str[strlen(str)]='.';
            forr(j,M+2)
            {
                if(str[j]=='1' || str[j]=='2' || str[j]=='3')
                {
                    pos[tot++]=pi(i,j);
                    a[i][j]=1;
                    continue;
                }
                if(str[j]=='#')
                {
                    a[i][j]=-1;
                }
                else
                {
                    a[i][j]=1;
                }
            }
        }
        N=N+2;
        M=M+2;
        forr(i,tot)
        {
            bfs(pos[i],i);
        }
        int answer=111111111;
        int vall;
        forr(i,N)
        {
            forr(j,M)
            {
                if(a[i][j]==-1) continue;
                vall=max_(arr[0][i][j],max_(arr[1][i][j],arr[2][i][j]));
                answer=min_(answer,vall);
            }
        }
        p(answer)
    }
    return 0;
}
