#include<bits/stdc++.h>
#define f(a,b,c) for(int a=b;a<c;a++)
#define s(x) scanf("%lld",&x)
#define p(x) printf("%lld\n",x);
using namespace std;

typedef long long ll;
ll mod=1e9+7;

void input(){
     #ifndef ONLINE_JUDGE
        freopen("inp.txt","r",stdin);
     #endif
}




#define max1 100010
#define ll long long

ll tree[max1],a[max1];
ll read(int index){
        ll count1=0;
        while(index>0){
            count1+=tree[index];
            index-=(index & (-index));
        }
        return count1;
}
void update(int index,ll value){
        while(index<max1){
             tree[index]+=value;
             index+=(index & (-index));
        }
}

int main(){
    input();
ll t,n,q,x,y,l,r,v,casev=1;
s(t);
while(t--){
    s(n),s(q);
    memset(tree,0,sizeof(tree));
    for(int i=1;i<=n;i++){
        s(a[i]);
    }

    printf("Case %d:\n",casev++);
    while(q--){
        char c;
        ll u,v,k;
        scanf("%c",&c);
        scanf("%c",&c);
        switch(c){
            case 'w':
                    s(u),s(v),s(k);
                    update(u,k);
                    update(v+1,-k);
                    break;
            case 'm':
                    s(u);
                    v=read(u);
                    a[u]=-v;
                    break;
            case 'f':
                    s(u);
                    printf("%lld\n",read(u)+a[u]);
                    break;

        }


    }printf("\n");
}



return 0;
}
