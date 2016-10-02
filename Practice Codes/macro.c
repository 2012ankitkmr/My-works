
#include<iostream>
#define gr8r(x,y,z) if(x>y&&x>z){return x;} if(y>x&&y>z){return y;} else{return z;}
main(){
int x=8,y=7,z=55,k;
k=gr8r(x,y,z);
cout<<k;

}
