#include<iostream>
    #include<stdio.h>
    using namespace std;
    int main()
    {	int t,c,temp,day,count,k;
     //scanf("%d",&t);
    cin>>t;
     //printf("hi");
    cout<<"hello";
    while(t)
    {	t--;
    cout<<"hello";
    // printf("hi");
   cin>>c;//same prob..making it a comment solves it
   // scanf("%d",&c);
  cout<<"hello";
     //printf("hi");
    day=0;
    cout<<c;

     count=0;

    while(c)
    {


    

        temp=c;

    while(temp)
    {	//cout<<"gg";
        temp=temp>>1;
    count++;
    }
    k=1;
    temp=k<<count;
    c=c^temp;
    day++;

    }

    cout<<day<<"\n";

    }
    return 0;
    }
