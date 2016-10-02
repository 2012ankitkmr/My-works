#include<bits/stdc++.h>
using namespace std;
int pow(int a, int b, int MOD) {
int x = 1, y = a;
    while(b > 0) {
        if(b%2 == 1) {
            x=(x*y);
            if(x>MOD) x%=MOD;
        }
        y = (y*y);
        if(y>MOD) y%=MOD;
        b /= 2;
    }
    return x;
}
 
int modInverse(int a, int m) {
    return pow(a,m-2,m);
}
int main()
{
	printf("%d\n",modInverse(2,1000000007));
	return 0;
}
