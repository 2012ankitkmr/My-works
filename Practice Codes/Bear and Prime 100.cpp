#include<bits/stdc++.h>
using namespace std;

int prime[20]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,4,9,25,49};

string s;
int main()
{
	int num,cnt =0;
	cout<<2<<endl;
	for(int i = 1 ;i < 20;i++){
	cin>>s;
	
	if(s=="yes")
    {
    	num = prime[i];
    	cnt++;
    }
    
    if(i!=19)
    {
   	fflush(stdout);
	cout<<prime[i]<<endl;
}
	}
	if(cnt <= 1)
	{
		cout<<"prime";
	}
	else
	{
		cout<<"composite";
	}
	
	return 0;
}
