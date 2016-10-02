#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	char ch[10];
	fstream fin;
	fin.open("abc.txt",ios::in|ios::out);
	
	fin.seekp(2,ios::beg);
     int p=fin.tellp(); 
     cout<<p;
	  fin<<"hello";
	p=fin.tellp();
	cout<<p;
	fin.close();
}
