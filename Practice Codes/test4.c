#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
int a[100005];
void build(vi&st,vi&v,int ver,int l,int r)
{
if(l==r)
st[ver]=v[l];
else
{
    build(st,v,2*ver,l,(l+r)/2);
    build(st,v,2*ver+1,(l+r)/2+1,r);
    st[ver]=st[2*ver]+st[2*ver+1];
}
}
void create(vi&st,vi&v)
{
int l=(int)(2*pow(2.0,floor((log((double)v.size())/log(2.0))+1))); 
st.assign(l,0);
build(st,v,1,0,v.size()-1);
}
int res(vi&st,vi&v,int ver,int l,int r,int i,int j)
{
if(j<l || i>r)return -1;
else if(l==r)
return st[ver];
else
{
    int p1=res(st,v,2*ver,l,(l+r)/2,i,j);
    int p2=res(st,v,2*ver+1,(l+r)/2+1,r,i,j);
    if(p1==-1)return p2;
    if(p2==-1)return p1;
    else
    return p1+p2;
}
}
void update(vi&st,vi&v,int ver,int l,int r,int i,int diff)
{
if(i<l || i>r) return;
st[ver]+=diff;
if(l!=r)
{
update(st,v,2*ver,l,(l+r)/2,i,diff);
update(st,v,2*ver+1,(l+r)/2+1,r,i,diff);
}
}
int main()
{
int t,n,q,x,y,z,f=1;
scanf("%d",&t);
while(t--)
{
    scanf("%d%d",&n,&q);
    for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
    vi v(a,a+n);
    vi st;
    create(st,v);
    int l=st.size();
    printf("Case %d:\n",f++);
    for(int i=0;i<q;i++)
    {
        scanf("%d",&x);
        if(x==1)
        {
        scanf("%d",&y);
        printf("%d\n",v[y]);
        int diff=0-v[y];
        v[y]=0;
        update(st,v,1,0,v.size()-1,y,diff);
        }
        else if(x==2)
        {
        scanf("%d%d",&y,&z);
        v[y]+=z;
        update(st,v,1,0,v.size()-1,y,z);   
        }
        else
        {
        scanf("%d%d",&y,&z);
        printf("%d\n",res(st,v,1,0,v.size()-1,y,z));   
        }
    }
}
 return 0;
} 
