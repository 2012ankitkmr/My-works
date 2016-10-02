#include<iostream>
#include<vector>
using namespace std;
#define ll long long
#define vll vector<ll>
#define vv vector<vll>
#define vvv vector<vv>
int main()
{
// freopen("data.in", "r", stdin);
    int n,m,i,j,k,t,maxupidx[2],maxdownidx[2],chuanyue;
    ll downmax[2],upmax[2],right[2],up,down,max;
    cin>>n>>m;
    vll vl(m,0);
    vv v(n,vl);
    vvv vm(2,v),vt(2,v),vn(2,v);
    for(i=0;i<n;i++)//read data
    {
        for(j=0;j<m;j++)    
        {
            cin>>v[i][j];
        }
    }
    for(j=m-1;j>=0;j--) 
    {
        for(i=n-1;i>=0;i--)
        {
            for(t=0;t<2;t++)
            {//for each v[i][j], solve the maxmal vm[t][i][j], turning direction for maximum vt[t][i][j], turning column subscript vn[t][i][j] with t=0 represent using teleporting, t=1 otherwise.
                right[t]=-1;
                if(v[i][j]==-1)
                {
                    vm[t][i][j]=-1;
                    vt[t][i][j]=-1;
                    vn[t][i][j]=-1;
                    continue;   
                }
                if(j!=m-1&&vm[t][i][j+1]!=-1)   
                    right[t]=vm[t][i][j+1]+t*v[i][j];
                up=v[i][j];
                upmax[t]=-1;
                maxupidx[t]=i;
                if(t==0)
                {//using teleporting
                    k=i-1;
                    chuanyue=0;
                    while(k!=i) 
                    {
                        if(k<0||(v[k][j]==-1&&i!=n-1&&chuanyue==0))
                        {
                            chuanyue=1;
                            k=n-1;
                            up=0;
                            continue;       
                        }   
                        else if(v[k][j]==-1)
                        {
                            chuanyue=1;
                            k--;
                            up=0;
                            continue;       
                        }   
                        else
                        {
                            up+=v[k][j];
                            if(j<m-1)           
                            {
                                if(chuanyue==1&&up+vm[1][k][j+1]>upmax[t])
                                {
                                    upmax[t]=up+vm[1][k][j+1];
                                    maxupidx[t]=k;  
                                }
                                if(vm[0][k][j+1]>upmax[t])
                                {
                                    upmax[t]=vm[0][k][j+1];
                                    maxupidx[t]=k;  
                                }
                            }
                            else if(chuanyue==1&&up>upmax[t])
                            {
                                upmax[t]=up;
                                maxupidx[t]=k;  
                            }
                            k--;
                        }
                    }

                }
                else//never using teleporting
                {
                    up=0;
                    for(k=i;k>=0&&v[k][j]!=-1;k--)      
                    {
                        up+=v[k][j];
                        if(j<m-1&&vm[t][k][j+1]>=0&&up+vm[t][k][j+1]>upmax[t])          
                        {
                            upmax[t]=up+vm[t][k][j+1];
                            maxupidx[t]=k;  
                        }
                        else if(j==m-1&&up>upmax[t])
                        {
                            upmax[t]=up;
                            maxupidx[t]=k;  
                        }
                    }
                }
                down=v[i][j];
                downmax[t]=-1;
                maxdownidx[t]=i;
                if(t==0)
                {//using teleporting 
                    k=i+1;
                    chuanyue=0;
                    while(k!=i) 
                    {
                        if(k>n-1||(v[k][j]==-1&&i!=0&&chuanyue==0))
                        {
                            chuanyue=1;
                            k=0;
                            down=0;
                            continue;       
                        }   
                        else if(v[k][j]==-1)
                        {
                            chuanyue=1;
                            k++;
                            down=0;
                            continue;       
                        }   
                        else
                        {
                            down+=v[k][j];
                            if(j<m-1)           
                            {
                                if(chuanyue==1&&down+vm[1][k][j+1]>downmax[t])
                                {
                                    downmax[t]=down+vm[1][k][j+1];
                                    maxdownidx[t]=k;    
                                }
                                if(vm[0][k][j+1]>downmax[t])
                                {
                                    downmax[t]=vm[0][k][j+1];
                                    maxdownidx[t]=k;    
                                }
                            }
                            else if(chuanyue==1&&down>downmax[t])
                            {
                                downmax[t]=down;
                                maxdownidx[t]=k;    
                            }
                            k++;
                        }
                    }


                }
                else
                {//never using teleporting
                    down=0;
                    for(k=i;k<n&&v[k][j]!=-1;k++)       
                    {
                        down+=v[k][j];
                        if(j<m-1&&vm[t][k][j+1]>=0&&down+vm[t][k][j+1]>downmax[t])          
                        {
                            downmax[t]=down+vm[t][k][j+1];
                            maxdownidx[t]=k;    
                        }
                        else if(j==m-1&&down>downmax[t])
                        {
                            downmax[t]=down;
                            maxdownidx[t]=k;    
                        }
                    }
                }
                if(right[t]>=upmax[t]&&right[t]>=downmax[t])    
                {
                    vm[t][i][j]=right[t];
                    vt[t][i][j]=0;
                    vn[t][i][j]=i;
                }
                else if(upmax[t]>downmax[t])
                {
                    vm[t][i][j]=upmax[t];
                    vt[t][i][j]=1;
                    vn[t][i][j]=maxupidx[t];
                }
                else 
                {
                    vm[t][i][j]=downmax[t];
                    vt[t][i][j]=2;
                    vn[t][i][j]=maxdownidx[t];
                }
            // cout<<vm[t][i][j];
            }
        }
    }
    //this is for testing
// cout<<endl;
// for(t=0;t<2;t++)
// {
// for(i=0;i<n;i++)
// {
// for(j=0;j<m;j++) 
// {
// cout<<vm[t][i][j]<<" ";
// }
// cout<<" ";
// for(j=0;j<m;j++) 
// {
// cout<<vt[t][i][j]<<" ";
// }
// cout<<" ";
// for(j=0;j<m;j++) 
// {
// cout<<vn[t][i][j]<<" ";
// }
// cout<<endl;
// }
// cout<<endl;
// }
    max=-1;
    for(i=0;i<n;i++)
    {
        for(t=0;t<2;t++)
        {
            if(vm[t][i][0]>max) 
                max=vm[t][i][0];
        }
    }
    cout<<max<<endl;
    return 0;
}
