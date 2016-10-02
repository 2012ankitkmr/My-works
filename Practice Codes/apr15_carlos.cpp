#include<iostream>
#include<limits.h>
using namespace std;
 #include<stdio.h>

long long a[200005];
long long b[205];
long long c[205][200005];
long long sequence[205];
#define MAX 100000005
long int next_int()
{
       long  int n = 0;
        char c = getchar_unlocked();
        while (!('0' <= c && c <= '9'))
        {
                c = getchar_unlocked(); 
        }
        while ('0' <= c && c <= '9')
        {
                n = (n<<3)+(n<<1) + c - '0';
                c = getchar_unlocked();
        }
        return n;
}
long long qroot(long long i)
{
	while(i!=b[i])
		{
	b[i]=b[b[i]];
		i=b[i];
	}
	return i;
}
 
int main()
{
long long t,m,k,n,x,y,i,j,index_x,index_y,min;

	for(t=next_int();t--;)
	{		
	m=next_int();
	k=next_int();
	n=next_int();

		for(i=0;i<=m;++i)
		{
			b[i]=i;
			sequence[i]=1;
		}
 
		while(k--)
		{

x=next_int();
y=next_int();
	
			index_x=qroot(x);
			index_y=qroot(y);
			if(index_x==index_y)
				continue;
			else if(sequence[x]<sequence[y])
			{
				b[index_y]=index_x;
				sequence[index_x]+=sequence[index_y];
			}
			else
			{
				b[index_x]=index_y;
				sequence[index_y]+=sequence[index_x];	
			}
		}
		for(i=0;i<=m;++i)
		{
			b[i]=qroot(i);
			c[0][i]=0;
		}
 
 
		for(i=1;i<=n;++i)
			a[i]=next_int();
 
		for(i=1;i<=n;++i)
		{
			min=MAX;
			for(j=1;j<=m;++j)
			{
				min=(c[j][i-1]<min)?c[j][i-1]:min;	
				if(b[j]==b[a[i]])
					c[j][i]=(min==MAX)		
							?MAX:((j==a[i])?min
							:(min+1));
				else
					c[j][i]=MAX;
			}	
		}
 
		min=MAX;
		for(i=1;i<=m;++i)
			min=(c[i][n]<min)?c[i][n]:min;
 
		if(min==MAX)
			cout<<"-1"<<endl;
		else
			cout<<min<<endl;
	}
	return 0;
}
