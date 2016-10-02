#include<bits/stdc++.h>
using namespace std;


int main()
{
	int t;
	freopen("in.txt","r",stdin);
//	freopen("out.txt","w+",stdout);
	cin>>t;
	char firstletter;
	int has[28],n,cnt,len,max_len;
	string s,temp,smax;
	
	for(int test = 1 ;test <=t ;test++)
	{
		cout<<endl;
		cout<<endl;
		cin>>n;
	//	scanf("*%c");
	getchar();
		max_len = INT_MIN;
		for(int i = 0;i<n;i++)
		{
              getline(cin,s);
              string original;
              original.assign(s);
	//		  cout<<s<<endl;
    
	s.erase(std::remove(s.begin(), s.end(), ' '), s.end());
	//		cout<<s<<endl;
			
			memset(has,0,sizeof(has));
			cnt = 0 ;
		for(int j = 0;j<s.length() ;j++)
		{
			if(has[s[j]-'A'])
			cnt++;
			has[s[j]-'A'] = 1;
		}
//		len = strlen(s);
	len = s.length();
printf("%5d  %5d   %5d   ",len,cnt,len-cnt);
cout<<original<<endl;

		if((len-cnt)>max_len)
		{
			max_len = len-cnt;
             smax.clear();
			smax.assign(original);
			firstletter = s[0];
		}
		
		if((len-cnt)==max_len)
		{
		if(firstletter<s[0])
		{
             smax.clear();
//			for(int j = 0 ;j<s.length() ; j++)
//			smax[j] = s[j];
            smax.assign(original);
			firstletter = s[0];
		}
			
		}
			
		}
		
		printf("Case #%d: ",test);
		cout<<smax<<endl;
	}
	return  0;
}
