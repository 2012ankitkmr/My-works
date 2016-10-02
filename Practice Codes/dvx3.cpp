#include <stdio.h>
#include <string.h>

void swap(char x, char y)
{
char temp;
temp = x;
x = y;
y = temp;
}
void permute(char a[], int l, int r)
{
int i;
if (l == r)
printf("%s\n", a);
else
{
for (i = l; i <=r; i++)
{


char temp;
temp = a[l];
a[l] = a[i];
a[i] = temp;
permute(a, l+1, r);

temp = a[l];
a[l] = a[i];
a[i] = temp;

}

}
}
int main()
{
		freopen("in.txt","r",stdin);
char str[101];
int t,n;
scanf("%d",&t);
while(t--) {
scanf("%d",&n);
scanf("%s",str);
permute(str, 0, n-1);
}
return 0;
}
