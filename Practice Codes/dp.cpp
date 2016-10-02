#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
#define ll long long
#define ull unsigned long long
#define inf 1000000007
#define mod 1000000007
#define pii pair<int,int>
#define vi vector<int>
#define VS vector<string>
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define N 200010
#define pi 3.14159265358979323846
#define DBG(vari) cerr<<#vari<<"="<<(vari)<<endl;
#define FOREACH(i,t) for(__typeof(t.begin()) i=t.begin();i!=t.end();i++)
#define MOD 1000000007
 #define FOR(i,a,b) for(int i=a;i<=b;++i)
// suffix array code is taken from 3rd party code
// http://w...content-available-to-author-only...f.com/viewplaintext/3927088
//http://d...content-available-to-author-only...f.com/questions/43060/anusar-editorial
// suffix array O(log^2(N)) algorithm.
struct node
{
	int ch[26],fail,len,v;
	void init()
	{
		memset(ch,0,sizeof(ch));
		fail=-1;len=0;v=1;
	}
}t[N*10];
int sz;
void add(char *s)
{
	int ed=0,i,j;
	for(i=0;s[i];i++)
	{
		j=s[i]-'a';
		int p=++sz;t[p].init();t[p].len=t[ed].len+1;
		while(ed>=0&&!t[ed].ch[j])t[ed].ch[j]=p,ed=t[ed].fail;
		if(ed==-1){t[p].fail=0;ed=p;continue;}
		int q=t[ed].ch[j];
		if(t[q].len==t[ed].len+1)t[p].fail=q;
		else
		{
			int r=++sz;t[r]=t[q];t[r].len=t[ed].len+1;
			t[p].fail=t[q].fail=r;t[r].v=0;
			while(ed>=0&&t[ed].ch[j]==q)t[ed].ch[j]=r,ed=t[ed].fail;
		}
		ed=p;
	}
}
int id[N*10];ll cnt[N*10],ans[N];char s[N];
bool cmp(int i,int j)
{
	return t[i].len>t[j].len;
}
void solve(int n)
{
	int i,j,k;
	//n=strlen(s);
	for(i=0;i<=sz;i++)id[i]=i,cnt[i]=0;
	for(i=0;i<=n;i++)ans[i]=0;
	sort(id,id+sz+1,cmp);
	for(k=0;k<=sz;k++)
	{
		i=id[k];
		if(t[i].v)cnt[i]++;
		
		j=t[i].fail;
		ll v=(ll)(t[i].len-t[j].len)*cnt[i];
		ans[1]+=v;if(cnt[i]+1<=n)ans[cnt[i]+1]-=v;
		
		cnt[j]+=cnt[i];
	}
	for(i=1;i<=n;i++)ans[i]+=ans[i-1];
}
 
 
long long cntA[5005];
void solve2(int n)
{
	int i,j,T,k,m;
	T = 1;
	while(T--)
	{
		//n=strlen(s);
		t[0].init();sz=0;
		add(s);
		m = n;
		solve(n);
		for(i=1;i<=n;i++)
		{
			cntA[i] = ans[i];
		}
		for(int i=2;i<n;i++)
        {
            cntA[i] = cntA[i] - cntA[i+1];
        }
        cntA[0] = 0;
        for(int i=1;i<=n;i++)
        {
            cntA[i] /= i;
        }
	}
}
 
int main()
{
    static long long ncr[5005][5005];
    //long long INV[5005];
  ncr[0][0]=1;
	FOR(i,1,5001)
	  {
	  	ncr[i][0]=1;
	  	FOR(j,1,i)
	  	ncr[i][j]=(ncr[i-1][j-1]+ncr[i-1][j])%MOD;
	  }
    int t;
    scanf("%d",&t);
 
    while(t--)
    {
        int n,q;
        scanf("%d%d",&n,&q);
    
        scanf("%s",s);
    
        solve2(n);
      
        long long ans[5005] = {0};
        ans[1] = cntA[1];
 
        vector<int> v;
        for(int i=2;i<=n;i++)
        {
            if(cntA[i])
            v.push_back(i);
        }
 long int y=v.size();
        for(int i=2;i<=n;i++)
        {
            //cout<<cntA[i]<<" ";
            long long sum = 0;
            for(int ind=0;ind<y;ind++)
            {
                int j = v[ind];
                
                sum = (sum + (cntA[j] * (i>j?0:ncr[j][i])))%MOD;
                  // cout<<ncr[j][i]<<endl;          
		    }
           // cout<<sum<<endl;
            ans[i] = sum;
        }
  //      int chk = 0;
        //assert(0);
        for(int i=0;i<q;i++)
        {
 
            int temp;
            cin>>temp;
            int aa;
           
            if(temp==1)
            aa=((n*(n+1))/2)%MOD;
            else if(temp <= n)
            aa = ans[temp];
            else if(temp>=n)
            aa = 0;
 
            cout<<aa<<endl;
            //assert(0);
 
        }
 
    }
    return 0;
}

