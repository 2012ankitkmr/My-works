#include<stdio.h>
int next_int()
{
    int n = 0;
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
	char s[1000005],a,b;
	long int p,q,r,sum,l,i,n;
	scanf("%s",s);
	for(q=next_int();q--;)
{
	scanf(" %c",&a);
	scanf(" %c",&b);
	l=next_int();
	r=next_int();
	 n=0;
	sum=0;
	for(i=l-1;i<r;i++)
	{
	
		if(s[i]==a)
		n++;
		if(s[i]==b)
		sum+=n;	
	}
	printf("%ld\n",sum);

}	
	
	return 0;
}
