#include <stdio.h>
#include <string.h>
#define MOD 1000000007
#define LEN 60000
int fact(int n)
{
	int fac[LEN+2];
  	fac[0]=1;
	
	for(int i=1;i<=n;i++)
	{
		fac[i]=(fac[i-1]%MOD*i%MOD)%MOD;
  }
  return fac[n];
}
 
void populateAndIncreaseCount (int* count, int* str)
{
    int i;
 
    for( i = 0;i<LEN; ++i )
        ++count[ str[i] ];
 
    for( i = 1; i <=LEN; ++i )
        count[i] += count[i-1];
}
 
void updatecount (int* count, int num)
{
    int i;
    for( i = num; i < LEN; ++i )
        --count[i];
}
int count[LEN+2] = {0};
int findRank (int* str)
{
    int len = LEN;
    int mul = fact(len);
    int rank = 1, i;
      // all elements of count[] are initialized with 0
    populateAndIncreaseCount( count, str );
 
    for (i = 0; i < len; ++i)
    {
        mul /= len - i;
 
        rank += count[ str[i] - 1] * mul;
        updatecount (count, str[i]);
    }
 
    return rank;
}
 int a[LEN+4];
int main()
{
   
for(int i=0;i<LEN;i++)
a[i]=i+1;
    printf("here\n");
    printf ("%d\n", findRank(a));
    return 0;
}


