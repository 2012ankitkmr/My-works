using namespace std;

#include<iostream>
#include<algorithm>

int main(){
int i,b,j;
long a;
cin>>a;
while(a>0)
{
cin>>b;
int d[b];
for(i=0;i<b;i++)
{
    cin>>d[i];
cout<<" ";
}
sort(d,d+b);

cout<<d[0]+d[1];
a--;
}

return 0;
}


