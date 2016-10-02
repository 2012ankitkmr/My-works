using namespace std;
#include<iostream>

int main(){
	int i,a,b,c,f,g,j,k;
	
	cin>>a;
	for(i=0;i<a;i++){
			
		cin>>b;
		
		int d[100][100];
	for(j=0;j<b;j++)
	{
	for(k=0;k<100;k++){
		d[j][k]=0;
	}
	}
	
		for(j=0;j<b;j++){
			for(k=0;k<=j;k++){
				cin>>d[j][k];
				}

		}
	
	
	f=d[0][0];
	g=1;
	for(j=1;j<b;j++){
		
		for(k=j;k<=j;k++){
		if(d[j][k-1]>d[j][k]&&d[j][k-1]>d[j][k+1])
		{ f=f+d[j][k-1];
		g--;}	
	    else if(d[j][k]>d[j][k-1]&&d[j][k]>d[j][k+1]){
	    	f=f+d[j][k];
	    	}
			else{
			f=f+d[j][k+1];	    		
	    	g++;
			}
	    }
	
	}
	cout<<f;
	
	}
	return 0;
}

