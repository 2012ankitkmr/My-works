#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a[20];
	a[0]=4;
	a[1]=7;
	a[2]=44;
	a[3]=444;
	a[4]=77;
	a[5]=777;
	a[6]=447;
	a[7]=474;
	a[8]=744;
	a[9]=774;
	a[10]=747;
	a[11]=477;
	a[12]=74;
	a[13]=47;
int n,fl=0;
cin>>n;
for(int i=0;i<14;i++)
{
	if(n%a[i]==0)
	{
		fl=1;
		break;
	}
}
if(fl)
cout<<"YES";
else
cout<<"NO";
	
	return 0;
}
