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
{ int b;
	long int n,m,a[250005],l,r,x,i,d,y;
	short int c[250005];
	n=0;
	a[1]=0;
	for(m=next_int();m--;)
	{
		scanf("%d",&b);
		switch(b)
		{
			case 0: x=next_int();
			//scanf("%ld",&x);
			        a[++n]=x;
					c[x]++; 
			        break;
			case 1: l=next_int();
			        r=next_int();
			        x=next_int();
			        //scanf("%ld%ld%ld",&l,&r,&x);
						d=0;
			        	y=a[l];
			        	for(i=l;i<=r;i++)
			        	{
			        		if(d<(a[i]^x))
			        		{
			        		//printf("d=%ld,a[i]^x=%ld,y=%ld\n",d,a[i]^x,y);
			        			d=a[i]^x;
			        			y=a[i];
			        		}
			        	}
			        	printf("%ld\n",y);
			        	break;
			case 2: x=next_int();
			        //scanf("%ld",&x);
					n=n-x;
					while(x--)
					{
						c[a[n-x]]--;
					}
					
			        break;
			case 3: l=next_int();
			r=next_int();
			x=next_int();
			//scanf("%ld%ld%ld",&l,&r,&x);
			        d=0;
					for(i=l;i<=r;i++)
			        {
			        	if(a[i]<=x)
			        	d++;
			        }
			        printf("%ld\n",d);
					break;
			case 4: l=next_int();
			r=next_int();
			x=next_int();
//scanf("%ld%ld%ld",&l,&r,&x);			    
			    for(i=l;i<=r;i++)
			    {   if(c[a[i]]>0)
				    x--;
			    //	printf("c[i]=%d,a[i]=%d",c[a[i]],a[i]);
			    	if(!x)
			    	break;
			    }
				printf("%ld\n",a[i]);
					  break;       
	     }
	}
	return 0;
} 
