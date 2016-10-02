#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
long unsigned int d,num1, num2,i,j,temp,e;
    char ch;
    int t,k,flag;
scanf("%d",&t);
for(k=0;k<t*2;k++){
e=1;
d=0;
scanf("%c",&ch);
scanf("%d%d",&num1,&num2);
        temp=num1;
    if(num1%2==0)
    {
        num1++;
    }
    for(i=num1;i<=num2;i=i+2)
    {
        flag=0;
        for(j=2;j<=sqrt(i);j++)
        {
            if(i%j==0)
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {if(ch=='P')
            printf("%ld ",i);

            else if(ch=='S')
                d=d+i;
            else if(ch=='M')
                e=e*i;
                 }
    }

    if(ch=='S')
        printf("\n%ld\n",d);

            else if(ch=='M'){
        e=e%1000000007;
            printf("%ld\n",e);
    }
}
return 0;
}

