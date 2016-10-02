#include<bits/stdc++.h>
using namespace std;


double C,c1,c2,temp,r2,r1,r0,ans;
int main()
{
	//freopen("C-small-attempt1.in","r",stdin);
	//freopen("out.txt","w+",stdout);
	int t,m;
	cin>>t;
	for(int test = 1; test<=t ; test++)
	{
		cin>>m;
		if(m==1)
		{
			cin>>C;
		    cin>>c1;
			temp = c1-C;
			temp/=C;
			
			printf("Case #%d: %lf\n",test,temp);
			
		}
		if(m==2)
		{
			cin>>C;
			cin>>c1>>c2;
			
			r2= C;
			r1 = 2*C-c1;
			r0 = C-(c1+c2);
		
			 ans = - r1+sqrt(r1*r1-4*r2*r0);
			 ans /=(2*r2);
			 printf("Case #%d: %lf\n",test,ans);
		}
		
		
	}
	
	
	return  0;
}
