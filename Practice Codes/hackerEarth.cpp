using namespace std;
#include<iostream>

int main(){
	
	int t,i,j,k,p,q,f;
	long unsigned int avg,c;
	cin>>t;
	long unsigned int a[t];
	cin>>avg;
	double d;

	for(i=0;i<t;i++){
		cin>>a[i];
	}
	
	for(i=0;i<t;i++){
		c=0;
		k=1;
		for(j=i;j<t;j++){
		c=c+a[j];
			d=(double)c/k;
		
		
			if(d==avg){
			q=i+1;
			f=0;
		p=k+i;
			break;	
			}
			k++;
		
		}
				
	}
	
	if(f==0)
	cout<<q<<" "<<p;
	else
	cout<<-1;
return 0;	
}
