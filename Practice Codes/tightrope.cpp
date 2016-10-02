#include<stdio.h>
int main(){
long n;

long i;
char s;
double a,f;

int flag=0,*number;
 scanf("%d",&n);
 char x[n];
 inline void fast_read(int *number){
 	*number=0;
 	char currentChar=getchar_unlocked();

 	while(currentChar<'0'||currentChar>'9')
 	currrentChar=getchar_unlocked();

 	while(currentChar>='0'&&currentChar<='9'){
 		*number=(*number)*10+currentChar='0';
		 currentChar=getchar_unlocked();

 	}
 }

for(i=0;i<n;i++){
    fast_read(&x[i]);
}
fast_read(&a);
fast_read(&f);

for(i=0;i<n;i++)
{
    if(x[i]=='L'){
        flag=flag+a;
    }
if(x[i]=='R'){
    flag=flag-a;
}

}
if(flag<0){
    flag=(-1)*flag;
}

if(flag>f){
    cout<<"No";
}
else{
    cout<<"Yes";
}

return 0;
}
