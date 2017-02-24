#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,x,y,z,x_i=0,y_i=0,z_i=0;
	scanf("%d",&n);
for(int i =0;i<n;i++)
{
	scanf("%d%d%d",&x,&y,&z);
	x_i+=x;
	y_i+=y;
	z_i+=z;
}
if(x_i==0&&y_i==0&&z_i==0)
printf("YES\n");
else
printf("NO\n");
	
	
	return  0;
}
