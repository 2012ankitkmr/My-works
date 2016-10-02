using namespace std;
#include<iostream>
 int main(){
 long unsigned int a,i,j;

 cin>>a;
 long unsigned int b[a],c=0;

 for(i=0;i<a;i++){

cin>>b[i];
     }
for(i=0;i<a;i++){
    for(j=i;j<a;j++){
        if(j!=i){
           if(c<(b[i]&b[j]))
            c=b[i]&b[j];
        }
    }
}
cout<<c;
 return 0;
 }
