#include<bits/stdc++.h>
using namespace std;

struct choice{
	int length;
	int index;
};

choice len[5];
bool comp(const choice x,const choice y)
{
	return x.length<y.length;
}
int main()
{
//	freopen("in.txt","r",stdin);
	char s[5][120];
	
	char ans='C';
	for(int i=0;i<4;i++)
	scanf(" %s",s[i]);
	
	for(int i=0;i<4;i++)
	{
		len[i].length=strlen(s[i])-2;
		len[i].index=i;
		printf("%d\n",len[i].length);
	}
	sort(len,len+4,comp);

	if(2*len[0].length<=len[1].length)
	ans = 'A' + len[0].index;
	else if(len[3].length>=2*len[2].length)
	ans = 'A' + len[3].index;
	
	printf("%c",ans);
	return  0;
}
