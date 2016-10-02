#include<stdio.h>
long int next_int()
{
       long int n = 0;
        char c = getchar_unlocked();
        while (!('0' <= c && c <= '9'))
        {
                c = getchar_unlocked(); 
        }
        while ('0' <= c && c <= '9')
        {
                n = (n<<3)+(n<<1) + c - '0';
                c = getchar_unlocked();
        }
        return n;
}

int main()
{
	long int t,i,n,ans,count;
	int x,y,k,p[100005],c[100005],flag;
	for(t=next_int();t--;)
	{
		x=next_int();
		y=next_int();
		k=next_int();
		n=next_int();
		for(i=0;i<n;i++)
		{
			p[i]=next_int();
			c[i]=next_int();
		}
		count=x-y;
		flag=0;
		for(i=0;i<n;i++)
		{
			if(p[i]>=count)
			{
				if(c[i]<=k)
				flag=1;
			}
		}
		
		if(flag==1)
		printf("LuckyChef\n");
		else
		printf("UnluckyChef\n");
	}
	return 0;
}
