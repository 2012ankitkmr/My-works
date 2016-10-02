#include <iostream>

#include <algorithm>

#include <iomanip>

#include <list>

#include <cstdio>

#include <vector>

#include <cstdlib>
#include <string.h>

#include <math.h>

#include <ctype.h>

#include <limits.h>

#include <stdbool.h>
#include <map>
#include <utility>
 

/* I N P U T    A N D     O U T P U T  */



#define si(a) scanf("%d",&a)

#define sli(a) scanf("%ld",&a)

#define slli(a) scanf("%lld",&a)

#define sf(a) scanf("%f",&a)

#define sd(a) scanf("%lf",&a)

#define ss(a) scanf("%s",a)

#define NL printf("\n")

#define pi(a) printf("%d",a)

#define pli(a) printf("%ld",a)

#define plli(a) printf("%lld",a)

 

/*  L O O P S  */

 
#define TEST while(t--)

#define fi(a,b) for(i=a;i<b;i++)

#define fj(a,b) for(j=a;j<b;j++)

#define fk(a,b) for(k=a;k<b;k++)
#define fx(a,b) for(x=a;x<b;x++)

/*  O T H E R   */


#define MAX(a,b) ((a>b)?a:b)

#define SQUARE(a) (a*a)
#define MIN(a,b) ((a<b)?a:b)

#define pb(a) push_back(a)

#define pf(a) push_front(a)



/*  HERE GOES THE CODE   */

using namespace std;

typedef long int ll;
typedef vector<ll> vi;
 

int main()

{
	ll m,st,l,r,x,k,i,j,maxor,max,cnt=0;
	sli(m);

vi v;

	ll sta[100005]={0};

	while(m--)

	{
		sli(st);
	switch(st)

	{
			case 0:
			sli(x);
				v.pb(x);
			sta[x-1]++;
			break;

case 1:
				sli(l);sli(r);sli(x);
			maxor=LONG_MIN;
				for(i=l-1;i<=r-1;i++)
				{
					if((v[i]^x)>maxor)
					{
						maxor=(v[i]^x);
						max=v[i];	
					}	
				}
				pli(max);NL;
				break;
			case 2:
				sli(k);
				while(k)
			{
					sta[v.size()-1]--;
					v.pop_back();
					k--;	
				}
			break;
			case 3:
			sli(l);sli(r);sli(x);
				cnt=0;
				fi(l-1,r)

			if(v[i]<=x)

						cnt++;
			pli(cnt);NL;
				break;
			case 4:	
			sli(l);sli(r);sli(k);
			fi(l-1,r)

			{

				if(sta[v[i]-1]>0)

					k--;
		if(!k)
					break;	

			}
				pli(v[i]);NL;

				break;

		}	

	}

return 0;

}



