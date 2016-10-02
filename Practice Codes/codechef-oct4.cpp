#include<iostream>
using namespace std;
#include<algorithm>
int main(){
	int t,i,r,b,m,g,k,j;
	long int d;
	cin>>t;
	for(i=0;i<t;i++){
		cin>>r>>g>>b;
		cin>>m;
	long signed int B[b],G[g],R[r];
  for(j=0;j<r;j++)
 cin>>R[j];

  for(j=0;j<g;j++)
 cin>>G[j];

  for(j=0;j<b;j++)
  cin>>B[j];
 
 sort(R,R+r);
 sort(G,G+g);
 sort(B,B+b);
 

for(j=1;j<=m;j++){
 	
 if(R[r-1]>G[g-1]&&R[r-1]>=B[b-1])
{
//cout<<"1 block";
	for(k=0;k<r;k++)
	R[k]=R[k]/2;
	
} 
else if(G[g-1]>=R[r-1]&&G[g-1]>B[b-1])
{//cout<<"2 block";
	for(k=0;k<g;k++)
	G[k]=G[k]/2;
	
}
else if(B[b-1]>R[r-1]&&B[b-1]>=G[g-1])
{//cout<<"3 block";
	for(k=0;k<b;k++)
	B[k]=B[k]/2;
	
}
else 
{//cout<<"last block";
for(k=0;k<b;k++)
	B[k]=B[k]/2;
}
}
  
 if(R[r-1]>G[g-1]&&R[r-1]>=B[b-1])
{
d=R[r-1];	
} 
else if(G[g-1]>=R[r-1]&&G[g-1]>B[b-1])
{
d=G[g-1];	
}
else if(B[b-1]>R[r-1]&&B[b-1]>=G[g-1])
{
d=B[b-1];	
} 

else
d=G[g-1];
 
 cout<<d<<"\n";
 
}
		return 0;
	}



