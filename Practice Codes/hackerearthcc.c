#include<stdio.h>
#include<math.h>
int main(){
	int t,k,flag,f;
	scanf("%d",&t);
	long int i,j,b,a;
	long long int d;
	for(k=0;k<t;k++){
		scanf("%ld%ld",&a,&b);
		d=0;
		f=0;
  for(i=a+1;i<b;++i)
  {
      flag=0;
      for(j=2;j<=sqrt(i);++j)
      {
        if(i%j==0)
        {
          flag=1;
          break;
        }
      }
      if(flag==0)
    {  d=d+i;
    f=1;}
  }
  flag=0;
  for(i=2;i<=sqrt(d);i++){
  	if(d%i==0){
  		flag=1;
  		break;
	  }
  }
  if(f==0||flag==1)
  printf("NO\n");
  else if(f==1&&flag==0)
  printf("YES\n");
	}	
return 0;
}
