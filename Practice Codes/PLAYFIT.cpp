#include<iostream>

int main(){
std::ios::sync_with_stdio(false);
	int t;
	std::cin>>t;
	long int n,i,a,e,ans;
	while(t--){
		std::cin>>n;
	ans=0;
		e=1000001;
		for(i=0;i<n;i++)
		{  
		std::cin>>a;

  if((a-e)>ans)
  ans=a-e;

 if(e>a)
  e=a;

  }
		if(ans==0)
		std::cout<<"UNFIT\n";
		else
		std::cout<<ans<<"\n";
	}
return 0;
}
