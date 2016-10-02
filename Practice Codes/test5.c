#include <iostream>

#include<cstring>

using namespace std;

int cnt(char num[],int s,int t)

{

   int i,j,count = 0; 
   int n = strlen(num);

    for (i = s; i <=t; i++)

   {

        int sum = num[i] - '0';  

        if (num[i] == '9'||num[i] == '3'||num[i] == '6'||num[i] == '0') count++;
        for (j = i+1; j <=t; j++)
        {
            sum = (sum + num[j]-'0')%3;
			            if (sum == 0)
              count++;
     }
    }
    return count;
 }
 
int main() 
{

	char c[1000008];

	int n,q;

	cin>>n>>q;

	cin>>c;

	while(q--)

	{

		int a,b,d;

		cin>>a>>b>>d;

		if(a==1)

		{

			b--;

			c[b]=d+'0';

	}
		else
		{
			b--;d--;
		cout<<cnt(c,b,d)<<endl;
		}
	}
	return 0;
}

