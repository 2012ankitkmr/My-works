#include<bits/stdc++.h>
using namespace std;

int n,m;
bool visited[20004];

int compute()
{
queue<int>q;
q.push(n);
int cnt[20004];
for(int i = 0;i<=20000;i++)
cnt[i] = 455400554;
cnt[n]=0;
visited[n]=1;
while(!q.empty())
{
	int p = q.front();
	//printf("%d\n",p);

	q.pop();
	if(p==m)
	return cnt[p];
	if(p<=10000&&(!visited[2*p]))
	{
		q.push(2*p);
		visited[2*p]=1;
  cnt[2*p]= min(cnt[2*p],1+cnt[p]);

    }
    	if(p>0&&(!visited[p-1]))
	{
		q.push(p-1);
		visited[p-1]=1;
		        cnt[p-1]= min(cnt[p-1],1+cnt[p]);
    }

}
return 0;
}

int main()
{
	scanf("%d%d",&n,&m);
	cout<<compute();
	
	return  0;
}
