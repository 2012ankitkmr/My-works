#include<bits/stdc++.h>
using namespace std;


int main(){
    int n,a[100005],ret[100005];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i - 1] < a[i])  ret[i] = ret[i - 1] + 1;
        else  ret[i] = 1;
    }
    int maxnum = 0;
    int cur = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        maxnum = max(maxnum,ret[i - 1] + 1);
        maxnum = max(maxnum,cur + 1);
        if (i == 0 || i == n - 1 || a[i - 1] + 1 < a[i + 1])
        {
            maxnum = max(maxnum,ret[i - 1] + cur + 1);
        }
        if (a[i] < a[i + 1])  cur++;
        else cur = 1;
    } 
    cout << maxnum << endl;
    return 0;
}
