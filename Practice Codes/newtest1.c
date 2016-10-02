#include<stdio.h>
#include<stdlib.h>

int main(){
 short int i,bl,g,j,t,m,r;
long unsigned int c;
scanf("%d",&t);
for(i=0;i<t;i++){
 scanf("%d%d%d",&g,&bl,&r);
 c=(bl+g);
 c=c+r;
 scanf("%d",&bl);
 //printf("here,c=%d",c);
 long unsigned int all[c];
 for(j=0;j<c;j++)
 scanf("%d",&all[j]);

   for(g=c-2;g>=0;g--){
      for(j=0;j<=g;j++){
           if(all[j]>all[j+1]){
               r=all[j];
              all[j]=all[j+1];
              all[j+1]=r;
           }
      }
  }

 
  j=c-1;
 while(bl>0){
 all[j]=all[j]/2;
 
 for(g=c-2;g>=0;g--){
      for(j=0;j<=g;j++){
           if(all[j]>all[j+1]){
               r=all[j];
              all[j]=all[j+1];
              all[j+1]=r;
           }
      }
  }
 
 bl--;
 }
 printf("%d\n",all[j]);
 }
return 0;
}
