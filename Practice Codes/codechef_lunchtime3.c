#include<iostream>
using namespacestd;
int main(){
	int a,i;
	long int count,j,k,m,n[10000],f;
	double d;
	cin>>a;
	
	for(i=0;i<a;i++){
		cin>>m>>f;
		for(j=0;j<m;j++){
			cin>>n[j];
		}
		count=0;
		sort(n,n+m);
		
		for(j=m-1;j>=0;j--){
			d=(double)n[j]/(double)f;
			while(d>=1){
				for(k=j-1;k>=0;k--)
				{ 
				if(d==n[k])
				count++;
             } 
		d=d/f;
		}
		}
		f=0;
		for(j=0;j<m-1;j++){
			if(n[j]==n[j+1])
			f++;
			if(n[j+1]!=n[j+2])
        {	while(f>=1){
			count=count+f;
			f--;
		}  f=0;
             }			
	}
		cout<<count;
	}
	return 0;
}
