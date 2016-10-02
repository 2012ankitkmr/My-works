using namespace std;
#include<iostream>


int main(){

int a,i,j,b,h,c[b],d,f=0;
cin>>a;
for(i=1;i<=a;i++)
{ cin>>b;
f=1;

for(j=0;j<b;j++)
  {
  cin>>c[j];
cout<<" ";
	}

for(j=0;j<b;j++){
d=0;
    for(h=1;h<=c[j];h++)
	{
    if(c[j]!=c[d]){
    if((c[j]%h)==0)
		 f++;
}
}
}
        cout<<f;
}
return 0;
}
