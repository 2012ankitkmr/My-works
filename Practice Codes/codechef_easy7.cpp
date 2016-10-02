using namespace std;
#include<iostream>
#include<algorithm>

int main(){
	int t,i;
	
	cin>>t;
	
	long unsigned int a[t];
	for(i=0;i<t;i++){
	cin>>a[i];

	} 
		sort(a,a+t);

for(i=0;i<t;i++)
{
cout<<a[i]<<endl;
}

return 0;

}
