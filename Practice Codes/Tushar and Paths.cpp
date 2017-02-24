#include <iostream>
#define ll long long
#define MOD 1000000007LL

using namespace std;
struct matrix
{
    ll a[2][2];
    matrix()
    {
        a[0][0]=0;a[0][1]=0;
        a[1][0]=0;a[1][1]=0;
    }
    matrix(ll x,ll y,ll z,ll t)
    {
        a[0][0]=x;a[0][1]=y;
        a[1][0]=z;a[1][1]=t;
    }
};
matrix operator*(matrix,matrix);
ll n;
matrix S=matrix(1,0,0,1),A=matrix(2,1,3,0);
int main()
{
    cin>>n;
    while(n)
    {
        if(n%2)
            S=S*A;
        A=A*A;
        n/=2;
    }
    cout<<S.a[1][1];
    return 0;
}
matrix operator*(matrix A,matrix B)
{
    matrix R;
    R.a[0][0]=(A.a[0][0]*B.a[0][0]+A.a[0][1]*B.a[1][0])%MOD;
    R.a[0][1]=(A.a[0][0]*B.a[0][1]+A.a[0][1]*B.a[1][1])%MOD;
    R.a[1][0]=(A.a[1][0]*B.a[0][0]+A.a[1][1]*B.a[1][0])%MOD;
    R.a[1][1]=(A.a[1][0]*B.a[0][1]+A.a[1][1]*B.a[1][1])%MOD;
    return R;
}
