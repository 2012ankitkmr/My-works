#include<bits/stdc++.h>
using namespace std;
#define ge(i,L,R) for (int i = L; i <= R; i++)



int main(){
    int dp[7994][4];
    
    for(int i = 0;i < 7994;++i) dp[i][1] = 1;
    dp[0][2] = dp[0][3] = 1;
    
    for(int k = 2;k <= 3;++k){
        for(int i = 1;i < 7994;++i){
            dp[i][k] = dp[i][k-1];
            if(i >= k) dp[i][k] += dp[i-k][k];
        }
    }
    int sp2[7994];
    bool sieve[7996];
    memset(sieve,1,sizeof sieve);
    ge(i,2,7994)
    {
    	if(sieve[i])
    	{
    		int j=2,num;
    		while((num=i*j)<=7994)
    		{
    		sieve[num]=0;
    		j++;
    		}
     	}
    }

    int sqr=ceil(sqrt(7994));
int sq[sqr+2];
    ge(i,1,sqr)
    {
    	sq[i]=i*i;   	
    }
    int p=1;
    ge(i,1,sqr)ge(j,i,sqr)
    {
    	if(sieve[(sq[i]+sq[j])])
    sp2[p++]=sq[i]+sq[j];
    }
    sort(sp2,sp2+p-1);
    //printA(sp2,1,5);
    int T,n,k;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d",&n,&k);
        printf("%d\n",dp[sp2[n]][k]);
    }
    
    return 0;
}
