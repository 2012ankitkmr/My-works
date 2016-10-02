#include<bits/stdc++.h>
using namespace std;

namespace ankit{

void show(float n)
{
	printf("%f\n",n);
}
}
//using namespace ankit;
int main()
{
    float x,y;
	scanf("%f%f",&x,&y);
	if((int)x%5==0)
	{
		if(x+0.5<=y)
		y=y-x-0.5;	
	}
	ankit::show(y);
	return  0;
}
