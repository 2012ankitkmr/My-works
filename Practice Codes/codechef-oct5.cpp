#include<iostream>
using namespace std;

int main(){
	int t,i;
	long signed int n,k,m,j;
	long unsigned int e;
	cin>>t;
	for(i=0;i<t;i++){
		cin>>n>>m;
		long signed int M[m];
		char c[m];
	for(j=0;j<m;j++){
	cin>>c[j];
	cin>>M[j];	
	}

for (j = 0 ; j < ( m - 1 ); j++)
  {
    for (k = 0 ; k < m - j - 1; k++)
    {
      if (M[k] > M[k+1]) // For decreasing order use < 
      { 
        e     = M[k];
        M[k]   = M[k+1]; 
        M[k+1] = e;
        e=c[k];
		c[k]=c[k+1];
		c[k+1]=e;
      }
    }
  }
	
	for(j=1;j<m;j++){
		if(c[j]==c[j-1])
		M[j]=M[j-1]+1;
	}
	e=1;
	if(m==1)
	e=1;
	
		for(j=1;j<m;j++){
			k=M[j]-M[j-1];
	      		
			e=e*k;
		}
		
		e=e%1000000009;
		cout<<e<<"\n";
	}
	
return 0;
}
