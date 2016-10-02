#include<iostream>
using namespace std;
#include<algorithm>
int main(){
	int t,i,r,b,g,m,j;
	cin>>t;
	for(i=0;i<t;i++){
		cin>>r>>g>>b;
		cin>>m;
		long unsigned int c;
		c=r+b+g;
		long unsigned int all[c];
		for(j=0;j<c;j++)
		cin>>all[j];
 
		sort(all,all+c);
		j=c-1;
		while(m>0){
			all[j]=all[j]/2;
			sort(all,all+c);
		    m--;
		}
			cout<<all[j]<<"\n";
		}
		return 0;
	}
