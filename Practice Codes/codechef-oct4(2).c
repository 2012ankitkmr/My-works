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
int i,b,g,m,j,t,re,k;
long int d;

scanf("%d",&t);
long int B[100],R[100],G[100];
for(i=0;i<t;i++){
 scanf("%d%d%d%d",&re,&g,&b,&m);
 
  for(j=0;j<re;j++)
 scanf("%d",&R[j]);

  for(j=0;j<g;j++)
 scanf("%d",&G[j]);

  for(j=0;j<b;j++)
 scanf("%d",&B[j]);
 
 quicksort(R,0,re-1);
 quicksort(G,0,g-1);
 quicksort(B,0,b-1);
 
 printf("%d\n%d\n%d\n",re,g,b);
 

for(j=1;j<=m;j++){
 	
 if(R[re-1]>G[g-1]&&R[re-1]>B[b-1])
{

	for(k=0;k<re;k++)
	R[k]=R[k]/2;
	
} 
else if(G[g-1]>R[re-1]&&G[g-1]>B[b-1])
{
	for(k=0;k<g;k++)
	G[k]=G[k]/2;
	
}
else if(B[b-1]>R[re-1]&&B[b-1]>G[g-1])
{
	for(k=0;k<b;k++)
	B[k]=B[k]/2;
	
}
else if(B[b-1]==R[re-1]==G[g-1])
{
for(k=0;k<b;k++)
	B[k]=B[k]/2;
}
printf("hi\n");
}
  
 if(R[re-1]>G[g-1]&&R[re-1]>B[b-1])
{
d=R[re-1];
} 
else if(G[g-1]>R[re-1]&&G[g-1]>B[b-1])
{
d=G[g-1];
}
else if(B[b-1]>R[re-1]&&B[b-1]>G[g-1])
{
d=B[b-1];	
} 
else if(B[b-1]==G[g-1]==R[re-1])
d=G[g-1];
 
 printf("%ld\n",d);
 }
return 0;
}
