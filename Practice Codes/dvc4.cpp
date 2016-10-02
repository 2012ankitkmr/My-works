#include <stdio.h>
int array[100005];
int main()
{
  int n, c, d, t,cnt;
 
  scanf("%d", &n);
 
  for (c = 0; c < n; c++) {
    scanf("%d", &array[c]);
  }
 
  for (c = 1 ; c <= n - 1; c++) {
    d = c;
 
    while ( d > 0 && array[d] < array[d-1]) {
      t          = array[d];
      array[d]   = array[d-1];
      array[d-1] = t;
      cnt++;
 
      d--;
    }
  }
 printf("%d\n",cnt);
 
  return 0;
}
