#include<bits/stdc++.h>
using namespace std;
int Off = 20;

int findactualposition(char s[])
{
	int k = 0;
	for(int i = 0;s[i];i++)
	{
		if(s[i]=='+')
		k++;
		else
		k--;
	}
	return k;	
}
int location[44];
void updateprevpointer(int k)
{
	if(k==0)
	return;
	int loc[44];
		for(int i = -20;i<=20;i++)
		loc [i+Off] = 0;

	for(int i = -10; i<=10 ; i++ )
	{
		loc[i+k+Off] = location[i+Off];
	}
	
	for(int i = -10; i<=10 ; i++ )
	{
		location[i+Off] = loc[i+Off];
	}
}

void multiplypossibility()
{
		int loc[44];
		for(int i = -20;i<=20;i++)
		loc [i+Off] = 0;

	for(int i = -10; i<=10 ; i++ )
	{
		if(location[i+Off])
		{
		loc[i-1+Off] += location[i+Off];
		loc[i+1+Off] += location[i+Off];
	 	}
	}
	for(int i = -10; i<=10 ; i++ )
	{
		location[i+Off] = loc[i+Off];
	}
	
}

int main()
{
	char drazil[20],dora[20];

	int pos;
	scanf(" %s",drazil);
	scanf(" %s",dora);
		for(int i = -10;i<=10;i++)
		location [i+Off] = 0;
	int k = 0,numq = 0;

	pos = findactualposition(drazil);
	location[0+Off] = 1;
//		for(int i = -10;i<=10;i++)
//			printf("%2d ",location[i]);
//			printf("\n");
	for(int i = 0 ; dora[i] ; i++ )
	{
		if(dora[i]=='+')
		k++;
		else if(dora[i]=='-')
		k--;
		else 
		{
			updateprevpointer(k);
			k = 0;
			numq++;
			multiplypossibility();
		
		}
		
	}
		updateprevpointer(k);
	
	
	printf("%.9lf\n",location[pos+Off]/(double)(1<<numq));
	return  0;
}
