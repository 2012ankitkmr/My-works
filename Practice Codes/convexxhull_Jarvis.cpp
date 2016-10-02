#include<bits/stdc++.h>
using namespace std;

#define INF 10000
struct point 
{
int x,y;
	
};
int next[INF];
int orientation(point p,point q,point r)
{
int val=(q.y-p.y)*(r.x-q.x)-(r.y-q.y)*(q.x-p.x);
if(val==0)
return 0;
	return (val>0)?1:2;
}
void convexhull(point points[],int n)
{
	if(n<3)
	return ;
	memset(next,-1,sizeof next);
	int l=0;
	for(int i=1;i<n;i++)
	{
		if(points[i].x<points[l].x)
		l=i;
	}
	int p=l,q;
	
	do
	{
		q=(p+1)%n;
		for(int i=0;i<n;i++)
		if(orientation(points[p],points[i],points[q])==2)//counter clockwise
		q=i;//update q
		
		next[p]=q;
		p=q;
	}while(p!=l);
	for(int i=0;i<n;i++)
	{
		if(next[i]!=-1)
		printf("%d %d\n",points[i].x,points[i].y);
	}
}
int main()
{
point points[] = {{0, 3}, {2, 2}, {1, 1}, {2, 1},
                      {3, 0}, {0, 0}, {3, 3}};
                      
int n=7;
convexhull(points,n);	
	return 0;
}
