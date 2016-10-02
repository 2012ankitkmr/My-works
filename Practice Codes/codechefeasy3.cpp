#include<stdio.h>

int main(){
int i,a,f=0;
long unsigned int b;

scanf("%d%lu",&a,&b);

long unsigned int c[a];
for(i=0;i<a;i++)
{scanf("%lu",&c[i]);	
}

for(i=0;i<a;i++){
	if(c[i]%b==0)
	f++;
}

printf("%d",f);

return 0;
}
