#include<bits/stdc++.h>
#include<map>
#include<string>
using namespace std;

long long int merge(long int arr[],long int temp[],long int low,long int mid,long int high)
{
	long int i,j,k;
	i=low;
	j=mid;
	k=low;
	long long int cnt=0;
	while((i<=mid-1)&&(j<=high))
	{
	if(arr[i]<=arr[j])
	temp[k++]=arr[i++];
	else
	{
		temp[k++]=arr[j++];
		cnt+=(mid-i);
	}
	}
while(i<=mid-1)
	temp[k++]=arr[i++];
	while(j<=high)
	temp[k++]=arr[j++];
for(i=low;i<=high;i++)
arr[i]=temp[i];
return cnt;	
}

long long int mergesort(long int arr[],long int temp[],long int low,long int high)
{
	long long int cnt=0;
	if(low<high)
	{
		int mid=(low+high)/2;
		cnt+=mergesort(arr,temp,low,mid);
		cnt+=mergesort(arr,temp,mid+1,high);
		cnt+=merge(arr,temp,low,mid+1,high);
	}
	return cnt;
}
struct tstnode{
	char data;
	int end_of_string;
	struct tstnode*left;
	struct tstnode*right;
	struct tstnode*eq;
};
struct tstnode*insert(struct tstnode*root,char*word,int data)
{

	if(root==NULL)
	{
		root=(struct tstnode*)malloc(sizeof(struct tstnode));
		root->data=*word;
		root->end_of_string=1;
		root->left=root->eq=root->right=NULL;
	}
	if(*word<root->data)
{//printf("l%c",*word);
	root->left=insert(root->left,word,data);
}
	else if(*word>root->data)
{//printf("r%c",*word);
	root->right=insert(root->right,word,data);
}
	else if(*word==root->data)
	{	
		if(*(word+1))
		root->eq=insert(root->eq,(word+1),data);
		else
		{
		root->end_of_string=data;
	}
	}
	return root;
}

int search(struct tstnode*root,char*word)
{
	if(root==NULL)
return 0;
	// printf("%c",root->data);
	if(*word<root->data)
	return search(root->left,word);
	else if(*word>root->data)
	return search(root->right,word);
	else{
	    if(root->end_of_string!=0&&*(word+1)=='\0')
	    {
   
		return root->end_of_string;
	}
		else
		return search(root->eq,(word+1));
	}
	
}

int main()
{
	int t;
	long int i,n,arr[30000];
char s[45];	
	for(scanf("%d",&t);t--;)
	{
	scanf("%ld",&n);
struct tstnode*root=(struct tstnode*)malloc(sizeof(struct tstnode));
//map<string,int>mymap
//root->end_of_string=0;
	for(i=0;i<n;i++)
	{
		scanf("%s",s);
		struct tstnode*temp1=insert(root,s,i+1);	
	}
	for(i=0;i<n;i++)
	{
		scanf("%s",s);
	
arr[i]=search(root,s);	
	//	word=s;
	//	arr[i]=mymap[word];
	}	
	long int temp[30000];
	
	for(i=0;i<n;i++)
	printf("%ld\n",arr[i]);
	printf("%ld\n",mergesort(arr,temp,0,n-1));
	
	}
	return 0;
}

