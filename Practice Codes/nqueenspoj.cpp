#include<bits/stdc++.h>
using namespace std;
#define mx 51
bool board[mx][mx];
int N;
bool memoize[mx][mx];
//bool safe[mx][mx];
void printboard()
{

	for(int i=0;i<N;i++)
{
	for(int j=0;j<N;j++)
	if(board[j][i])
	printf("%d ",j+1);	
}
	printf("\n");
}
int arr[54];
bool IsSafe(int row,int column)
{
	for(int i=0;i<column;i++)
	if(board[row][i])
	return false;
	for(int i=column+1;i<N;i++)
	if(board[row][i])
	return false;
		
	for(int i=row+1,j=column+1;i<N&&j<N;i++,j++)
	if(board[i][j])
	return false;
			
	for(int i=row-1,j=column+1;i>=0&&j<N;i--,j++)
	if(board[i][j])
	return false;
	
	for(int i=row-1,j=column-1;i>=0&&j>=0;i--,j--)
	if(board[i][j])
	return false;
	
	for(int i=row+1,j=column-1;i<N&&j>=0;i++,j--)
	if(board[i][j])
	return false;
	
	return true;
}


bool SolveNQueen(int row,int column)
{
	if(column>=N)
	return true;
	if(arr[column])
	return SolveNQueen(row,column+1);
	for(int i=0;i<row;i++)
	{
		if(IsSafe(i,column))
		{
		board[i][column]=1;
		
if(memoize[row][column]!=-1)
{
	if(memoize[row][column])
	return true;
}		
else if(memoize[row][column]=SolveNQueen(row,column+1))
return true;	
		board[i][column]=0;
	    }
	}
return false;
}


int main()
{
while(scanf("%d",&N)!=EOF)
//while(1)
{
	//scanf("%d",&N);
	memset(memoize,-1,sizeof memoize);
	memset(arr,0,sizeof (arr));
int row=N,column=N,a;
memset(board,0,sizeof board);
for(int i=0;i<N;i++)
{
	scanf("%d",&a);
	
	if(a)
	{
	a--;
board[a][i]=1;
arr[i]=1;
}
}
//	printf("here=%d\n",IsSafe(2,0));
bool b=SolveNQueen(row,0);
printboard();
}
return 0;
}
