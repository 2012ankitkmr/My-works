#include<bits/stdc++.h>
using namespace std;
int main(){
long long int t;
long long int m[3],r,c,f,gg,h[3],cnt;
cin>>t;
while(t--)
{
    f=0;
    memset(h,0,sizeof(h));
cin>>r>>c>>m[0]>>m[1]>>m[2];
if(m[0]+m[1]+m[2]>r*c)
{
cout<<"No"<<endl;
continue;
}
cnt=0;
while(cnt<3)
{
    gg=-1;
    for(int i=0;i<3;i++)
    if(h[i]==0 && (m[i]%r==0 || m[i]%c==0) ) gg=m[i] , h[i]=1, cnt++;
    if(gg==-1)
    {
        cout<<"No"<<endl;
        f=1;
        break;
    }
if(gg%r==0)
{
c-=gg/r;
}else if(gg%c==0)
{
r-=gg/c;
}

if(f)
    break;
if(r<0 || c<0)
{
    f=1;
    cout<<"No\n";
    break;
}
}
if(!f)
    cout<<"Yes"<<endl;
}


return 0;
}
