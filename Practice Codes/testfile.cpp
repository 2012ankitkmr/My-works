#include<iostream>
#include<fstream>
using namespace std;

/*long int next_int()
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
*/
int main()
{ int flag;
	long int t,n,j,k,i;
	double a[100003],b[100003];
	long long int ans; 
	double e;
	ifstream fin;
	ofstream fout;
	fout.open("abd.txt");
	fin.open("abc.txt");
	fin>>t;
   //scanf("%ld",&t);
   //t=next_int();	
	while(t--)
	{flag=0;
		fin>>n>>k;
		//scanf("%ld%ld",&n,&k);
		//n=next_int();
		//k=next_int();
		for(i=0;i<n;i++)
		fin>>a[i];
		//scanf("%lf",&a[i]);
		
		//a[i]=next_int();
		for(i=0;i<n;i++)
	    fin>>b[i];
		//scanf("%lf",&b[i]);
	      //b[i]=next_int();
		
		for(i=0;i<n;i++)
		a[i]=k/(long long int)a[i];
    
		ans=a[0]*b[0];
		for(i=0;i<n;i++)
		{
			if(a[i]*b[i]>ans)
			ans=a[i]*b[i];
		}
	//}
	fout<<ans<<"\n";
		//printf("%lld\n",ans);
		fin.close();
		
		fout.close();
	}
	return 0;
}
