#include<bits/stdc++.h>
#include<queue>
using namespace std;
bool matrix[100][100];

bool snakespath[31];
bool visited[100];
queue<int>path;

void createladders(int size)
{
	int i,x,y;
	for(i=0;i<size;i++)
	{
		printf("Enter the numbers between which the ladders exists : ");
		scanf("%d%d",&x,&y);
		matrix[x>y?y:x][x>y?x:y]=1;
	}
	
}

void createsnakes(int size)
{
	int i,x,y;
	for(i=0;i<size;i++)
	{
		printf("Enter the numbers between which the snakes exists : ");
		scanf("%d%d",&x,&y);
		matrix[x>y?x:y][x>y?y:x]=1;
	snakespath[x>y?x:y]=1;
	}
	
}

void buildgraph()
{
	int i;
printf("building graph....\n");
	for(i=1;i<=30;i++)
	matrix[i][i+1]=1;
printf("graph built\n");
printf("Initializing graphs..... snakes and ladders\n");
int ladders;
printf("Enter the number of ladders : ");
scanf("%d",&ladders);
createladders(ladders);
printf("ladders built\n");
printf("Enter the number of snakes : ");
int snakes;
scanf("%d",&snakes);
memset(snakespath,0,sizeof snakespath);
createsnakes(snakes);//back edges
printf("snakes created\n");
}


void bfs(int a)
{
	visited[a]=1;
	queue<int>q;
	int i,counter=0,c=0;
q.push(a);
	
	while(!q.empty())
	{
		if(counter)
		{
		q.pop();
		path.push(c-1);
		c=0;
	    }
		int root=q.front();
	q.pop();
		if(snakespath[root])
		{
			path.push(c-1);
			c=1;
		}
		c++;
		counter=-1;
		for(i=1;i<=30;i++)
		{
			if(!visited[i]&&matrix[root][i])
			{
				
		//printf("%d %d %d\n",root,i,matrix[27][1]);
				visited[i]=1;
	    if(i>root)
				q.push(i);
	        else
                {
                path.push(c-2);
				c=1;
			}
			if(i==30)
			path.push(c);
			
		      counter++;  	
			}
			
		}
		
	}
	
}
void calculate_path(int a,int n)
{
	
	memset(visited,0,sizeof visited);
	bfs(a);
int t,i;
queue<int>ans;
while(!path.empty())
{
t=path.front();
path.pop();
while(t>6)
{
	t-=6;
	ans.push(6);

}
//printf("t=%d\n",t);
ans.push(t);
}	
printf("\n\tThe possible values are : ");
while(!ans.empty())
{
	cout<<ans.front()<<" ";
ans.pop();
}


}
int main()
{


memset(matrix,0,sizeof matrix);
buildgraph();
/*int i,j;
for(i=1;i<=30;i++)
{
	for(j=1;j<=30;j++)
	printf("%d ",matrix[i][j]);
	printf("\n");
}
*/
calculate_path(1,30);
	
return 0;	
}
