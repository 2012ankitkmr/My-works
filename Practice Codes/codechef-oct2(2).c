#include<stdio.h>
#include<stdlib.h>
int main()
{
    long int t,i,n,j,k;
	long signed cost;
    long int d[100000];
	scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        
        for(i=0;i<n;i++)
        {
            scanf("%d",&d[i]);
        }
        k=0;
        cost=0;
        i=0;
        j=0;
        while(k<n)
        {
            while(d[i]<=0 && i<(n-1))       //i should be for +ve d[i],i.e, villagers
                i++;
            while(d[j]>=0 && j<(n-1))        //j should be for -ve d[j],i.e, dinasours
                j++;
            if(d[i]>(-d[j]))
            {
                cost+=abs(j-i)*(-d[j]);
                d[i]-=(-d[j]);
                d[j]=0;
            }
            else if(d[i]<(-d[j]))
            {
                cost+=abs(j-i)*d[i];
                d[j]+=d[i];
                d[i]=0;
            }
            else if(d[i]==(-d[j]))
            {
                cost+=abs(j-i)*d[i];
                d[i]=0;
                d[j]=0;
            }
            k++;
        }
        printf("%d\n",cost);
    }
    return 0;
}
