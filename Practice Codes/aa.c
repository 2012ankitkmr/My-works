#include<stdio.h>
int main()
{
    int a,b,c,i,j;
    printf("enter 1,2,3 or 4");
    scanf("%d",&a);
    switch(a)
    {
    case 1:
        printf("enter no. for which u wanna find factorial");
        scanf("%d",&b);
        for(i=1,c=1;i<=b;i++)
        {
            c=c*i;
        }
        printf("%d",c);
        break;
    case 2:
        printf("enter no which u wanna find prime or not");
        scanf("%d",&b);
        {
            for(i=2;i<=(b-1);i++)
        {

            if(b%i==0)
            {
                printf("not a prime no.");
                break;

            }

        }
        if(i==(b-1))
            printf("prime no.");
        }
        break;
    case 3:
        printf("enter no eor which u wanna find it is even or not");
        scanf("%d",&b);
        if(b%2==0)
            printf("even no");
        else
            printf("odd no");
            break;
    case 4:
        printf("exit");

    }
    return 0;
}
