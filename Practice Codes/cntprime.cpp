#include<bits/stdc++.h>
#include<math.h>
using namespace std;
bool sieve[1000000];
	long int maxsize;
int getmid(int a,int b)
{
	return a+(b-a)/2;
}
void updatestutil(int*st,int ss,int se,int i,int diff,int index)
{
	if(i<ss||i>se)
	return;
	st[index]=st[index]+diff;
	if(se!=ss)
	{
		int mid = getmid(ss,se);
		updatestutil(st,ss,mid,i,diff,2*index+1);
		updatestutil(st,mid+1,se,i,diff,2*index+2);
	}
	
}

void updatevalue(long int arr[],int*st,int n,int i,int new_val)
{
	if(i<0||i>n-1)
	return;
	int diff=new_val-arr[i];
	arr[i]=new_val;
	updatestutil(st,0,n-1,i,diff,0);
	
}

int countstprimeutil(int*st,int ss,int se,int qs,int qe,int index)
{

if (se < qs || ss > qe)
        return 0;
//printf("st=%d,index=%d,ss=%d,se=%d,qs=%d,qe=%d\n",st[index],index,ss,se,qs,qe);
	if(ss==se&&ss>=qs&&se<=qe)//condition for accessing leaf node
	{
	if(sieve[st[index]])
	{
	return 1;
 }
 else return 0;
}
  
	int mid=getmid(ss,se);
	return countstprimeutil(st,ss,mid,qs,qe,2*index+1)+countstprimeutil(st,mid+1,se,qs,qe,2*index+2);
}

int countprime(int*st,int n,int l,int r)
{
	if(l<0||r>n-1)
	return 0;
	return countstprimeutil(st,0,n-1,l,r,0);
}
int constructutil(long int arr[],int ss,int se,int *st,int si)
{
	if(ss==se)
	{
		st[si]=arr[ss];
		return arr[se];
	}
	
	int mid=getmid(ss,se);
	st[si]=constructutil(arr,ss,mid,st,2*si+1)+constructutil(arr,mid+1,se,st,2*si+2);
	return st[si];
}


int*constructst(long int a[],int n)
{
	int h=(int)log2(n);
	
	 maxsize=pow(2,h+1)-1;
	int*st=new int[maxsize];
    //printf("max=%d\n",maxsize);
	constructutil(a,0,n-1,st,0);
	//for(int i=0;i<=maxsize+1;i++)
	//printf("%d ",st[i]);
	return st;

}
long int next_int()
{
        long int n = 0;
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

int main()
{

long int a[10005],i,t,n,q,j;
n=1000000;
memset(sieve,1,sizeof sieve);
for(i=2;i<=n;i++)
{
	if(sieve[i])
	{
		j=2;
		while((q=i*j)<=n)
		{
			sieve[q]=0;
			j++;
		}
	}
	
}
long int ch,x,y,v;
for(scanf("%d",&t);t--;)
{
n=next_int();
q=next_int();
	for(i=0;i<n;i++)
	a[i]=next_int();
	int*st=constructst(a,n);
while(q--)
{

	ch=next_int();
	if(!ch)
	{
		x=next_int();
		y=next_int();
		v=next_int();
		x--;
		y--;
		
			updatevalue(a,st,n,i,v,x,y);
	}
	else
	{
	x=next_int();
	y=next_int();
	x--;
	y--;
	int ans=countprime(st,n,x,y);	
		printf("%d\n",ans);
	}
	
}
	
}	
	return 0;
}
