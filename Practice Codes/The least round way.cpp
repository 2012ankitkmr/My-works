#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second

int mat[1003][1003];

int path2[1003][1003],path5[1003][1003];
int n;

int gv(int num,int d)
{
	int a=0;
	if(num==0)
	return 0;
	while(num%d==0)
	{
		a++;
		if(d==2)
		num>>=1;
		else
		num/=d;
	}
	return a;
}

int min2(int x,int y)
{

	path2[0][0]=gv(mat[0][0],2);
	for(int i = 1;i<n;i++)
	path2[0][i]=gv(mat[0][i],2)+path2[0][i-1];
	for(int i = 1;i<n;i++)
	path2[i][0]=gv(mat[i][0],2)+path2[i-1][0];
	
	for(int i = 1;i<n;i++)
	for(int j = 1;j<n;j++)
	{
		path2[i][j] = min(path2[i-1][j],path2[i][j-1])+gv(mat[i][j],2);
	}
return path2[n-1][n-1];
}	

int min5(int x,int y)
{

	path5[0][0]=gv(mat[0][0],5);
	for(int i = 1;i<n;i++)
	path5[0][i]=gv(mat[0][i],5)+path5[0][i-1];
	for(int i = 1;i<n;i++)
	path5[i][0]=gv(mat[i][0],5)+path5[i-1][0];
	
	for(int i = 1;i<n;i++)
	for(int j = 1;j<n;j++)
	{
		path5[i][j] = min(path5[i-1][j],path5[i][j-1])+gv(mat[i][j],5);
	}
return path5[n-1][n-1];
}	

string getpath2()
{
	string s;
	
	int x=n-1,y=n-1;
	
	while(!((x==0)&&(y==0)))
	{
		if(x==0)
		{
		s.append("R");
		y--;
		continue;
		}
		if(y==0)
		{
		s.append("D");
		x--;
		continue;
		}
		if(path2[x-1][y]>path2[x][y-1])
     	{
		s.append("R");
		y--;
		}
		else
		{	
		x--;
		s.append("D");	
	    }
	}
	reverse(s.begin(),s.end());
	return s ;
}

string getpath5()
{
		string s;
	
	int x=n-1,y=n-1;
	
	while(!((x==0)&&(y==0)))
	{	
		if(x==0)
		{
		s.append("R");
		y--;
		continue;
		}
		if(y==0)
		{
		s.append("D");
		x--;
		continue;
		}
		if(path5[x-1][y]>path5[x][y-1])
     	{
		s.append("R");
		y--;
		}
		else
		{	
		x--;
		s.append("D");	
	    }
	}
	reverse(s.begin(),s.end());
	return  s;
}




int main()
{
	
	int fl = 0,a,b;
//	freopen("in.txt","r+",stdin);
	scanf("%d",&n);
	for(int i = 0;i<n;i++)
	for(int j = 0;j<n;j++)
{
	scanf("%d",&mat[i][j]);
	if(mat[i][j]==0)
	{
	fl=1;
	a = i,b = j;
    }
}
	int twos = min2(0,0);
	int fives = min5(0,0);

if(fl&&(twos)&&(fives))
{
	string s;
	for(int i =1;i<=a;i++)
	 s.append("D");
	for(int i =1;i<n;i++)
	 s.append("R");
	for(int i =a+1;i<n;i++)
	 s.append("D");
	printf("1\n");
	cout<<s;
}
else
{

	
/*	for(int i = 0;i<n;i++)
	{
		for(int j = 0;j<n;j++)
		printf("%d ",path2[i][j]);
		printf("\n");
	}
*/
	if(twos>fives)
	{
		printf("%d\n",fives);
		cout<<getpath5();
	
	}
	else
	{
		printf("%d\n",twos);
	    cout<<getpath2();
	}
}
	return 0;
}
