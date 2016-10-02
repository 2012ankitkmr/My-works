#include<stdio.h>
#include<string.h>
#define gl(i,L,R) for (int i = L; i < R; i++) //next four are for "for loops"
#define ge(i,L,R) for (int i = L; i <= R; i++)


bool isSubsetSum(int set[], int n, int sum)
{
 
    bool subset[sum+1][n+1];
 
    // If sum is 0, then answer is true
    memset(subset[0],1,sizeof(subset[0]));
// ms(subset[0],1);
    // If sum is not 0 and set is empty, then answer is false
    for (int i = 1; i <= sum; i++)
      subset[i][0] = false;
 
     // Fill the subset table in botton up manner
     for (int i = 1; i <= sum; i++)
     {
       for (int j = 1; j <= n; j++)
       {
         subset[i][j] = subset[i][j-1];
         if (i >= set[j-1])
           subset[i][j] = subset[i][j] || subset[i - set[j-1]][j-1];
       }
     }
 
     return subset[sum][n];
}
 int next_int()
{
        int n = 0;
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
int a[100005],temp[100005];
int main()
{
	//freopen("in.txt","r",stdin);
	int n,q,te,x,y,w,p;
scanf("%d%d",&n,&q);

	gl(i,0,n)
scanf("%d",&a[i]);
	while(q--)
	{
	//	printA(a,0,n-1);
	scanf("%d",&te);
		if(te==1)
		{
scanf("%d%d",&x,&y);
		a[x-1]=y;
			
		}
		if(te==2)
		{
	scanf("%d%d",&x,&y);
			 p=0;
			ge(i,x-1,y-1)
			temp[p++]=a[i];
			
			ge(i,x-1,y-1)
			a[i]=temp[--p];
			
		}
		if(te==3)
		{
scanf("%d%d%d",&x,&y,&w);
		 p=0;
		ge(i,x-1,y-1)
		temp[p++]=a[i];
	if (isSubsetSum(temp,p, w) == true)
     printf("Yes\n");
  else
     printf("No\n");
 
			
		}
		
		
	}
	
	return 0;
} 
