#include<bits/stdc++.h>
using namespace std;
#define MAX 50002
char str[MAX];
long int suffixarray[MAX];
long int length_of_str;
long int cnt[MAX],heigh[MAX],nex[MAX],ran[MAX];
bool bh[MAX],bha[MAX];
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
	bh[i]=(i==0||str[suffixarray[i]]!=str[suffixarray[i-1]]);
	bha[i]=false;
}	
for(int h=1;h<n;h<<=1)
{
	int buckets=0;
	for(int i=0,j;i<n;i=j)
	{
		j=i+1;
		while(j<n&&!bh[j])j++;
		nex[i]=j;
		buckets++;
	}
	if(buckets==n)break;
	
	for(int i=0;i<n;i=nex[i])
	{
		cnt[i]=0;
		for(int j=i;j<nex[i];++j)
		{
			ran[suffixarray[j]]=i;
		}
		
	}
	cnt[ran[n-h]]++;
	bha[ran[n-h]]=true;
	for(int i=0;i<n;i=nex[i])
	{
	for(int j=i;j<nex[i];++j)
	{
		int s=suffixarray[j]-h;
		if(s>=0)
		{
			int head=ran[s];
			ran[s]=head+cnt[head]++;
			bha[ran[s]]=true;
		}
	}
	for(int j=i;j<nex[i];++j)
	{
		int s=suffixarray[j]-h;
		if(s>=0&&bha[ran[s]])
		{
			for(int k=ran[s]+1;!bh[k]&&bha[k];k++)
			bha[k]=false;
		}
	}	
	}
	for(int i=0;i<n;++i)
	{
		suffixarray[ran[i]]=i;
		bh[i]|=bha[i];
	}
}
for(int i=0;i<n;++i)
{
	ran[suffixarray[i]]=i;
}
}

void getheigh(int n)
{
	for (int i=0; i<n; ++i) ran[suffixarray[i]] = i;
	heigh[0] = 0;
	for (int i=0, h=0; i<n; ++i)
	{
		if (ran[i] > 0)
		{
			int j = suffixarray[ran[i]-1];
			while (i + h < n && j + h < n && str[i+h] == str[j+h])
			{
				h++;
			}
			heigh[ran[i]] = h;
			if (h > 0) h--;
		}
	}
}

int main()
{
	int t,len;
		long long int ans;
for(scanf("%d",&t);t--;)
{
	scanf("%s",str);
	len=strlen(str);
	suffixsort(len);
	getheigh(len);
	ans=0;
	for(int i=0;i<len;i++)
	{
		ans+=(len-heigh[i]-suffixarray[i]);
		
	}
	printf("%lld\n",ans);
	
}	
	return 0;
}
