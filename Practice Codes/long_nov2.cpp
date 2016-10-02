#include<stdio.h>
#include<string.h>
int main(){
    char string1[100000],string2[100000];
    long unsigned int i,length,k,flag,z;
    int t,j;
    int f;
    scanf("%d",&t);
    for(j=0;j<t;j++){
    	f=0;
i=0;length=0;
      scanf("%s",string1);
      
      length=strlen(string1);
		
	for(k=0;k<length;k++){
    z=0;
    for(i=0;i<length;i++){
    	if(i!=k)
    {
    	string2[z]=string1[i];
    z++;
	}
	}
	    flag=0;
	    
    for(i=0;i<(length-1)/2;i++){
        if(string2[i]==string2[length-i-2]){
            flag++;
     }
      else 
      break;
	}
if(flag==(length-1)/2)
{
f=1;
break;
}
}
    if (f)
        printf("YES\n");   
    else 
        printf("NO\n");

 }
        return 0;
} 
