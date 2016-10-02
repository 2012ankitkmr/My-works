#include<bits/stdc++.h>
using namespace std;
bool YES=0;
vector<int> ans;
string s;int tmp;
int m,ttl_wght,ttl_wght1;
void dfs(int cnt,int prev){
    if(YES)
        return;
    if(cnt==m)
    {
        YES=1;
        return;
    }
    for(int i=tmp;i<10;i++){
        tmp=0;
        if(s[i]=='1'&&i+1!=prev&&ttl_wght+i+1>ttl_wght1){
            ttl_wght=ttl_wght+i+1;
            ans.push_back(i+1);
            swap(ttl_wght,ttl_wght1);
            dfs(cnt+1,i+1);
            break;
        }
    }
}
int main(){
    cin>>s>>m;
    for(int start=0;start<10;start++){
        tmp=start;
        ttl_wght=ttl_wght1=0;
        ans.clear();
        dfs(0,0);
        if(YES){
            cout<<"YES"<<endl;
            int sz=ans.size();
            for(int i=0;i<sz;i++)
                cout<<ans[i]<<" ";
            cout<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
}
