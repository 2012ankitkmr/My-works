#include<bits/stdc++.h>
using namespace std;
#define N 8
void printsol(int sol[N][N])
{
	for(int i=0;i<N;i++)
	{
	for(int j=0;j<N;j++)
	printf(" %2d ",sol[i][j]);
printf("\n");
}
	
}

bool isSafe(int x,int y,int sol[N][N])
{
	if(x>=0&&y>=0&&x<N&&y<N&&sol[x][y]==-1)
	return true;
	return false;
}

bool SolveKTutil(int x,int y,int iMove,int sol[N][N],int xMove[N],int yMove[N])
{
	int k,next_y,next_x;
if(iMove==N*N)	
	return true;
	
for(k=0;k<8;k++)
{
	next_x=x+xMove[k];
	next_y=y+yMove[k];
	if(isSafe(next_x,next_y,sol))
	{
		sol[next_x][next_y]=iMove;
		if(SolveKTutil(next_x,next_y,iMove+1,sol,xMove,yMove))
		return true;
		else
		sol[next_x][next_y]=-1;
	}
}	
return false;	
}


bool solveKT()
{
	int sol[N][N];
	memset(sol,-1,sizeof sol);
	int xMove[8]={  2, 1, -1, -2, -2, -1,  1,  2 };
	int yMove[8]={  1, 2,  2,  1, -1, -2, -2, -1 };
	sol[0][0]=0;
	if(SolveKTutil(0,0,1,sol,xMove,yMove)==false)
	{
	printf("No Solution exist\n");
return false;
}
	else
	printsol(sol);
	return true;
}

int main()
{
	solveKT();
	return 0;
}
