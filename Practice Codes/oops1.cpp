#include<iostream>
using namespace std;

template<class T1,class T2>

class person
{ T1 m_t1;
	T2 m_t2;
	public:
		person(T1 t1,T2 t2){
	m_t1=t1;
	m_t2=t2;
	cout<<m_t1<<" "<<m_t2<<"\n";
	cout<<"1 here";
		}
	person(T2 t2,T1 t1)
	{
		m_t2=t2;
		m_t1=t1;
	cout<<m_t1<<" "<<m_t2<<"\n";	
	cout<<"2 here";
	}
	
};

int main()
{
	person<int,float>ob1(1,1.344);
	person<float,char>ob2(2.132,'r');
	return 0;
}

