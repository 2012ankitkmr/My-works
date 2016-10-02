using namespace std;
#include<iostream>
#include<math.h>
#include<string.h>
int main()
{  long i,j,k,q,p;
static long a,b;
short d;
char e[127];

cin>>d;

for(i=0;i<d;i++){
	cin>>e;

	a=strlen(e)+1;
	b=pow(2,a-1);
	int arr[a][b];
p=3;
q=6;

	for(j=0;j<a;j++)
	{  if(j==0){
	arr[0][0]=1;
	} 
	else if(j==1)
	{
	arr[1][0]=2;
	arr[1][1]=4;
	}
	else{
	for(k=0;k<pow(2,j);k++)
	{ 
				
     if(j%2!=0){
	arr[j][k]=q;
	q=q+2;
    }
	if(j%2==0){
		arr[j][k]=p;
		p=p+2;
		}
	}
	}
}

cout<<arr[3][6];
	q=1;
	j=0;
	while(e[j]!='\0')
	{
		if(e[j]='r')
		q=(2*q);

		if(e[j]='l')
		q=(2*q)-1;
		j++;	}

	cout<<arr[a-1][q-1];

}

return 0;
}
