#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
struct point{
	int x,y;
};
double dis(point p,point q)
{
	return sqrt((double)((p.x-q.x)*(p.x-q.x)+(p.y-q.y)*(p.y-q.y)));
}

int main()
{
	point p1,p2,p3;
	double dis12,dis23,dis31,angle1,angle2,angle3,parameter;
	freopen("in.txt","r",stdin);
	pair<int,int>vect[2];
	int ID,test;
	scanf("%d",&ID);
	for(scanf("%d",&test);test--;)
	{
		scanf("%d%d%d%d%d%d",&p1.x,&p1.y,&p2.x,&p2.y,&p3.x,&p3.y);
		dis12=dis(p1,p2);
		dis23=dis(p2,p3);
		dis31=dis(p3,p1);
		if(ID==1)
		{
		if((fabs(dis12-dis23)<10e-6)||(fabs(dis23-dis31)<10e-6)||(fabs(dis31-dis12)<10e-6))
		printf("Isosceles triangle\n");
		else
		printf("Scalene triangle\n");	
		}
		else
		{
	if((fabs(dis12-dis23)<10e-6)||(fabs(dis23-dis31)<10e-6)||(fabs(dis31-dis12)<10e-6))
        printf("Isosceles ");
        else
        printf("Scalene ");
        dis12=dis12*dis12;
        dis23=dis23*dis23;
        dis31=dis31*dis31;
        if(fabs(dis12+dis23-dis31)<0.000001||fabs(dis31+dis23-dis12)<0.000001||fabs(dis12+dis31-dis23)<0.000001)
            printf("right triangle\n");
        else if(dis12+dis23<dis31||dis23+dis31<dis12||dis12+dis31<dis23)
            printf("obtuse triangle\n");
        else
            printf("acute triangle\n");
		
			
		}
		
	}
	return 0;
}
