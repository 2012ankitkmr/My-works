#include<stdio.h>
#include<stdlib.h>
void quicksort(char *ptr,long signed int a[],long signed int l,long signed int r)
{    if(r>l){
    long signed int i, j, v, t;
char c;
        v = a[r];
        i = l-1;
        j = r;

        for(;;)
       {
            while (a[++i] < v);
            while (a[--j] > v);

            if(i >= j) break;
            t = a[i]; a[i] = a[j]; a[j] = t;
           c=*(ptr+i);
*(ptr+i)=*(ptr+j);
*(ptr+j)=c;
        }
    t = a[i];
	a[i] = a[r];
	a[r] = t;
  c=*(ptr+i);
*(ptr+i)=*(ptr+r);
*(ptr+r)=c;
      quicksort(ptr,a, l, i - 1);
     quicksort(ptr,a, i + 1, r);
  }
return;
 }
 
int main(){
	int t,i;
	long long int e,k;
	long int n,m,j,M[100000];
char*ptr;
ptr=(char*)calloc(100000,sizeof(char));
	scanf("%d",&t);
	for(i=0;i<t;i++){
		scanf("%d%d",&n,&m);

	for(j=0;j<m;j++){
	scanf("%s",ptr+j);
	scanf("%d",&M[j]);
}
quicksort(ptr,M,0,m-1);
	e=1;
	if(m==1)
	e=1;
		for(j=1;j<m;j++){
			k=M[j]-M[j-1];
		
		if(*(ptr+j)!=*(ptr+j-1))
				e=e*k;
			}
			e=e%1000000009;
		printf("%d\n",e);
	}	
return 0;
}
