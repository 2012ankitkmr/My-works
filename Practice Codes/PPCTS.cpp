#include<bits/stdc++.h>
using  namespace std;

int x[300004],y[300004],cnt_x[2000005],cnt_y[2000005];
char s[300005];
int main()
{
	int n,m;
	long long dis=0;
//	freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&m);
	int left=0,right=0,down=0,up=0;//no. of dog catchers below above left right to the axes
	for(int i=0;i<n;i++)
	{
		
		scanf("%d%d",&x[i],&y[i]);
		if(x[i]<0)
		left++;
		if(y[i]<0)
		down++;
		if(x[i]>0)
		right++;
		if(y[i]>0)
		up++;
	cnt_x[x[i]]++;
	cnt_y[y[i]]++;
	}
	
	for(int i=0;i<n;i++)
	{
		dis+=(abs(x[i]-0)+abs(y[i]-0));//distance from 0
	}
	
	int current_x=0,current_y=0;
	scanf("%s",s);
	// left , right , down , up , on_x , on_y
	for(int i=0;s[i];i++)
	{
		if(s[i]=='U')
		{
			dis+=down;
			dis-=up;
			dis+=cnt_y[current_y];
		    down+=cnt_y[current_y];
		    up-=cnt_y[current_y+1];
			current_y++;
		}
		if(s[i]=='L')
		{
			dis+=right;
			dis-=left;	
			dis+=cnt_x[current_x];
		    right+=cnt_x[current_x];
		   	left-=cnt_x[abs(current_x-1)];
			
			
			current_x--;			
		}
		if(s[i]=='D')
		{
			dis-=down;
			dis+=up;
			dis+=cnt_y[current_y];
		    down-=cnt_y[current_y-1];
			up+=cnt_y[current_y];
			
			current_y--;
			
		}
		if(s[i]=='R')
		{
			
			dis-=right;
			dis+=left;
	     	dis+=cnt_x[current_x];
		    right-=cnt_x[current_x+1];
		    left+=cnt_x[current_x];
			current_x++;			
			
		}
	printf("%d\n",dis);	
	//	dis=0;
	}

	return 0;
}
