using namespace std;
#include<iostream>
#include<math.h>
#include<string.h>
int main()
{  long i,j,k,q=1,p=2;
static long a,b;
short d;
unsigned char e[255];

cin>>d;

for(i=0;i<d;i++){
	cin>>e;

	a=strlen(e)+1;
	b=pow(2,strlen(e));
	int arr[a][b];

	for(j=0;j<=a;j++)
	{
		for(k=0;k<=pow(2,j);j++)
		{

		if(j%2!=0){
	arr[j][k]=p;
	p=p+2;
}
	else{
		arr[j][k]=q;
		q=q+2;}
	}
	}

	q=1;

	for(j=0;j<a;i++)
	{
		if(e[j]=='r')
		q=2*q;

		if(e[j]=='l')
		q=2*q-1;
			}

	cout<<arr[a-1][q];

}

return 0;
}
