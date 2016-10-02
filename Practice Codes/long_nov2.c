#include <iostream>
#include <string>

int main(){
    char string1[100000],string2[100000];
    long int i,length,k;
    int t,j;
    int flag = 0;
    for(j=0;j<t;j++){
      cin>>string1;
    
    length = strlen(string1);
    for(k=0;k<length;k++){
    string1.erase(k,1);
	  
    
    for(i=0;i < length ;i++){
        if(string1[i] != string1[length-i-1]){
            flag = 1;
            break;
	   }
	}
}
    if (flag)
        cout<<"YES\n";   
    else 
        cout<<"NO\n";

 }
        return 0;
}
