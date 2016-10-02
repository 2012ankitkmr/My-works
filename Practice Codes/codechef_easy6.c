using namespace std;
#include<iostream>
#include<algorithm>

int main(){
	long unsigned int t;
	
	cin>>t;
	
	long unsigned int a[t];
	for(int i=0;i<t;i++){
	cin>>a[i];

	} 
	
	sort(a,a+t);
for(int i=0;i<t;i++)
{cout<<a[i]<<endl;
	
}

return 0;

}
