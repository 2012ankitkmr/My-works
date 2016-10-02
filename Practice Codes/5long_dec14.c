#include<stdio.h>

void quicksort(long long int a[],long long int l,long long int r)
{    if(r>l){
    long int i, v, t,j;

        v = a[r];
        i = l-1;
        j = r;

        for(;;)
       {
            while (a[++i] < v);
            while (a[--j] > v);

            if(i >= j) break;
            t = a[i]; a[i] = a[j]; a[j] = t;

        }


    t = a[i];
	a[i] = a[r];
	a[r] = t;

    quicksort(a, l, i - 1);
    quicksort(a, i + 1, r);

  }
return;
 }
 
int main(){
unsigned int t,i,flag,count,k,s,d,j;
	long long int sum,a[22],n,avg;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{ flag=0;
	sum=0;
		scanf("%llu%llu",&n,&k);
		for(j=0;j<n;j++)
		scanf("%llu",&a[j]);
		
		for(j=0;j<n;j++)
		{
			sum=sum+a[j];
		}
		
		avg=sum/(long long int)k;
   //  printf("%llu\n",avg);
       quicksort(a,0,n-1);
      if(a[n-1]>avg)
      printf("no\n");
         
		else if(sum%avg!=0)
		printf("no\n");
		else
		{count=0;
		j=n-1;
		while(a[j]==avg)
		{
			j--;
			count++;
		}
		//printf("%d\n",j);
		d=j-1;
		sum=a[j];
		for(s=0;s<k;s++)
	  {
	    if(count!=k){
		for(j=d;j>=0;j--)
		{
		sum=sum+a[j];
		if(sum>avg&&j!=d)
		sum=sum-a[j+1];
		else	
	     {if(j!=d)
	     a[j+1]=0;
	    }
	    if(sum==avg)
	    { a[j]=0;
	count++;
	    break;
		}
		//printf("%d,j=%d\n",sum,j);
		}
	}
		sum=0;
	}
	if(count==k)
	printf("yes\n");
	else
	printf("no\n");
		}

	}
	return 0;
}
