#include<bits/stdc++.h>
using namespace std;
#define N 8
bool board[N][N];

void printboard()
{
	for(int i=0;i<N;i++)
{
	for(int j=0;j<N;j++)
	printf("%d ",board[i][j]);
	printf("\n");
}
	
}

bool IsSafe(int row,int column)
{
	for(int i=0;i<column;i++)
	if(board[row][i])
	return false;
	
	for(int i=row,j=column;i>=0&&j>=0;i--,j--)
	if(board[i][j])
	return false;
	
	for(int i=row,j=column;i<N&&j>=0;i++,j--)
	if(board[i][j])
	return false;
	
	return true;
}


bool SolveNQueen(int row,int column)
{
	if(column>=N)
	return true;
	
	for(int i=0;i<row;i++)
	{
		if(IsSafe(i,column))
		{
		board[i][column]=1;
		
if(SolveNQueen(row,column+1))
return true;	
		board[i][column]=0;
	    }
	}
return false;
}


int main()
{
int row=N,column=N;

memset(board,0,sizeof board);

if(SolveNQueen(row,0))
{
	printboard();
}	
else
printf("No such case exists\n");
	
return 0;
}
