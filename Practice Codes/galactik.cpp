#include<stdio.h>
#include<string.h>
long int a[1000006],b[1000006];
long int weight[100005];
long int id[100005];
#define MAX 100004
 void make_set()
 {
 long int i;
for(i=1;i<=MAX;i++)
id[i]=i;//id means identity 
 }

long int root(long int i)
{
	if(i!=id[i])
	{
		id[i]=id[id[i]];//if any number(2) has id 3 but root of id is now 4 
		i=id[i];//compresses path of 2 to 4
	}
	return i;
}

inline void m_union(long int a,long int b)
{
	a=root(a);
	b=root(b);
id[a]=b;
	
}


int main()
{
	long int n,m,i=0,u,cost,sum,flag,count;
	memset(weight,-1,sizeof(weight));
	make_set();
	scanf("%ld%ld",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%ld%ld",&a[i],&b[i]);
	m_union(a[i],b[i]);	
}
		for(i=1;i<=n;i++)
	{
	scanf("%ld",&cost);	
	
	u=root(i);
	if(weight[u]==-1)
	{
		weight[u]==MAX,count++;
	}
	if(cost<weight[i])
	weight[u]=cost;
	
	if(cost<0)
	cost=MAX;
	}
	if(count==1)
	{
	printf("-1");
return 0;
}
flag=0;	
u=MAX;	
for(i=1;i<=n;i++)
	{
		if(weight[i]!=-1)
		{
			if(weight[i]==MAX){flag=1;break;}
			sum+=weight[i];
			u=weight[i]<u?weight[i]:u;
		}
	}
	if(flag)puts("-1\n");
	else printf("%ld",u*(count-2)+sum);
	return 0;
}
