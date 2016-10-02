#include<iostream>
using namespace std;

int main()
{

int a,n,i,j,k,c,d;
 c=0;
    cin>>a;

    for(i=0;i<a;i++)
    {
        cin>>n;
        char b[n][n];
        for(j=0;j<n;j++)
        {
            for(k=0;k<n;k++)
        cin>>b[j][k];
        }
d=-3;
        for(k=n-1;k>=0;k--)
            {
                    for(j=n-1;j>=0;j--)
                    {
                    
if(j==k){
    if(b[j][j]=='#')
{c=c-d;
d++;
break;
}
}                     
else if(b[j][k]=='#')   
break;
                            else
                            c++;
                    }


            }
                        cout<<c<<"\n";
        }

        return 0;
    }




