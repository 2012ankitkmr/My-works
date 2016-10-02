#include<iostream>
#include<stdio.h>
#include<cstring>

using namespace std;

int min(int x,int y,int z,int w)
{
    int k=(x>y)?y:x;
    k=(k>z)?z:k;
    k=(k>w)?w:k;
    
    return k;
}
    

int main()
{
    while(true)
    {
               string a,b;
               
               cin>>a>>b;
               
               if(a=="*" && b=="*")
               break;
               
               int alen=a.length();
               int blen=b.length();
               
               int INF=alen+blen;
               
               int h[alen+2][blen+2];
               
               h[0][0]=INF;
               
               for(int i=0;i<=alen;i++)
               {
                       h[i+1][1]=i;
                       h[i+1][0]=INF;
               }
               
               for(int j=0;j<=blen;j++)
               {
                       h[1][j+1]=j;
                       h[0][j+1]=INF;
               }
               
               int C='z'+1;
               int da[C];
               
               for(int d=0;d<C;d++)
               da[d]=0;
               
               for(int i=1;i<=alen;i++)
               {
                       int db=0;
                       
                       for(int j=1;j<=blen;j++)
                       {
                               int i1=da[b[j-1]];
                               
                               int j1=db;
                               
                               int d=((a[i-1]==b[j-1])?0:1);
                               
                               if(d==0)
                               db=j;
                               
                               h[i+1][j+1]=min(h[i][j]+d,h[i+1][j]+1,h[i][j+1]+1,h[i1][j1]+(i-i1-1)+1+(j-j1-1));
                       }
                       
                       da[a[i-1]]=i;
               }
               
               printf("%d\n",h[alen+1][blen+1]);
               
    }
    
    system ("pause");
    
    return 0;
}

