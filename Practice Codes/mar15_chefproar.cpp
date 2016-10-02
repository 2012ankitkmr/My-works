#include<stdio.h>
#include<string.h>
	char s[200005];
	long int count,count1;
unsigned X; // we assume that unsigned is a 32bit integer type
 
void srand1(unsigned S){
  X = S;
}
 
unsigned nextInteger1(void){
  X = X * 1103515245 + 12345;
  return (X / 65536) % 32768;
}
 
void generator1(int N, unsigned S){
  srand1(S);
  //if(S==0||S==1||S==2)
  //printf("\n");
  for(int i=1;i<=N;i++){
 {  //if(S==0||S==1||S==2)
 	//printf("%lu ",nextInteger1());
   if( (nextInteger1() % 2)!=s[i-1]-'0')
    {count--;
break;
}
}
  }
}
unsigned x, y, z, w; // we assume that unsigned is a 32bit integer type
 
void srand2(unsigned S){
  x = S;
  y = x * S;
  z = y * S;
  w = z * S;
}
 
unsigned nextInteger2(void){
  unsigned t = x ^ (x << 11);
  x = y; y = z; z = w;
  return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)); 
}
 
void generator2(int N, unsigned S){
  srand2(S);
  for(int i=1;i<=N;i++){
  if( (nextInteger2() % 2)!=s[i-1]-'0')
    {count1--;
break;
}
      
  }
}
 
 
int main()
{
	int t;
	long long int i,len,flag,j; 
 
	for(scanf("%d",&t);t--;)
{
scanf("%s",s);
len=strlen(s);
count=len;		
flag=0;
 i=10000000;
while(1)
{
	count=len;
	count1=len;
	generator1(len,i);

generator2(len,i);

i--;
if(count==len)
{
flag=1;
break;
}
if(count1==len)
{
flag=2;
break;
}
}		
if(flag==1)	
printf("LCG\n");
else if(flag==2)
printf("Xorshift\n");		
}
	return 0;
} 
