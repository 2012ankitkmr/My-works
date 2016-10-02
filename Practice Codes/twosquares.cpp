#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;

const int nmax=1000001;

unsigned long long primes[nmax/10];
bool fl[nmax];
int test, m;
unsigned long long n;

int main()
{
    for (int i=2; i<nmax; i++)
    if (!fl[i]) {
        primes[m] = i;
        m++;
        int j=i;
        while (j+i<nmax) {
        fl[j+i]=1;
        j+=i;
    }
    }
//for(int i=2;i<10;i++)
//printf("%d ",primes[i]);
scanf("%d",&test);
while (test--) {
scanf("%lld",&n);

if (n==0) {
printf("Yes\n");
continue;
}

bool mt=0;
for (int i=0; i<m; i++) {
int k=0;
while (n%primes[i]==0) {
if (primes[i]%4==3) k++;
n/=primes[i];
}
if (k%2!=0) {
printf("No\n");
mt=1;
break;
}
}
if (!mt && n%4!=3) printf("Yes\n");
else if (!mt) printf("No\n");
}
return 0;
}

