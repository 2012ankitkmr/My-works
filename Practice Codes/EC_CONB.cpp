#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
int modifyNumber(int n)
{
    int bits[64];
    int length = 0;
    while( n > 0 )
    {
        bits[length++] = n % 2;
        n = n / 2;
    }
    int temp = 0;
    for(int i = length - 1, j = 0; i >= 0; --i, ++j)
    {
        temp = temp + pow(2, j)*bits[i];
    }
    return temp;
}
int main()
{
    int t, n;
    scanf("%d", &t);
    while(t-->0)
    {
        scanf("%d", &n);
        if( n % 2 == 0 )
            printf("%dn", modifyNumber(n));
        else
            printf("%dn", n);

    }
    return 0;

}
