#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265

double dist(int x1,int y1,int x2,int y2)
{
	return (double)(sqrt(pow(x1-x2,2)+pow(y1-y2,2)));
}



int main()
{
	freopen("progress_pie.txt","r+",stdin);
	freopen("out.txt","w+",stdout);
int t,p,x,y;
cin>>t;
double th1,th2,d;
for(int test = 1 ; test <= t ; test++)
{
scanf("%d%d%d",&p,&x,&y);	

th1 = p*3.60;
d = dist(x,y,50,50);
if((d-50.0000000)>1e-6)
{
	printf("Case #%d: white\n",test);
}
else if(p==0)
{
	printf("Case #%d: white\n",test);
}
else
{
	if(x<50)
	{
		if((th1-180.00)<1e-6)
		{
			printf("Case #%d: white\n",test);
		}
		
		x = abs(x-50) + 50;
		y = -1*(y-50) + 50;
		th1-=180.00;
	}

	th2 = asin(abs(y-50)/d)*180.0/PI;

	if(y<50)
	{
		th2 +=90.00;
	}
	else
	th2 = 90 - th2;
	
//	printf("%lf %lf\n",th1,th2);
	if(fabs(th1-th2)<1e-6)
	{
	printf("Case #%d: black\n",test);
	}
	else if(th1>th2)
	{
		printf("Case #%d: black\n",test);
	}
	else
	{
		printf("Case #%d: white\n",test);
	}
}
	
}		
	return 0;
}
