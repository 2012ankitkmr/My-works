#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

int main(){
	int t,x,sz;
	bool fix;
	char s[1000002];

	scanf("%i",&t);
	while(t--){
		
		cin>>s;
		sz=strlen(s);
		x=(sz)/2-1;
		cout<<sz<<endl;
		cout<<x<<endl;
		//check from center if it needs to be added
		while(s[x]==s[sz-x-1])
		{x--;
        cout<<s[x]<<endl;
		}
		if(s[sz-x-1]>s[x])
			fix=true;
		else
			fix=false;
		for(x=0;x<sz/2;x++)
			s[sz-x-1]=s[x];
		x=(sz+1)/2-1;
		while(fix){
			if(s[x]<'9'){
				fix=false;
				s[x]+=1;
				s[sz-x-1]=s[x];
			}
			else{
				s[x]='0';
				s[sz-x-1]=s[x];
				x-=1;
				if(x<0){
					s[0]='1';
					s[sz]='1';
					s[sz+1]=0;
					fix=false;
				}
			}
		}
		printf("%s\n",s);
		if(fix)printf("Fix\n");
	}
}
