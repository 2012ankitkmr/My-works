#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

double a[4005];
double ceil_a[4005];
double floor_a[4005];
double cha[4005];

int main()
{
    //freopen("in.txt", "r", stdin);

    int n;
    scanf("%d", &n);

    double res = 0;
    for (int i = 0; i < 2 * n; ++i) {
        scanf("%lf", &a[i]);
        ceil_a[i] = ceil(a[i]);
        floor_a[i] = floor(a[i]);
        cha[i] = ceil_a[i] - floor_a[i];
        res += ceil_a[i] - a[i];
    }
    sort(cha, cha + 2 * n);
    int l = 0, r = 2 * n - 1;
    for (int i = 0; i < n; ++i) {
        if (res > 0.5) res -= cha[r--];
        else res -= cha[l++];
    }

    printf("%.3f\n", abs(res));
    return 0;
}
