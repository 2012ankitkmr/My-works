
#include<stdio.h>
#include<conio.h>
#define infinity 999
#define max 10
int G[max][max],Q[max];
int n,path[max],p[max];
int dest,scr,y,z;
void display(int,int);
void main()
{
void buildgraph();
void dijkstra(int,int);
void insert(int,int);
void insertq(int);
int front,rear;

printf("\nProgram for the shortest path algorithm using priority queue");
printf("\nEnter the number of the vertices:");
scanf("%d",&n);
buildgraph();
printf("\nEnter the source");
scanf("%d",&scr);
printf("\nEnter the destination");
scanf("%d",&dest);
dijkstra(scr,dest);
for(y=1;y<=max;y++)
p[y]=infinity;
printf("\nThe shortest path is:\n\t");
display(dest,scr);
printf("%d",dest);
getch();
}
void display(int dest,int scr)
{
int z=1;
while(dest>scr)
{
int a;
a=path[dest];
if(a!=scr)
{
p[z]=a;
}
else
{
p[z]=a;
}
++z;
dest=a;
}
for(y=max;y>0;y--)
{
if(p[y]!=infinity)
{
printf("%d",p[y]);
}
}
}
void buildgraph()
{
int i,j,v1,v2;
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
printf("\nEnter the edge of v%d to v%d:",i,j);
scanf("%d",&G[i][j]);
}
printf("\n");
}
}
void insertq(int index)
{
Q[index]=1;
}
void insert(int index,int vertex)
{
path[index]=vertex;
}
void dijkstra(int scr,int dest)
{
int small,dist[10],current,start,new1;
int temp,i,a[10];
void insertq(int);
for(i=0;i<=n;i++)
{
a[i]=0;
dist[i]=infinity;
}
Q[scr]=1;
dist[scr]=0;
current=scr;
while(current!=dest)
{
small=infinity;
start=dist[current];
for(i=1;i<=n;i++)
{
if(Q[i]==0)
{
new1=start+G[current][i];
if(new1<dist[i])
{
dist[i]=new1;
insert(i,current);
}
if(dist[i]<small)
{
small=dist[i];
temp=i;
}
}
}
current=temp;
insertq(current);
}
printf("\nThe minimum cost is:%d",new1);
}

