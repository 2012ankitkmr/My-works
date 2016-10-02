#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a[11];
	vector<int>vec;
	int amount,flag=-1,max_digit=0,temp,residue;
	scanf("%d",&amount);
	for(int i=1;i<=9;i++)
	scanf("%d",&a[i]);
	
		
	for(int i=1;i<=9;i++)
	{
	temp=amount/a[i];
	if(temp>max_digit)
		max_digit=temp;
	}
if(max_digit==0)
	printf("-1");
else
{	
		for(int i=1;i<=9;i++)
		{
			temp=amount/a[i];
			
			
			if(temp==max_digit)
			{
				int num=temp;
				while(temp--)
			{
				vec.push_back(i);
			}
			
				
		int pointer=0;		
		//	printf("here\n");
			residue=amount-num*a[i];
			//printf("%d,,\n",residue);
			for(int k=0;k<vec.size();k++)
			{
			
			for(int j=9;j>=i;j--)
			if(residue+a[i]>=a[j])
			{
			vec[pointer++]=j;
			residue=residue+a[i]-a[j];
		    break;
			}
		    
	        }
			break;
		    }
		
		}
	for(int i=0;i<vec.size();i++)
	printf("%d",vec[i]);
	
}
	
	return 0;
}
	
