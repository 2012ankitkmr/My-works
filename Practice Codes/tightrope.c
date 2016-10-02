#include<stdio.h>
int main(){
long int n,flag=0;

long i;
double a,f;

int b=0;
 scanf("%ld",&n);
 char x[n];
    scanf("%s",&x);

scanf("%lf",&a);
printf(" ");
scanf("%lf",&f);

for(i=0;i<n;i++)
{
    if(x[i]=='L'){
        flag=flag+a;
    }
if(x[i]=='R'){
    flag=flag-a;
}

if(flag>f||flag<(-1)*f){
b++;
}
}
if(b!=0){
    printf("N0");
}
else{
    printf("YES");
}

return 0;
}

