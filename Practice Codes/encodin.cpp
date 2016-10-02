#include<bits/stdc++.h>
using namespace std;
int main()
{
    char str[10000];
    while(gets(str))
    {
        char encoding[20000];
        int k=0,prev_count=0,count=0,i,len;
        char ch;
        len=strlen(str);
        for(i=0;i<len;i++)
        {
            prev_count=count;
            count=1;
            if(str[i]==str[i+1]&&(i+1)<len)
            {
                count=2;
                ch=str[i];
                i=i+2;
                while(str[i]==ch)
                {
                    i=i+1;
                    count=count+1;
                    if(count==9)
                    break;
                }
                i=i-1;
            }
            if(count!=1)
            {
                encoding[k]=count+'0';
                k=k+1;
                encoding[k]=str[i];
                k=k+1;
            }
            else if(count==1)
            {
                if(count!=prev_count){
                    if(str[i]!='1')
                    {
                    encoding[k]='1';
                    k=k+1;
                    encoding[k]=str[i];
                    k=k+1;
                    encoding[k]='1';
                    k=k+1;
                    }
                    else if(str[i]=='1')
                    {
                    encoding[k]='1';
                    k=k+1;
                    encoding[k]='1';
                    k=k+1;
                    encoding[k]='1';
                    k=k+1;
                    encoding[k]='1';
                    k=k+1;
                    }
                }
                else
                {
                    if(str[i]!='1')
                    {
                        k=k-1;
                        encoding[k]=str[i];
                        k=k+1;
                        encoding[k]='1';
                        k=k+1;
                    }
                    else if(str[i]=='1')
                    {
                        encoding[k]='1';
                        k=k+1;
                        encoding[k]='1';
                        k=k+1;
 
                    }
                }
            }
        }
        for(i=0;i<k;i++)
            printf("%c",encoding[i]);
        printf("\n");
    }
    return 0;
}
