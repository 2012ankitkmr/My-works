using namespace std;
#include<iostream>
#include<cstdlib>
#include<ctime>
 main(){
int random,i,j;
 srand(time(NULL));
random=rand()%12 + 1;

for(i=0;i<12;i++){
for(j=0;j<12;j++){
        cout<<"#";
    }
    cout<<"\n";
}
 return 0;}
