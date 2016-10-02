#include<bits/stdc++.h>
using namespace std;

typedef pair<long int ,int>am;
queue<am>ank[4];
int main()
{
	am temp;
	temp.first=2;
	temp.second=4;
	ank[2].push(temp);
	am temp2;
//	ank[2].pop();
	temp2=ank[2].front();
	printf("%d",temp2.second);
	return 0;
	
}
