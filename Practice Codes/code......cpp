#include<iostream>
using namespace std;
int main(){

long unsigned int t,n,i,gras,j;
long int dnv=0;
long int d[100000];

cin>>t;

for(i=0;i<t;i++){
cin>>n;
gras=0;
for(j=0;j<n;j++)
cin>>d[j];

for(j=0;j<n;j++){
dnv=dnv+d[j];
if(dnv>0)
gras=gras+dnv;
else
gras=gras-dnv;
}
if(dnv==0)
cout<<gras<<"\n";
dnv=0;
}
return 0;
}
