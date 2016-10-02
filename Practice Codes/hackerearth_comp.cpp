#include<stdio.h>
int main(){
int a,b,i,j,flag,x,y,t,k;
scanf("%d%d",&a,&b);

long signed int c[a][b],q;
for(i=0;i<a;i++){
for(j=0;j<b;j++){
scanf("%ld",&c[i][j]);
}
}
scanf("%d",&t);
for(k=0;k<t;k++){
        flag=0;
    scanf("%ld",&q);
for(i=0;i<a;i++){
        for(j=0;j<b;j++){
            if(c[i][j]==q){
                x=i;
                y=j;
                flag=1;
                break;
                }
            else if(c[i][j]>q)
            break;

           }
    }
if(flag==1)
  printf("%d %d\n",x,y);
   else
    printf("%d %d\n"-1,-1);
}

return 0;
}
