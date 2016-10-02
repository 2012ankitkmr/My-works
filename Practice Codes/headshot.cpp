#include<stdio.h>
#include<stdlib.h>
#include<iostream> 
#include<string.h>
 using namespace std;
  int main(){ char arr[101]; int l,zero_one,zero_zero,TotalOnes,TotalZeroes; while(scanf("%s",arr)!=EOF){ l=strlen(arr); TotalZeroes=0; zero_one=0; zero_zero=0; for(int i=0;i<l;i++){ if(arr[i]=='0'){ TotalZeroes++; if(i!=l-1&&arr[i+1]=='1') zero_one++; if(i!=l-1&&arr[i+1]=='0') zero_zero++; } } if(arr[0]=='1'&&arr[l-1]=='0') zero_one++; if(arr[0]=='0'&&arr[l-1]=='0') zero_zero++; if((zero_one==zero_zero||TotalZeroes==l)) printf("EQUAL\n"); else if(zero_zero>zero_one) printf("SHOOT\n"); else if((zero_zero<zero_one)&&TotalZeroes!=l) printf("ROTATE\n"); } return 0; }
