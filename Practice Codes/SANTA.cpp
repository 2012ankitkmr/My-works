#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int N = 1000000;
struct node{
	ll type[26];
}a[4000000];

int getmid(int a,int b)
{
	return a+(b-a)/2;
}
void update(int ss,int se,int ind,int node,int val,int tp)
{
	if(ss>ind||se<ind)
	return;

a[node].type[tp]+=val;
if(ss!=se)
{
int mid = getmid(ss,se);
update(ss,mid,ind,node*2+1,val,tp);
update(mid+1,se,ind,node*2+2,val,tp);
}
}

ll query(int node,int ss,int se,int qs,int qe,int tp)
{
	if(ss>=qs&&se<=qe)
	return a[node].type[tp];
	
	if(ss>qe||se<qs)
	return 0;
	
	int mid= getmid(ss,se);
	return query(node*2+1,ss,mid,qs,qe,tp)+query(node*2+2,mid+1,se,qs,qe,tp);
	
}

int main()
{
	//freopen("in.txt","r+",stdin);
	int q,c,n,m,x;
	char p;
	cin>>q;
	while(q--)
	{
		scanf("%d",&c);
		if(c==1)
		{
			scanf("%d%d %c",&m,&x,&p);
			//printf("here %c\n ",p);
			update(0,N-1,m-1,0,x,p-'a');
			
			
		}
		else
		{
			scanf("%d%d %c",&m,&n,&p);
			printf("%lld\n",query(0,0,N-1,m-1,n-1,p-'a'));
		}
		
	}
	
	return 0;
}
