using namespace std;
#include<iostream>
 
int main(){
int a,i; 
cin>>a;
long unsigned int b[a];
for(i=0;i<a;i++){
	int k,j;
for(j=0;j<a;j++)
   cin>>b[j];
int d=0;

 for(k=0;k<a;k++){
 for(j=k;j<a;j++){
if(k!=j)
{
if(d>b[j]&b[k]);
d=b[j]&b[k];
}}
}
cout<<d;
}
return 0;
} 
