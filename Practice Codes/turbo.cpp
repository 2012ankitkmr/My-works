#include<stdio.h>

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
{
long int t,a[1000005],i;	
	scanf("%ld",&t);
	for(i=0;i<t;i++)
	{
		a[i]=next_int();
		
	}
	quicksort(a,0,t-1);
	for(i=0;i<t;i++)
	printf("%ld\n",a[i]);
	return 0;
}
