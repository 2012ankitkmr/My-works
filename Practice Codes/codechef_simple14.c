#include<stdio.h>
#include<math.h>

int main(){
	long unsigned int e,k,j,a,i,b,c;
	scanf("%d",&a);
	int flag;
	for(k=0;k<a;k++){
		scanf("%d%d",&b,&c);
		e=1;
		 for(i=b;i<=c;++i)
  {
      flag=0;
      x=sqrt(i);
      for(j=2;j<=x;++j)
      {
        if(i%j==0)
        {
          flag=1;
          break;
        }
      }
      if(flag==0)
    {e=e*i;
  }
  
  }	
  e=e%1000000009;
  printf("%d\n",e);	
	} 
	
	return 0;
}
