#include<stdio.h>

long int next_int()
{
       long  int n = 0;
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
	long int a,b,m,t,d,flag;
	for(t=next_int();t--;)
	{
		flag=0;
		a=next_int();
		b=next_int();
		m=next_int();
		
		
				d=b-a;
		if(d%m!=0)
		flag=1;
		d=d/m;
		if(flag)
		d++;
		printf("%ld\n",d);
	}
	
	return 0;
}
