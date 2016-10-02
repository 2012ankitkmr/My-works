#include<bits/stdc++.h>
using namespace std;
#define MAX 50002
char str[MAX];
long int suffixarray[MAX];
long int length_of_str;
long int bh[MAX],b2h[MAX],cnt[MAX],height[MAX],next[MAX],rank[MAX];
bool smaller_first_char(long int a,long int b)
{
	return str[a]<str[b];
}

void suffixsort(long int n)
{
	for(int i=0;i<n;++i)
{
	suffixarray[i]=i;
}
sort(suffixarray,suffixarray+n,smaller_first_char);
for(int i=0;i<n;++i)
{
	bh[i]=i==0||str[suffixarray[i]]!=str[suffixarray[i-1]];
	b2h[i]=false;
}	
for(int h=1;h<n;h<<=1)
{
	int buckets=0;
	for(int i=0,j;i<n;i=j)
	{
		j=i+1;
		while(j<n&&!bh[j])j++;
		next[i]=j;
		buckets++;
	}
	if(buckets==n)break;
	
	for(int i=0;i<n;i=next[i])
	{
		cnt[i]=0;
		for(int j=i;j<next[i];++j)
		{
			rank[suffixarray[j]]=i;
		}
		
	}
	cnt[rank[n-h]]++;
	b2h[rank[n-h]]=true;
	for(int i=0;i<n;i=next[i])
	{
	for(int j=i;j<next[i];++j)
	{
		int s=suffixarray[j]-h;
		if(s>=0)
		{
			int head=rank[s];
			rank[s]=head+cnt[head]++;
			b2h[rank[s]]=true;
		}
	}
	for(int j=i;j<next[i];++j)
	{
		int s=suffixarray[j]-h;
		if(s>=0&&b2h[rank[s]])
		{
			for(int k=rank[s]+1;!bh[k]&&b2h[k];k++)
			b2h[k]=false;
		}
	}	
	}
	for(int i=0;i<n;++i)
	{
		suffixarray[rank[i]]=i;
		bh[i]|=b2h[i];
	}
}
for(int i=0;i<n;++i)
{
	rank[suffixarray[i]]=i;
}
}

void getheight(int n)
{
	for (int i=0; i<n; ++i) rank[suffixarray[i]] = i;
	height[0] = 0;
	for (int i=0, h=0; i<n; ++i)
	{
		if (rank[i] > 0)
		{
			int j = suffixarray[rank[i]-1];
			while (i + h < n && j + h < n && str[i+h] == str[j+h])
			{
				h++;
			}
			height[rank[i]] = h;
			if (h > 0) h--;
		}
	}
}

int main()
{
int len,t,x,y;

while(1)
{
gets(str);
len=strlen(str);
length_of_str=len;
suffixsort(len);
printf("The Suffix is: \n");
for(int i=0;i<(len);i++)
printf("%d %s\n",suffixarray[i],(str+suffixarray[i]));	
	return 0;
}
	return 0;
}
