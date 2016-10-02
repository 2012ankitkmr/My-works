#include<bits/stdc++.h>
using namespace std;

int x,y,n;

double fraction;
int nums[100005];

double diff(int num,int den)
{
double frac  = num/(double)den;
frac =  fraction - frac; 
return frac;	
}

int binary_search(int lo,int hi,int den)
{
if(hi>=lo)
{
	
	int mid =(hi+lo)/2;
	
	if(mid+1<=100000)
	{
	
	if(diff(mid,den)>=0&&diff(mid+1,den)<=0)
	{
		if(fabs(diff(mid,den))>fabs(diff(mid+1,den)))
		return mid+1;
		else
		return mid;
	} 
    }
    else
    return mid;
    if(diff(mid,den)>0)
    return binary_search(mid+1,hi,den);
    else
    return binary_search(lo,mid,den);
}
}

int main()
{

scanf("%d%d%d",&x,&y,&n);

fraction = x/(double)y;

for(int i = 1;i<=n;i++)
{
	nums[i] = binary_search(0,100000,i);
}	


double minval =1111111111111111.0;
int minNum,minDen;

for(int i = 1;i<=n;i++)
{
	if(minval>fabs(diff(nums[i],i))&&fabs((minval-fabs(diff(nums[i],i))))>1e-16)
	{
		minval = fabs(diff(nums[i],i));
		minNum = nums[i];
		minDen = i;
	//	printf("%.22lf n = %d, d = %d\n",minval,minNum,minDen);
	}
}
	
	printf("%d/%d\n",minNum,minDen);
	return  0;
}
