#include<stdio.h>
#include<math.h>
int solve(int,int);

  int t,i,j,a,c;
 
 	
	

int main(){
scanf("%d",&t);
 for(i=0;i<t;i++){
 	scanf("%d",&a);	 
   int b[a][a];
 for(i=0;i<a;i++){
	 	for(j=0;j<=i;j++)
	    scanf("%d",&b[i][j]);
	 }
 	c=solve(i,j);
 }
 return 0;
 }
 
 int solve(int i,int j)
 {int d=1;
 if(d==1){
 	int b[a][a];
 for(i=0;i<a;i++){
	 	for(j=0;j<=i;j++)
	    scanf("%d",&b[i][j]);
	 
	 }
 	d++;
 }
 if(i>t)
 return 0;
 int t1,t2;
 t1=solve(i+1,j);	
 t2=solve(i+1,j+1);	
 int p;
 p=b[i][j]+max(t1,t2);
return p;
 }
