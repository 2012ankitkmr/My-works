#include<iostream>
#include<fstream>
using namespae std;
int main()
{
	fstream f;
	f.open("vasu",ios::in);
	f>>4;
	cout<<f.fail()<<"\n";
	cout<<f.bad();
}
