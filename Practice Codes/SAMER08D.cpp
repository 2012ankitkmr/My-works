#include<stdio.h>
#include<string.h>
char s1[1005],s2[1005];
int sequence[1005][1005],segment[1005][1005];
int max(int a,int b)
{
	return a>b?a:b;
}
int lcs(int a,int b,int k)
{
	int i,j,l;
	segment[0][0] = 0;
        for(int i = 0; i < 1005; ++i)
		 sequence[i][0] = sequence[0][i] = 0;
      
	for(i=1;i<=a;++i)
	{
		for(j=1;j<=b;++j)
		{
			sequence[i][j]=max(sequence[i-1][j],sequence[i][j-1]);
		
			if(s1[i-1]==s2[j-1])
				segment[i][j]=1+segment[i-1][j-1];
				else
				segment[i][j]=0;	
				
		   if(segment[i][j]>= k)
                for(l= k;l<= segment[i][j]; l++)
                    sequence[i][j] = max(sequence[i][j],sequence[i-l][j-l]+l);
				
		}
		
	}
	return sequence[a][b];
	
}

int main()
{
	int k,ans,len1,len2;
	
	while(1){
		scanf("%d",&k);
		
		if(k==0)
		break;
		scanf("%s",s1);
		scanf("%s",s2);
		len1=strlen(s1);
		len2=strlen(s2);
		ans=lcs(len1,len2,k);
		printf("%d\n",ans);
	}
	return 0;
}
