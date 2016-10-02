#include<iostream>
using namespace std;

class ABC
{
    int a;
int b;

public:
ABC(int c, int d)
{a=c;
b=d;
}
void display(){
cout<<"a= "<<a<<endl;
cout<<"b= "<<b<<endl;
}

bool operator==(ABC);
bool operator&&(ABC);

};
bool ABC::operator==(ABC N){
return a==N.a&&b==N.b;
}
bool ABC::operator&&(ABC M){
return a&&M.a&&b&&M.b;
}

int main(){
ABC obj1(3,6);
ABC obj2(3,6);
bool x,y;

x=(obj1==obj2);
y=(obj1&&obj2);
cout<<"x is"<<x<<"\ny is "<<y<<endl;
obj1.display();
obj2.display();
}
