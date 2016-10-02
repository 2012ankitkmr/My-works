#include<bits/stdc++.h>
using namespace std;
int n, q, l, r;
int values[100005];
int dp_asc[100005], dp_dec[100005];
bool ladder;
int main() {
    scanf("%d%d", &n, &q);
    for (int i=0 ; i<n ; i++)
        scanf("%d", &values[i]);

    dp_asc[n-1] = dp_dec[n-1] = 0;
    for (int i=n-2 ; i>=0 ; i--) {
        if (values[i] <= values[i+1]) {
            dp_asc[i] = 1 + dp_asc[i+1];
        }
        else {
            dp_asc[i] = 0;
        }

        if (values[i] >= values[i+1]) {
            dp_dec[i] = 1 + dp_dec[i+1];
        }
        else {
            dp_dec[i] = 0;
        }
    }

    while (q--) {
        scanf("%d%d", &l, &r);
        l--, r--;
        ladder = false;
        if (r <= l+dp_asc[l] || r <= l+dp_dec[l] || r <= (l+dp_asc[l]) + dp_dec[l+dp_asc[l]])
            ladder = true;

        printf(ladder ? "Yes\n" : "No\n");
    }
return 0;
}
