#include<stdio.h>

void quicksort(long signed int a[],long signed int l,long signed int r)
{    if(r>l){
    long signed int i, j, v, t;

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
	int a,i;
	long int count,j,k,m,n[10000],f;
	double d;
	scanf("%d",&a);
	
	for(i=0;i<a;i++){
		scanf("%d%d",&m,&f);
		for(j=0;j<m;j++){
			scanf("%d",&n[j]);
		}
		count=0;
		quicksort(n,0,m-1);
		
		for(j=m-1;j>=0;j--){
			d=(double)n[j]/(double)f;
			while(d>=1){
				for(k=j-1;k>=0;k--)
				{ 
				if(d==n[k])
				count++;
             } 
		d=d/f;
		}
		}
		f=0;
		for(j=0;j<m-1;j++){
			if(n[j]==n[j+1])
			f++;
			if(n[j+1]!=n[j+2])
        {if(f>=1){
        	
		f=f*(f+1);
        f=f/2;
			count=count+f;
		} f=0;
             }			
	}
		printf("%lu\n",count);
	}
	return 0;
}
