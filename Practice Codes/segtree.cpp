#include<bits/stdc++.h>
#include<math.h>
using namespace std;

int getmid(int a,int b)
{
	return a+(b-a)/2;
}
void updateutil(int *st,int ss,int se,int i,int diff,int index)
{
	if(i<ss||i>se)
	return;
	st[index]=st[index]+diff;
	if(ss!=se)
	{
		int mid=getmid(ss,se);
		 updateutil(st,ss,mid,i,diff,2*index+1);
		 updateutil(st,mid+1,se,i,diff,2*index+2);
	}
	
}

void updatevalue(int arr[],int *st,int n,int i,int val)
{
	if(i<0||i>n)
	return;
	int diff=val-arr[i];
	arr[i]=val;
	updateutil(st,0,n-1,i,diff,0);
	
}

int getsum(int *st,int ss,int se,int qs,int qe,int index)
{
	if(ss<0||ss>se||qs<0||qs>qe||se<qs||ss>qe)
	return 0;
	if(qs<=ss&&qe>=se)
	return st[index];
	
	int mid=getmid(ss,se);
	return getsum(st,ss,mid,qs,qe,2*index+1)+getsum(st,mid+1,se,qs,qe,2*index+2);
}

int constructutil(int arr[],int ss,int se,int *st,int si)
{
	if(ss==se)
	{
		st[si]=arr[se];
		return arr[ss];
	}
	
	int mid=getmid(ss,se);
	st[si]=constructutil(arr,ss,mid,st,2*si+1)+constructutil(arr,mid+1,se,st,2*si+2);
	st[si]=max(constructutil(arr,ss,mid,st,2*si+1),contructutil(arr,mid+1,se,st,2*si+2));//for max 
	return st[si];	
}

int*construct(int arr[],int n)
{
	int h=(int)(ceil(log2(n)));
	int max_size=pow(2,h+1)-1;
	int *st=new int[max_size];
	constructutil(arr,0,n-1,st,0);
return st;
}

int main()
{
	int arr[]={4,8,31,5,321,9,54,531,97};
	int n=(sizeof arr)/(sizeof arr[0]);
	int *st=construct(arr,n);
	printf("sum=%d",getsum(st,0,n-1,3,4,0));
	updatevalue(arr,st,n,4,14);
	printf("\nsum=%d",getsum(st,0,n-1,3,4,0));
	return 0;
}

