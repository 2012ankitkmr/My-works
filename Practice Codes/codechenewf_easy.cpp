#include<iostream>
using namespace std;
#include<algorithm>

int main()
{
	int i,t,n,j,y,count=0,flag=0,p=0,x;
	int h[500],k[500];
	cin>>t;
	for(i=0;i<t;i++){
		cin>>n;

		for(j=0;j<n;j++){
			cin>>h[j];
		}

		for(j=0;j<n;j++){
			cin>>k[j];
		}
		sort(h,h+n);
		sort(k,k+n);
		y=0;
		for(j=0;j<n;j++)

		for(y=0;y<n;y++){
p=0;
			if(h[j]*2==k[y]){
				count++;
			}

			else if(k[y]>h[j]*2)
			break;
			else if(h[j]==k[y]){
				count+=2;
			cout<<count<<endl;

			}
            else
            {
                for(x=n-1;x>=0;x--){
                    if(2*h[j]>k[x])
                    { while(2*h[j]>=p)
                       {
                        p=p+k[x];
                        count++;
                        cout<<count<<endl;
                        break;
                    }
                    p=p-k[x];
                    }
                }
                flag=1;
                break;
            }
			}

	cout<<count;
	}
		return 0;
	}






