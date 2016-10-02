#include<stdio.h>
#include<math.h>

void quicksort(long int a[],long int l,long int r)
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
  else
return;
 }


int main()
{ long int a[100005];
	long int t,k,n;
	long long unsigned int p,i,q,sum,val,temp;
	for(scanf("%ld",&t);t--;)
	{
		scanf("%ld%ld",&n,&k);
if(n%2==0)
{q=n+1;
p=n/2;		
p=q*p;
}
else
{
q=n;
p=(n+1)/2;		
p=q*p;	
}
	//	printf("p=%lld",p);
		if(k==0)
		{
			if(p%2==0)
			printf("Chef\n");
			else
			printf("Mom\n");
		}
		else{
		for(i=0;i<k;i++)
		{
			scanf("%ld",&a[i]);
		}		
		quicksort(a,0,k-1);
		q=0;
		sum=0;
		for(i=0;i<k;i++)
		{
			val=a[i]-1;
			sum+=a[i];
		}
	
if(a[0]==1)
printf("Chef\n");

else if(a[0]==2)
{
	printf("Mom\n");	
}

else
{       
if(a[k-1]%2==0)
		{q=a[k-1]+1;
val=a[k-1]/2;		
val=q*val;
}
else
{
q=a[k-1];
val=(a[k-1]+1)/2;		
val=q*val;	
}//val update val=a[k-1]*(a[k-1]+1)/2
     val=val-sum;
	
		if(val< a[k-1])
      {
	if(a[k-1]%2==0)
    printf("Chef\n");
	    else
    printf("Mom\n");
		}

		else{
 val=p-sum;

		if(val%2==0)

	printf("Chef\n");

	else
	printf("Mom\n");
		}
}
 
		
	}
	}
return 0;
}
