#include<iostream>
void quicksort(long int a[],long int l,long int r)
{    if(r>l){
    long int i, j, v, t;

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
	int t,i;
	long int n,j,count;
	cin>>t;
	long int a[100005];
	for(i=0;i<t;i++)
	{
		count=1;
		cin>>n;
		for(j=0;j<n;j++)
		{
		cin>>a[j];			
		}
		quicksort(a,0,n);
		
		for(j=0;j<n;j++)
		{
			cout<<a[j]<<"\n";
		}
		
		for(j=1;j<n;j++)
		{
			if(a[j]!=a[j-1])
			count++;
		}
	cout<<count<<"\n";	
	}
	return 0;
}
