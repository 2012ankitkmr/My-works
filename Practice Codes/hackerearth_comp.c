using namespace std;
#include<iostream>
std::ios::sync_with_stdio(false);
int main(){
int a,b,i,j;
cin>>a>>b;
long signed int c[a][b];
for(i=0;i<a;i++){
for(j=0;j<b;j++){
cin>>c[i][j];
}
}
int t,k,x,y,flag;
long signed int q;
cin>>t;
for(k=0;k<t;k++){
        flag=0;
    cin>>q;

    for(i=0;i<a;i++){
        for(j=0;j<b;j++){
            if(c[i][j]==q){
                x=i;
                y=j;
                flag=1;
            }

    }
    }
if(flag==1)
   cout<<x" "<<y;
   else
    cout<<-1<<" "<<-1;
}

return 0;
}
