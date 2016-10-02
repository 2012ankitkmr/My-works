#include<stdio.h>
#include<stdlib.h>

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
 long int i,b,g,j,t,m,r,k,d;
scanf("%d",&t);
long signed int B[100],G[100],R[100],sumr,sumg,sumb;
for(i=0;i<t;i++){
 scanf("%d%d%d%d",&r,&g,&b,&m);

  for(j=0;j<r;j++)
 scanf("%d",&R[j]);

  for(j=0;j<g;j++)
 scanf("%d",&G[j]);

  for(j=0;j<b;j++)
 scanf("%d",&B[j]);
 
 quicksort(R,0,r);
 quicksort(G,0,g);
 quicksort(B,0,b);
 

sumr=sumg=sumb=0;
for(j=1;j<=m;j++){
 
for(k=0;k<r;k++){
	sumr=sumr+R[k];
	
}


for(k=0;k<g;k++){
	sumg=sumg+G[k];
	
}


for(k=0;k<b;k++){
	sumb=sumb+B[k];
	
}

 if(R[r-1]>=G[g-1]&&R[r-1]>B[b-1])
{
	if(R[r-1]==G[g-1]){
	
	if(sumr>sumg)
	{for(k=0;k<r;k++)
	R[k]=R[k]/2;
	}
	else 
	for(k=0;k<g;k++)
	G[k]=G[k]/2;
}
   else
	for(k=0;k<r;k++)
	R[k]=R[k]/2;
	
} 
else if(G[g-1]>R[r-1]&&G[g-1]>=B[b-1])
{
	
	if(G[g-1]==B[b-1]){
	
	if(sumg>sumb)
	{for(k=0;k<g;k++)
	G[k]=G[k]/2;
	}
	else 
	for(k=0;k<b;k++)
	B[k]=B[k]/2;
}
	else
	for(k=0;k<g;k++)
	G[k]=G[k]/2;
	
}
else if(B[b-1]>=R[r-1]&&B[b-1]>G[g-1])
{
	
	if(B[b-1]==R[r-1]){
	
	if(sumb>sumr)
	{for(k=0;k<b;k++)
	B[k]=B[k]/2;
	}
	else 
	for(k=0;k<r;k++)
	R[k]=R[k]/2;
}
	else
	for(k=0;k<b;k++)
	B[k]=B[k]/2;
	
}

else if(R[r-1]==G[g-1]==B[b-1]){
	if(sumr>=sumg&&sumr>sumb)
	{for(k=0;k<r;k++)
	R[k]=R[k]/2;
		}
	
	else if(sumg>sumr&&sumg>=sumb){
	for(k=0;k<g;k++)
	G[k]=G[k]/2;
		
	}
	else if(sumb>=sumr&&sumb>sumg)
	{for(k=0;k<b;k++)
	B[k]=B[k]/2;
	
	}
else 
for(k=0;k<r;k++)
	R[k]=R[k]/2;
	
}

 }
 
 if(R[r-1]>=G[g-1]&&R[r-1]>B[b-1])
{
d=R[r-1];	
} 
else if(G[g-1]>R[r-1]&&G[g-1]>=B[b-1])
{
d=G[g-1];	
}
else if(B[b-1]>=R[r-1]&&B[b-1]>G[g-1])
{
d=B[b-1];	
} 
 
 printf("%d\n",d);
 }
return 0;
}
