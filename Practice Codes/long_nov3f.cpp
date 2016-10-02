#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;
int main()
{
	long int q,p,i,j,w,l,ri,r,b,y,s=1;
	char qu[3];
	long long g,h;
	ifstream fin;
	fin.open("abc.txt",ios::in);
	ofstream fout;
	fout.open("ans.txt",ios::out);
	fin>>q;
	cout<<fin.fail();
	for(i=0;i<q;i++)
	{
w=1;
for(j=0;j<w;j++)
	{
	fin>>qu;
	if(qu[1]=='i')
	{
	w++;
	s++;
	}
	else
	fin>>l>>ri;
}
		
r=0;
b=0;
j=1;
p=0;
g=l;
h=ri;
while(1){
h=h/2;
g=g/2;
if(g==1)
{p=j;
}
if(h==1)
break;
	
j++;
}
 
if(j%2==0)
b++;
else
r++;
 
if(p%2==0)
b++;
else
r++;
 y=1;
 for(g=0;g<p;g++)
 y=y*2;
 
j=y; 
while(1)
{
if(ri>=2*y)
{
ri=ri/2;
if(ri!=l)
{
if(j%2==0)
r++;
else
b++;
}
}
else
break;

if(l==ri)
break;	
}	
g=l;
y=0;
while(1)
	{
		ri=ri/2;
		l=l/2;	
		y++;
 
if(l==ri)
break;	
}
 
if(y!=1&&y%2==0)
{
	b=b+2*(y-1)/2;
	r=r+2*(y-1-(y-1)/2);
}
 else if(y!=1&&y%2!=0)
 {
r=r+2*(y-1)/2;
	b=b+2*(y-1-(y-1)/2);	
 }
 if(y%2==0&&p%2==0||(y%2!=0)&&p%2!=0)
b++;
else if(y%2!=0&&p%2==0||(y%2==0)&&p%2!=0) 
 r++;
if(h/2!=g)
{
if(j%2==0)
b++;
else if(j%2!=0)
r++;
} 
 
if(s%2==0)
{
p=b;
b=r;
r=p;
}
if(qu[1]=='r')
fout<<r<<"\n";
if(qu[1]=='b')
fout<<b<<"\n";	
	}
	fout.close();
	fin.close();
	return 0;
}
