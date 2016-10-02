#include<bits/stdc++.h>
using namespace std;

vector <int> rbnode[100005] , ans ;
bool bits[100005];
bool reqbits[100005];

// 0 is black color
// 1  is red color
void dfs(int prevnode , int a , int countb , int countr , int color)
{
	if(color == 0)
	{
		if(countb)
		bits[a] = 1 - bits[a];
	}
	
	if(color == 1)
	{
		if(countr)
		bits[a] = 1 - bits[a];
	}
	int flag = 0; 
	if(reqbits[a] != bits[a])
	{
		flag = 1;
		ans.push_back(a);
		bits[a] = 1 - bits[a]; 
		
	}		
	
	
	for(int i = 0 ; i < rbnode[a].size() ; i++ )
	{
		if(prevnode != rbnode[a][i])
		{
			//printf("going from %d to %d\n",a,rbnode[a][i]);
			
			if(flag)
			{
			if(color == 0)
			dfs(a , rbnode[a][i] , 1 - countb , countr, 1 - color);
			
			else
			dfs(a , rbnode[a][i] , countb , 1 - countr, 1 - color);	
		
			}
			else
		    dfs(a , rbnode[a][i] , countb , countr, 1 - color );		
						
		}
		
	}
	
}

int main()
{

int n , a , b  ;
//freopen("in.txt","r",stdin);
scanf("%d",&n);

for(int i = 0 ; i < n - 1 ; i++ )
{
	scanf("%d%d", &a , &b );
	
	rbnode[b].push_back(a);
	rbnode[a].push_back(b);
	
	//color[a] = 1 - color[b];
}

for(int i = 1 ; i <= n ; i++)
scanf("%d",&bits[i]);	

for(int i = 1 ; i <= n ; i++)
scanf("%d",&reqbits[i]);	

dfs(0,1,0,0,0);

printf("%d\n",ans.size());

for(int i = 0 ; i < ans.size(); i++)
printf("%d\n",ans[i]);

	return  0;
}
