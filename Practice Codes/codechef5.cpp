using namespace std;
#include<iostream>
int main(){
	int a,b,i,j,c[b],d=0;
	cin>>a;
	for(i=0;i<a;i++){
		cin>>b;
		for(j=0;j<b;j++){
			cin>>c[j];
		}
		for(j=0;j<b;j++){
			if(c[j]<0)
		d++;
		}
	int e=0;// scope in the entire block
	if(d==0){
		for(j=0;j<b-1;j++){
			if(e>=0)
			e=c[j]-c[j+1];
			else
			e=e*c[j+1];
		}}
	
	if(d==b){
	int	f=0;
		e=c[0];//scope in this block
    if(d%2==0){
    	for(j=0;j<b;j++){
    		if(c[f]>c[j])
    		f=j;
    	}
    	for(j=0;j<b-1;j++){
    		if(f==0)
    		{
    		e=c[j]+c[j+1];
			f=f-2;}
    	else if(f==(j+1))
    	{if(j==1||j%2!=0)
    	e=(-1)*e+c[j+1];
		else
    	e=e+c[j+1];
		}
		else
    	e=e*c[j+1];
    	
		}
    }
  else
  e=e*c[j+1];  
	}
		
if(d!=b&&d!=0){
	e=c[0];
	if(d%2==0){
		for(j=0;j<b-1;j++){
			if(c[j]<0){
				if(c[j+1]>0)
				e=e*c[j+1];
				else{
					e=e+c[j+1];
				}
				}
			else {
				if(e<0&&c[j+1]<0)
				e=e+c[j+1];
				else
				e=e*c[j+1];
		
			}	
			
		}
		}
else
{for(j=0;j<b-1;j++)
e=e*c[j+1];
}
	
	
}		
		
cout<<e;
	}
return 0;
}
