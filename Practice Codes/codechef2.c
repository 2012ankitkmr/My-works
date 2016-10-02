#include<iostream>
#define scana() scanf("%d",&a);
#define scanb() scanf("%d",&b);
#define scanc() scanf("%d",&c);



int main(){
int a,i,j,b,c,d=1,h,f=0;
scana();
for(i=1;i<=a;i++)
{ scanb();
   d=1;
   f=0;


    for(j=1;j<=b;j++){
      scanc();
    d=d*c;
}
for(h=1;h<=d;h++){

        if((d%h)==0)
        f++;
 }
        printf("%d",f);
}

return 0;

}
