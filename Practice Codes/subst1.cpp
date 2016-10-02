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
	int t,len;
for(scanf("%d",&t);t--;)
{
	scanf("%s",str);
	len=strlen(str);
	suffixsort(len);
	getheight(len);
	long long int ans=0;
	for(int i=0;i<len;i++)
	{
		ans+=(len-height[i]-suffixarray[i]);
		
	}
	printf("%lld\n",ans);
	
}	
	return 0;
}
