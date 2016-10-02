#include <iostream>
using namespace std;
#define lli long long int
lli next_int()
{
        lli n = 0;
        char c = getchar_unlocked();
        while (!('0' <= c && c <= '9'))
        {
                c = getchar_unlocked(); 
        }
        while ('0' <= c && c <= '9')
        {
                n = (n<<3)+(n<<1) + c - '0';
                c = getchar_unlocked();
        }
        return n;
}
int main() 
{
	lli t,n,arr[50005],i,sum,ank[50005];
     t=next_int();
    while(t--)
    {
       n=next_int();
       sum=0;
       for(i=0;i<n;i++)
       { arr[i]=next_int(); 
	   sum+=arr[i];}
	   sum/=(n-1);
	   for(i=0;i<n;i++)
	   {
	   	 ank[i]=sum-arr[i];
	   }
	   for(i=0;i<n;i++) cout<<ank[i]<<" ";
	   cout<<endl;
    }
	return 0;
}
