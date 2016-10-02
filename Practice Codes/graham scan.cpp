#include<bits/stdc++.h>
using namespace std;

struct Point
{
	int x;
	int y;
};
Point p0;

int orientation(Point p,Point q,Point r)
{
	int val=(q.y-p.y)*(r.x-q.x)-(r.y-q.y)*(q.x-p.x);
	if(val==0)
	return 0;
	
	return (val>0)?1:2;
}

Point nextToTop(stack<Point>&s)
{
	
	Point p=s.top();
	s.pop();
	Point res=s.top();
	s.push(p);
	return res;
}

int dis(Point p1,Point p2)
{
	return (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y);
	
}
int comp(const void *vp1,const void *vp2)
{
	Point*p1=(Point *)vp1;
	Point*p2=(Point *)vp2;
	int o=orientation(p0,*p1,*p2);
	if(o==0)
	return (dis(p0,*p2)>=dis(p0,*p1))?-1:1;
	return (o==2)?-1:1;
	
}

void swap(Point &pointA,Point &pointB)
{
	Point temp;
	temp=pointA;
	pointA=pointB;
	pointB=temp;
	
}
void convexhull(Point points[],int n)
{
int ymin=points[0].y,mini=0;
	for(int i=1;i<n;i++)
	{
		if(points[i].y<ymin||(ymin==points[i].y)&&(points[i].x<points[mini].x))
		{
		ymin=points[i].y,mini=i;	
		}
		
	}
	swap(points[0],points[mini]);
	
	p0=points[0];
	qsort(&points[1],n-1,sizeof(Point),comp);
stack<Point>s;
s.push(points[0]);
s.push(points[1]);
s.push(points[2]);
	
for(int i=3;i<n;i++)
{
	while(orientation(nextToTop(s),s.top(),points[i])!=2)
	s.pop();
	s.push(points[i]);
}	
	while(!s.empty())
	{
		Point p=s.top();
	printf("%d %d\n",p.x,p.y);
	s.pop();
	}
}
int main()
{
	 Point points[] = {{0, 3}, {1, 1}, {2, 2}, {4, 4},
                       {0, 0}, {1, 2}, {3, 1}, {3, 3}};
                int n=8;
				       
	convexhull(points,n);
	return 0;
}
