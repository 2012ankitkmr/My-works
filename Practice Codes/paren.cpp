#include<bits/stdc++.h>
#include<stdio.h>
using  namespace std;
char s[10];
int ex[105];
int op[105];
long int T[105][105];
long int F[105][105];
long int paren(int n)
{
	memset(F,0,sizeof F);
	memset(T,0,sizeof T);
	
for(int i=0;i<n;i++)
{
	F[i][i]=ex[i]==0;
	T[i][i]=ex[i];
	//printf("i=%d,ex[i]=%d,F[i][i]=%d,T[i][i]=%d\n",i,ex[i],F[i][i],T[i][i]);
}
for(int  gap=1;gap<n;++gap)
{
	for(int i=0,j=gap;j<n;++i,++j)
	{
		T[i][j]=F[i][j]=0;
		for(int g=0;g<gap;g++)
		{
			int k=i+g;
			int tik=T[i][k]+F[i][k];
			int tkj=T[k+1][j]+F[k+1][j];
			
			if(op[k]==1)
			{
				T[i][j]+=T[i][k]*T[k+1][j];
				F[i][j]+=(tik*tkj-T[i][k]*T[k+1][j]);				
			}
			if(op[k]==2)
			{
				F[i][j]+=F[i][k]*F[k+1][j];
				T[i][j]+=(tik*tkj-F[i][k]*F[k+1][j]);
			}
			if(op[k]==3)
			{
				T[i][j]+=F[i][k]*T[k+1][j]+T[i][k]*F[k+1][j];
				F[i][j]+=T[i][k]*T[k+1][j]+F[i][k]*F[k+1][j];				
			}
		}
		
	}

}
return 	T[0][n-1];
}
//char p[5];
int main()
{
	freopen("in.txt","r",stdin);
	int i,t,x,flag=0;

	for(scanf("%d",&t);t--;)
	{
		x=0;

while(1)
{
	if(!flag)
	scanf(" %s",s);
    // printf("%s\n",p);
	ex[x]=s[0]=='T'?1:0;
	
	
scanf(" %s",s);
//printf("%s",s);	
if(s[0]=='T'||s[0]=='F')
{
flag=1;
break;
}
if(s[0]=='a')
op[x]=1;
if(s[0]=='o')
op[x]=2;
if(s[0]=='x')
op[x]=3;

x++;
flag=0;
//printf("here\n");
}
//printf("x=%d\n",x);
long int count=paren(x+1);
printf("%ld\n",count);
		
	}
	return 0;
}
