#include<iostream>
using namespace std;
class A
{
	int a;
	public:
		A()
		{
		}
		void display()
{	
cout<<"a"<<"\n";
}	
};

class B:virtual public A
{
	
	int b;
	public:
		B()
		{
		}
		/*void display()
{	
cout<<"b"<<"\n";
}	*/
};

class C:virtual public A
{
	
	int c;
	public:
		C()
		{
		}
/*		void display()
{	
cout<<"c"<<"\n";
}	*/
};

class D:public B,public C 
{
	
	int d;
	public:
	/*void display()
{	
cout<<"d"<<"\n";
}	*/
};

int main()
{
	D d;
	d.display();
	
	return 0;
}



