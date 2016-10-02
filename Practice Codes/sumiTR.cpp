#include<bits/stdc++.h>
using namespace std;
#define s(x) scanf("%d",&x);
int a[102][102],t,n,i,j,d[102][102];int c(int i,int j){if(i>n||j>n)return 0;if(d[i][j]!=-1)return d[i][j];d[i][j]=max(c(i+1,j),c(i+1,j+1))+a[i][j];return d[i][j];}int main(){for(s(t);t--;){s(x);for(i=1;i<=n;i++)for(j=1;j<=i;j++)s(a[i][j]);memset(d,-1,10004);printf("%d\n",c(0,0));}return 0;}
