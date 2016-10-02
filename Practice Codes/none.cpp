#include<iostream>
#include<algorithm>
#include<math.h>
#include<bits/stdc++.h>
long long mod=1000000007;
long long arr[1020][1005];
long long lcm[1020][1005];
bool done[100005];
long long mult[10005];
long long pas[1020][1005];
using namespace std;
long long hcf(long long a,long long b){
    long long temp;
    if(b>a){
        temp=a;
        a=b;
        b=temp;
    }
    while(b!=0){
        temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}
int main(){
    memset(done,0,100004);
    ios::sync_with_stdio(false);
   /* for(int i=0;i<1020;i++){
        for(int j=0;j<505;j++){
            arr[i][j]=i;
            lcm[i][j]=i;
        }
    }*/
    /*for(int i=1;i<40;i++){
     for(int j=1;j<=i;j++){
     if(arr[i][j]==-1){
     if(arr[i-1][j-1]==-1||arr[i][j-1]==-1)
     cout<<"hey";
     //if(i==22&&j==22)
     //  cout<<arr[i-1][j-1]<<" "<<arr[i][j-1];
     arr[i][j]=(arr[i-1][j-1]*arr[i][j-1])/(arr[i][j-1]-arr[i-1][j-1]);}
     cout<<i<<","<<j<<"--"<<arr[i][j]<<"\n";
     
     }
     }*/
    int t,n,k,a,b,m;
    cin>>t>>n>>k;
    for(int i=1;i<1020;i++){
        arr[i][1]=i;
        lcm[i][1]=i;
        lcm[i][2]=i*(i-1);
        arr[i][2]=i*(i-1);
    }
    pas[1][0]=1;
    pas[1][1]=1;
   /* for(int i=2;i<1004;i++){
        arr[i][1]=i;
        
    }*/
    /*for(int i=2;i<1004;i++){
        pas[i][0]=1;
        pas[i][i]=1;
        arr[i][1]=i;
        for(int j=2;j<i;j++){
            arr[i][j]=(n*(pas[i-1][j-1]))%mod;
        }
        for(int j=1;j<i;j++){
            pas[i][j]=(pas[i-1][j-1]+pas[i-1][j])%mod;
        }
    }*/
    unsigned long long mul=1;
    //long long newm=1;
    // long long new3=1;
   /* for(int i=1;i<1005;i++){
        //int k=i;
        mul=1;
        for(int j=2;j<=(i+1)/2;j++){
            unsigned long long d=hcf((i-j+1),j-1);
            arr[i][j]=((arr[i][j-1]*(i-j+1))/(j-1))%mod;
            unsigned long long newm=(j-1)/d;
            unsigned long long new3=(i-j+1)/d;
            unsigned long long e=hcf(mul,new3);
            mul=newm*(mul/e);
           // if(mul>10e19)
             //   cout<<"hey";
            //cout<<i<<" "<<j<<" "<<mul<<"\n";
            //long long c=hcf(lcm[i][j-1],arr[i][j]);
            lcm[i][j]=(arr[i][j]*mul)%mod;
        }
    }*/
    arr[n][1]=n;
    lcm[n][1]=n;
    int y=0;
    mult[y]=1;
    for(int j=2;j<=(n+1)/2;j++){
        mul=1;
        unsigned long long d=hcf((n-j+1),j-1);
        arr[n][j]=((arr[n][j-1]*(n-j+1))/(j-1))%mod;
        unsigned long long newm=(j-1)/d;
        unsigned long long new3=(n-j+1)/d;
        for(int k=0;k<=y;k++){
            if(mult[k]==1)
                continue;
            long long f=hcf(mult[k],new3);
            mult[k]/=f;
            mul=(mul*mult[k])%mod;
            new3/=f;
        }
        mul=(mul*newm)%mod;
        y++;
        mult[y]=newm;
        // unsigned long long e=hcf(mul,new3);
        //mul=newm;
        // if(mul>10e19)
        //   cout<<"hey";
        //cout<<i<<" "<<j<<" "<<mul<<"\n";
        //long long c=hcf(lcm[i][j-1],arr[i][j]);
        lcm[n][j]=(arr[n][j]*mul)%mod;
    }
    done[n]=true;
 
    //cout<<lcm[3][2]<<"\n";
    if(k>(n+1)/2)
        k=(n+1)/2;
    /* if(n>1020||k>1005||k<0||n<0){
     n=5;
     k=5;
     }*/
    // cout<<mul<<"\n\n";
    lcm[n][k]%=mod;
    cout<<lcm[n][k]<<"\n";
    long long ans=lcm[n][k];
    
	for(int i=1;i<=n;i++)
	{
	for(int j=1;j<=n;j++)
	printf("%d ",lcm[i][j]);	
	printf("\n");
	}
   /* int c[t];
    int d[t];
    for(int i=0;i<t-1;i++)
        cin>>c[i];
    for(int i=0;i<t-1;i++)
        cin>>d[i];*/
    t--;
    int l=0;
  /*  while(t--){
        //long long temp=ans%m;
        int n=l+1;
        //temp=ans%n;
 
        for(int o=1;o<n;o++){
        	int k=o;
        if(!done[n]){
            arr[n][1]=n;
            lcm[n][1]=n;
            int x=0;
            mult[x]=1;
            for(int j=2;j<=(n+1)/2;j++){
                mul=1;
                unsigned long long d=hcf((n-j+1),j-1);
                arr[n][j]=((arr[n][j-1]*(n-j+1))/(j-1))%mod;
                unsigned long long newm=(j-1)/d;
                unsigned long long new3=(n-j+1)/d;
                for(int k=0;k<=x;k++){
                    if(mult[k]==1)
                        continue;
                    long long f=hcf(mult[k],new3);
                    mult[k]/=f;
                    mul=(mul*mult[k])%mod;
                    new3/=f;
                }
                mul=(mul*newm)%mod;
                x++;
                mult[x]=newm;
               // unsigned long long e=hcf(mul,new3);
                //mul=newm;
               // if(mul>10e19)
                 //   cout<<"hey";
                //cout<<i<<" "<<j<<" "<<mul<<"\n";
                //long long c=hcf(lcm[i][j-1],arr[i][j]);
                lcm[n][j]=(arr[n][j]*mul)%mod;
            }
            done[n]=true;
 
 
        }
        if(k>(n+1)/2)
            k=(n+1)/2;
        //cout<<n<<" "<<k<<"\n";
       /* if(n>1020||k>1005||n<0||k<0){
            n=5;
            k=5;
        }
        lcm[n][k]%=mod;
     //   cout<<n<<" "<<k<<" "<<lcm[n][k]<<"\n";
        ans=lcm[n][k];
        //l++;
 
    }
    l++;
    }*/
}
