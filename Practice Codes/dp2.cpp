/*source http://www.geeksforgeeks.org/suffix-array-set-1-introduction/*/
#include<bits/stdc++.h>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;
#define NMAX 200005
#define MOD 1000000007

struct suffixnode
{
	int ch[26],fail,len,v;
	void init()
	{
		memset(ch,0,sizeof(ch));
		fail=-1;len=0;v=1;
	}
}node[NMAX*10];
int it;
void add(char *s)
{
	int edit=0,i,j;
	for(i=0;s[i];i++)
	{
		j=s[i]-'a';
		int p=++it;node[p].init();node[p].len=node[edit].len+1;
		while(edit>=0&&!node[edit].ch[j])node[edit].ch[j]=p,edit=node[edit].fail;
		if(edit==-1){node[p].fail=0;edit=p;continue;}
		int q=node[edit].ch[j];
		if(node[q].len==node[edit].len+1)node[p].fail=q;
		else
		{
			int r=++it;node[r]=node[q];node[r].len=node[edit].len+1;
			node[p].fail=node[q].fail=r;node[r].v=0;
			while(edit>=0&&node[edit].ch[j]==q)node[edit].ch[j]=r,edit=node[edit].fail;
		}
		edit=p;
	}
}
int id[NMAX*10];
long long int counter[NMAX*10],sum[NMAX];char s[NMAX];
bool cmp(int i,int j)
{
	return node[i].len>node[j].len;
}
void suffix(int n)
{
	int i,j,k;
	//n=strlen(s);
	for(i=0;i<=it;i++)id[i]=i,counter[i]=0;
	for(i=0;i<=n;i++)sum[i]=0;
	sort(id,id+it+1,cmp);
	for(k=0;k<=it;k++)
	{
		i=id[k];
		if(node[i].v)counter[i]++;
		
		j=node[i].fail;
		long long int v=(long long int)(node[i].len-node[j].len)*counter[i];
		sum[1]+=v;if(counter[i]+1<=n)sum[counter[i]+1]-=v;
		
		counter[j]+=counter[i];
	}
	for(i=1;i<=n;i++)sum[i]+=sum[i-1];
}
 
 
long long arr[5005];
void compute(int n)
{
	int i,T;
	T = 1;
	while(T--)
	{
		//n=snoderlen(s);
		node[0].init();it=0;
		add(s);
		suffix(n);
		for(i=1;i<=n;i++)
		{
			arr[i] = sum[i];
		}
		for(int i=2;i<n;i++)
        {
            arr[i] = arr[i] - arr[i+1];
        }
        arr[0] = 0;
        for(int i=1;i<=n;i++)
        {
            arr[i] /= i;
        }
	}
}
 long long precomputation[5005][5005];
int main()
{    
  precomputation[0][0]=1;
	for(int i=1;i<=5001;++i)
	  {
	  	precomputation[i][0]=1;
	  	for(int j=1;j<=i;++j)
	  	precomputation[i][j]=(precomputation[i-1][j-1]+precomputation[i-1][j])%MOD;
	  }
    int t;
   
 
    for( scanf("%d",&t);t--;)
    {
        int n,q;
        scanf("%d%d",&n,&q);
    scanf("*%c");
        scanf("%s",s);
    
        compute(n);
    
        long long sum[5005] = {0};
        sum[1] = arr[1];
 
        vector<int> indexing;
        for(int i=2;i<=n;i++)
        {
            if(arr[i])
            indexing.push_back(i);
        }
 long int u=indexing.size();
		for(int i=2;i<=n;i++)
        {
            //cout<<arr[i]<<" ";
        sum[i] = 0;
            for(int in=0;in<u;in++)
            {
                int j = indexing[in];
                if(i<=j)
                sum[i] = (sum[i] + (arr[j] *precomputation[j][i]))%MOD;
                    
			}   

            
        }
      while(q--)
        {
 
            int tmp;
            cin>>tmp;
           long int ans;
           
            if(tmp==1)
            ans=((n*(n+1))/2)%MOD;
            else if(tmp <= n)
            ans = sum[tmp];
            else if(tmp>=n)
            ans = 0;
 
            cout<<ans<<"\n";
         
 
        }
 
    }
    return 0;
}
  
